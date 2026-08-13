# Software Setup Guide

## 1. Raspberry Pi 4B — Gateway Node

### Базовая установка Ubuntu 24.04

```bash
# Обновление системы
sudo apt update && sudo apt upgrade -y

# Установка зависимостей
sudo apt install -y python3 python3-pip python3-venv git curl wget

# Создание виртуального окружения для meshtastic
python3 -m venv ~/mesh-venv
source ~/mesh-venv/bin/activate
pip install meshtastic
```

### Установка meshtasticd

```bash
# Добавляем официальный PPA
sudo add-apt-repository ppa:meshtastic/beta
sudo apt update
sudo apt install -y meshtasticd
```

### Конфигурация LoRa-модуля

**Файл: `/etc/meshtasticd/config.yaml`**

```yaml
# MeshAdv-Pi E22-900M30S
# https://github.com/chrismyers2000/MeshAdv-Pi-Hat

Lora:
  Module: sx1262
  CS: 21
  IRQ: 16
  Busy: 20
  Reset: 18
  TXen: 13
  RXen: 12
  DIO3_TCXO_VOLTAGE: true

Webserver:
  Port: 80
```

### Настройка прав и запуск

```bash
# Владелец данных
sudo chown -R meshtasticd:meshtasticd /var/lib/meshtasticd/
sudo chmod 750 /var/lib/meshtasticd/

# Доступ к SPI и GPIO
sudo usermod -aG spi,gpio meshtasticd

# Запуск службы
sudo systemctl enable meshtasticd
sudo systemctl start meshtasticd

# Проверка
sudo systemctl status meshtasticd
sudo journalctl -u meshtasticd -f
```

### Настройка региона и параметров

```bash
# Устанавливаем регион EU_868
source ~/mesh-venv/bin/activate
meshtastic --host localhost --set lora.region EU_868

# Проверка частоты
meshtastic --host localhost --info
```

### Установка Mosquitto MQTT Broker

```bash
sudo apt install -y mosquitto mosquitto-clients

# Создаём пользователя
sudo touch /etc/mosquitto/passwd
sudo mosquitto_passwd -b /etc/mosquitto/passwd mesh mesh123
sudo chown mosquitto:mosquitto /etc/mosquitto/passwd
sudo chmod 640 /etc/mosquitto/passwd

# Внешний listener
sudo tee /etc/mosquitto/conf.d/10-ext.conf << 'EOF'
listener 1883 0.0.0.0
allow_anonymous false
password_file /etc/mosquitto/passwd
EOF

sudo systemctl restart mosquitto
sudo systemctl enable mosquitto
```

---

## 2. Heltec HTIT-WB32LA V4 — Field Node

### Подключение к Pi через USB

```bash
# Определяем порт
lsusb | grep Espressif
# Должно быть: ID 303a:1001 Espressif USB JTAG/serial debug unit

# Права на порт
sudo usermod -aG dialout $USER
sudo chmod 666 /dev/ttyACM0
```

### Настройка Serial Module для Altruist Urban

```bash
source ~/mesh-venv/bin/activate

# Проверяем текущие настройки
meshtastic --port /dev/ttyACM0 --get serial

# Включаем Serial Module
meshtastic --port /dev/ttyACM0 --set serial.enabled true

# Режим TEXTMSG (отправляем как текстовые сообщения)
meshtastic --port /dev/ttyACM0 --set serial.mode 2

# Пины UART (Altruist TXD0 → Heltec GPIO48)
meshtastic --port /dev/ttyACM0 --set serial.rxd 48
meshtastic --port /dev/ttyACM0 --set serial.txd 47

# Скорость 115200 (enum value 11!)
meshtastic --port /dev/ttyACM0 --set serial.baud 11

# Таймаут 1 секунда (важно!)
meshtastic --port /dev/ttyACM0 --set serial.timeout 1

# Echo (для отладки)
meshtastic --port /dev/ttyACM0 --set serial.echo true

# Проверяем результат
meshtastic --port /dev/ttyACM0 --get serial
```

⚠️ **Важно о baud rate:**
```
Enum значения:
0 = Default
1 = 110
2 = 300
3 = 600
4 = 1200
5 = 2400
6 = 4800
7 = 9600
8 = 19200
9 = 38400
10 = 57600
11 = 115200  ← Altruist Urban
12 = 230400
13 = 460800
14 = 576000
15 = 921600
```

### Проверка связи

```bash
# На Heltec отправляем тест
meshtastic --port /dev/ttyACM0 --sendtext "TEST FROM HELTEC"

# На Pi проверяем журнал
sudo journalctl -u meshtasticd -f | grep "text msg"
# Должно быть:
# Received text msg from=0xb29f9cfc, msg=TEST FROM HELTEC
```

---

## 3. Python Bridge: journalctl → MQTT

### Установка зависимостей

```bash
source ~/mesh-venv/bin/activate
pip install paho-mqtt
```

### Запуск bridge

```bash
# Скрипт находится в scripts/journal_to_mqtt.py
# Параметры в начале файла:
MQTT_BROKER = "localhost"
MQTT_PORT = 1883
MQTT_USER = "mesh"
MQTT_PASS = "mesh123"
TARGET_NODE = "0xb29f9cfc"
```

```bash
# Запуск вручную
python3 ~/meshtastic-altruist-bridge/scripts/journal_to_mqtt.py

# Запуск как systemd service
sudo cp ~/meshtastic-altruist-bridge/config/mesh-mqtt-bridge.service /etc/systemd/system/
sudo systemctl enable mesh-mqtt-bridge
sudo systemctl start mesh-mqtt-bridge
```

### Проверка MQTT

```bash
# Подписаться на топики
mosquitto_sub -h localhost -u mesh -P mesh123 -t "altruist/#" -v

# Ожидаемый вывод:
# altruist/b29f9cfc/text {"source": "0xb29f9cfc", "msg_id": "0x...", "text": "...", "timestamp": 1234567890}
```

---

## 4. Проверка полного стенда

### Тест 1: Прямая связь

```bash
# Heltec → Pi (direct)
# Результат в journalctl:
# Received text msg from=0xb29f9cfc, msg=...
```

### Тест 2: Данные от Altruist Urban

```bash
# Данные автоматически идут:
# Altruist Urban → UART → Heltec → LoRa → Pi → MQTT
# Топик: altruist/b29f9cfc/text
```

### Тест 3: Двусторонняя связь

```bash
# Pi → Heltec
meshtastic --host localhost --sendtext "HELLO FROM PI"

# Heltec должна получить (если в радиусе)
```

---

## 5. Интеграция в городскую сеть (опционально)

### Получение city channel URL

1. Подключиться к любой ноде города через Web UI / Android app
2. **Каналы** → **Первичный** → **Экспорт**
3. Скопировать URL вида: `https://meshtastic.org/e/#CgcSAQE6...`

### Применение на обеих нодах

```bash
# На Pi (406B)
meshtastic --host localhost --ch-set-url <CITY_URL>

# На Heltec (9CFC)
meshtastic --port /dev/ttyACM0 --ch-set-url <CITY_URL>
```

⚠️ **Последствия**: Данные Altruist Urban станут видны ВСЕМ нодам городской сети.

---

## Полезные команды отладки

```bash
# Логи meshtasticd в реальном времени
sudo journalctl -u meshtasticd -f

# Фильтр только текстовых сообщений от 9CFC
sudo journalctl -u meshtasticd -f | grep "text msg.*from=0xb29f9cfc"

# Список нод
meshtastic --host localhost --nodes

# Информация о радио
meshtastic --host localhost --info

# Экспорт конфигурации
meshtastic --host localhost --export-config

# Проверка MQTT
mosquitto_sub -h localhost -u mesh -P mesh123 -t "#" -v
```
