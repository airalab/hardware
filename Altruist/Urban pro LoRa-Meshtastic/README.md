# Meshtastic IoT Bridge: Altruist Urban + Heltec + Raspberry Pi

**English** | **[Русский](README.ru.md)**

A testbed for transmitting air quality sensor data from **Altruist Urban** (ESP32-C6) through **Heltec HTIT-WB32LA V4** via LoRa/Meshtastic to a **Raspberry Pi 4B + MeshAdv-Pi-Hat (E22-900M30S)** gateway node.

**🇷🇺 Русский** | **[Русская версия](README.ru.md)** — Полная документация на русском языке  
**🇬🇧 English** | **[English version](README.en.md)** — Full documentation in English

---

## Quick Start

Choose your language:

| Language | File | Description |
|----------|------|-------------|
| 🇷🇺 Русский | [README.ru.md](README.ru.md) | Полная документация на русском |
| 🇬🇧 English | [README.en.md](README.en.md) | Full English documentation |

---

## Repository Structure

```
meshtastic-altruist-bridge/
├── README.md                  # This file (language selector)
├── README.ru.md              # 🇷🇺 Russian documentation
├── README.en.md              # 🇬🇧 English documentation
├── images/
│   └── altruist-heltec-wiring.jpg  # Wiring diagram photo
├── docs/
│   ├── HARDWARE.md           # Hardware specifications
│   └── SOFTWARE.md           # Software setup guide
├── scripts/
│   └── journal_to_mqtt.py   # Python bridge (journalctl → MQTT)
└── config/
    ├── meshtasticd.yaml     # LoRa module configuration
    ├── mosquitto.conf       # MQTT broker configuration
    └── mesh-mqtt-bridge.service  # Systemd service file
```

---

## System Overview

```
[Altruist Urban] --UART--> [Heltec V4] --LoRa/Meshtastic--> [Raspberry Pi 4B + E22-900M30S] --MQTT--> [Home Assistant/Cloud]
      (Remote)                  (Field Node)                     (Gateway Node)
```

| Component | Model | Role |
|-----------|-------|------|
| Sensor | Altruist Urban (ESP32-C6) | Air quality data source |
| LoRa Board | Heltec HTIT-WB32LA V4 | Field node transmitter |
| Gateway | Raspberry Pi 4B + MeshAdv-Pi-Hat | MQTT bridge to internet |

---

## Key Features

- ✅ Direct LoRa communication between nodes
- ✅ UART bridge from sensor to Meshtastic network
- ✅ MQTT integration for IoT platforms
- ✅ JSON data format for easy parsing
- ✅ Systemd service for automatic startup
- ✅ Multi-language documentation

---

## License

MIT / Public Domain. Open Source project based on Meshtastic (GPL).
