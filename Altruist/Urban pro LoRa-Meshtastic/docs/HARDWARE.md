# Hardware Setup Guide

## Altruist Urban Pinout

| Pin | Назначение | Примечание |
|-----|-----------|------------|
| TXD0 | UART TX | GPIO17 (ESP32-C6) |
| RXD0 | UART RX | GPIO16 (ESP32-C6) |
| GND | Земля | |
| 3.3V | Питание | Heltec может питать Altruist через 3.3V |

## Heltec HTIT-WB32LA V4 Pinout

| GPIO | Функция | Default | Использование |
|------|---------|---------|---------------|
| 47 | UART RX (Serial2) | | Приём от Altruist TXD0 |
| 48 | UART TX (Serial2) | | Отправка на Altruist RXD0 |
| 18 | LoRa RESET | | |
| 14 | LoRa DIO1 (IRQ) | | |
| 26 | LoRa CS | | |
| 3 | LoRa SCK | | |
| 46 | LoRa MOSI | | |
| 9 | LoRa MISO | | |
| 33 | OLED SDA | | |
| 34 | OLED SCL | | |

## MeshAdv-Pi-Hat (E22-900M30S) → Raspberry Pi

| Pi Pin | Pi GPIO | Назначение | SX1262 Pin |
|--------|---------|-----------|------------|
| 19 | GPIO 10 | SPI MOSI | MOSI |
| 21 | GPIO 9 | SPI MISO | MISO |
| 23 | GPIO 11 | SPI SCK | SCK |
| 24 | GPIO 8 (alt) | SPI CS0 | NSS |
| 36 | GPIO 16 | IRQ | DIO1 |
| 38 | GPIO 20 | Busy | BUSY |
| 40 | GPIO 21 | Reset | RST |
| 29 | GPIO 5 | TX Enable | TXEN |
| 31 | GPIO 6 | RX Enable | RXEN |

⚠️ **Важно**: MeshAdv-Pi-Hat использует **не стандартные** GPIO для CS/IRQ/Reset. Точная распиновка указана в `config/meshtasticd.yaml`:

```yaml
Lora:
  Module: sx1262
  CS: 21
  IRQ: 16
  Busy: 20
  Reset: 18
  TXen: 13
  RXen: 12
  DIO3_TCXO_VOLTAGE: true
```

## Схема подключения Altruist → Heltec

```
Altruist Urban          Heltec V4
┌──────────┐            ┌──────────┐
│ TXD0     │───────────>│ GPIO 48  │ (Serial RX)
│ RXD0     │<───────────│ GPIO 47  │ (Serial TX)
│ GND      │────────────│ GND      │
│ 3.3V     │────────────│ 3.3V     │ (опционально)
└──────────┘            └──────────┘
```

## Фото подключений

*(Добавить фото после сборки)*

1. Altruist Urban + Heltec UART
2. MeshAdv-Pi-Hat на Raspberry Pi GPIO
3. Общий вид обоих сетапов
4. Скриншот Web UI Meshtastic

## Питание

| Сетап | Требования |
|-------|-----------|
| Altruist Urban | 3.3V / 200mA (или USB-C) |
| Heltec V4 | USB-C 5V / 500mA |
| Raspberry Pi 4B | USB-C 5V 3A |
| MeshAdv-Pi-Hat | Питается от Pi (3.3V через GPIO) |

**Рекомендация**: Heltec питайте через USB-C, не через Pi. Altruist можно питать от Heltec 3.3V пина.
