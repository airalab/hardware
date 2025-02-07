[EN](./README.md) | [RU](./README.ru.md)

Что бы самостоятельно скомпилировать прошивку из оригинального репозитория Tasmota используйте команду
pio run -e em-esp32s3 -e es-sds-esp8266 -e ir-esp32 -e ir-esp32c6 -e sws-1g-e-esp32 -e sws-2g-e-esp32

# Инструкция по прошивке устройств Robonomics Hardware
## На русском языке

### 1. Установка ESPTool
1. Скачайте последнюю версию утилиты `esptool` с [официального репозитория](https://github.com/espressif/esptool/releases).
2. Распакуйте архив в отдельную папку.

### 2. Подготовка прошивки
1. Загрузите актуальную версию прошивки для вашего устройства с [релизов Robonomics Hardware](https://github.com/airalab/hardware/releases).
2. Поместите файл прошивки (например, `em-esp32c6.factory.bin`) в папку с `esptool`.

### 3. Подключение устройства
1. Зажмите кнопку **Boot** на плате устройства.
2. Подключите устройство к компьютеру через USB-C.
3. Отпустите кнопку **Boot** после подключения.

### 4. Определение COM-порта
- **Windows**: Используйте Диспетчер устройств (порт будет обозначен как `COMXX`, например `COM3`).
- **Linux/Mac**: Используйте команду `ls /dev/tty*` для поиска порта (обычно `/dev/ttyUSB0` или `/dev/ttyACM0`).

### 5. Очистка памяти
Выполните в командной строке:
```bash
esptool.exe --port <COM_PORT> erase_flash
```
Пример для COM3:
```bash
esptool.exe --port COM3 erase_flash
```

### 6. Запись прошивки
Используйте команду в соответствии с вашим устройством:

| Устройство           | Команда                                                                                          |
|----------------------|--------------------------------------------------------------------------------------------------|
| Robo-EM-ESP32C6      | `esptool.exe --port <COM_PORT> --chip esp32c6 --baud 921600 write_flash 0x0 em-esp32c6.factory.bin` |
| Robo-ES-SDS-ESP8266  | `esptool.exe --port <COM_PORT> --chip esp8266 --baud 460800 write_flash 0x0 es-sds-esp8266.bin`    |
| Robo-IR-ESP32        | `esptool.exe --port <COM_PORT> --chip esp32 --baud 921600 write_flash 0x0 ir-esp32.bin`            |

### 7. Завершение
1. После успешной записи перезагрузите устройство.
2. Настройте устройство через веб-интерфейс Tasmota.

### Примечания / Notes
- Для ESP32-C6 и ESP32-S3 используйте `--baud 921600`. Для ESP8266 — `--baud 460800`.
- Если возникли ошибки, попробуйте снизить скорость (`--baud 115200`).
- Для Linux/Mac замените `esptool.exe` на `python -m esptool`.