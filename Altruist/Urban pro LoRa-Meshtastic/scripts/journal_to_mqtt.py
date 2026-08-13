#!/usr/bin/env python3
"""
Meshtastic (journalctl) -> MQTT Bridge

Слушает логи meshtasticd через journalctl, парсит текстовые сообщения
от указанной ноды и публикует их в MQTT в формате JSON.

Настройки:
  MQTT_BROKER    - адрес MQTT брокера (default: localhost)
  MQTT_PORT      - порт MQTT (default: 1883)
  MQTT_USER      - логин для MQTT
  MQTT_PASS      - пароль для MQTT
  TARGET_NODE    - ID ноды-источника (default: 0xb29f9cfc)
  MQTT_ROOT      - корневой топик (default: altruist)

Топики:
  {MQTT_ROOT}/{node_id}/text    - текстовые сообщения
  {MQTT_ROOT}/{node_id}/raw     - сырые данные (hex)

Payload JSON:
  {
    "source": "0xb29f9cfc",
    "msg_id": "0x4d1099c6",
    "text": "данные от датчика...",
    "timestamp": 1785828186,
    "received_at": "2026-08-04T11:23:06"
  }

Запуск:
  python3 journal_to_mqtt.py

Systemd:
  sudo cp mesh-mqtt-bridge.service /etc/systemd/system/
  sudo systemctl enable --now mesh-mqtt-bridge
"""

import paho.mqtt.client as mqtt
import json
import re
import subprocess
import time
import signal
import sys

# === НАСТРОЙКИ ===
MQTT_BROKER = "localhost"
MQTT_PORT = 1883
MQTT_USER = "mesh"
MQTT_PASS = "mesh123"
MQTT_ROOT = "altruist"
TARGET_NODE = "0xb29f9cfc"
# === КОНЕЦ НАСТРОЕК ===

mqtt_client = None
running = True

def signal_handler(sig, frame):
    global running
    print("[BRIDGE] Stopping...")
    running = False
    if mqtt_client:
        mqtt_client.disconnect()
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)
signal.signal(signal.SIGTERM, signal_handler)

def on_connect(client, userdata, flags, rc, properties=None):
    if rc == 0:
        print("[MQTT] Connected to %s:%d" % (MQTT_BROKER, MQTT_PORT))
    else:
        print("[MQTT] Connection error: %d" % rc)

def on_disconnect(client, userdata, rc, properties=None):
    print("[MQTT] Disconnected (rc=%d)" % rc)

def parse_log_line(line):
    """
    Парсит строку лога meshtasticd вида:
    INFO  | ... [Router] Received text msg from=0xb29f9cfc, id=0x..., msg=...
    """
    match = re.search(
        r'Received text msg from=' + re.escape(TARGET_NODE) + r',\s*id=([0-9a-fx]+),\s*msg=(.+)',
        line
    )
    if match:
        return {
            "source": TARGET_NODE,
            "msg_id": match.group(1),
            "text": match.group(2).strip(),
            "timestamp": int(time.time()),
            "received_at": time.strftime('%Y-%m-%dT%H:%M:%S')
        }
    return None

def main():
    global mqtt_client
    print("=" * 60)
    print("Meshtastic (journalctl) -> MQTT Bridge")
    print("MQTT broker: %s:%d" % (MQTT_BROKER, MQTT_PORT))
    print("Target node: %s" % TARGET_NODE)
    print("MQTT root:   %s" % MQTT_ROOT)
    print("=" * 60)
    
    # Создаём MQTT клиент (совместимость с paho-mqtt v1 и v2)
    try:
        mqtt_client = mqtt.Client(
            callback_api_version=mqtt.CallbackAPIVersion.VERSION1
        )
    except (AttributeError, TypeError):
        mqtt_client = mqtt.Client()
    
    mqtt_client.username_pw_set(MQTT_USER, MQTT_PASS)
    mqtt_client.on_connect = on_connect
    mqtt_client.on_disconnect = on_disconnect
    
    try:
        mqtt_client.connect(MQTT_BROKER, MQTT_PORT, 60)
        mqtt_client.loop_start()
        time.sleep(1)
    except Exception as e:
        print("[ERROR] Failed to connect to MQTT: %s" % e)
        sys.exit(1)
    
    print("[BRIDGE] Starting journalctl listener...")
    print("[BRIDGE] Waiting for packets from %s..." % TARGET_NODE)
    print("[BRIDGE] Press Ctrl+C to stop\n")
    
    # Запускаем journalctl -f
    proc = subprocess.Popen(
        ["sudo", "journalctl", "-u", "meshtasticd", "-f", "-n", "0"],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    
    packet_count = 0
    
    try:
        for line in proc.stdout:
            if not running:
                break
            
            line = line.strip()
            if not line:
                continue
            
            data = parse_log_line(line)
            if data:
                packet_count += 1
                node_id = data["source"].lstrip("0x")
                topic = "%s/%s/text" % (MQTT_ROOT, node_id)
                payload = json.dumps(data, ensure_ascii=False)
                
                # Публикуем в MQTT
                result = mqtt_client.publish(topic, payload, qos=0)
                
                # Лог в консоль
                text_preview = data['text'][:60]
                if len(data['text']) > 60:
                    text_preview += "..."
                print("[MQTT #%d] %s: %s" % (packet_count, topic, text_preview))
                
    except KeyboardInterrupt:
        pass
    except Exception as e:
        print("[ERROR] Bridge error: %s" % e)
    finally:
        print("\n[BRIDGE] Cleaning up...")
        proc.terminate()
        try:
            proc.wait(timeout=2)
        except:
            proc.kill()
        
        mqtt_client.loop_stop()
        mqtt_client.disconnect()
        print("[BRIDGE] Done. Total packets: %d" % packet_count)

if __name__ == "__main__":
    main()
