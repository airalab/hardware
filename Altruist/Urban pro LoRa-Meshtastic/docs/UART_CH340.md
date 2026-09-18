# Управление Meshtastic-платой по UART (USB–UART CH340)

Практическое руководство: как управлять Meshtastic-платой без USB-разъёма — через внешний
USB–UART адаптер CH340, подключённый к аппаратному UART0. Готовый отчёт о проверке на стенде:
плата EByte EoRa-S3, управление с ноутбука Ubuntu тем же Meshtastic CLI, что и по нативному USB/BLE.

> **Важно:** в этом гайде CH340 подключается к служебной Meshtastic-плате EoRa-S3 (шлюз/ретранслятор),
> а **не** к сенсору Altruist Urban на Heltec V4. Распиновка подключения самого сенсора описана
> в [README](../README.ru.md).

---

Отчёт по проверке гипотезы: плата с прошивкой Meshtastic полностью управляется через внешний USB–UART
адаптер CH340, подключённый к аппаратному UART0 платы, — тем же Meshtastic CLI, что и по нативному USB/BLE.

Испытательный стенд: узел EByte EoRa-S3 с прошивкой Meshtastic (в mesh виден сенсорный узел
Altruist Urban на Heltec V4), управление с ноутбука Ubuntu через CH340.

| Компонент | Значение |
|---|---|
| Плата | EByte EoRa-S3 (ESP32-S3 + SX1262), hwModel `CDEBYTE_EORA_S3` |
| Прошивка | 2.7.26.54e0d8d, edition VANILLA |
| Адаптер | CH340G/CH341 (USB VID:PID `1a86:7523`), `/dev/ttyUSB0` |
| CLI | Meshtastic Python CLI 2.7.11 |
| Скорость | 115200, режим модуля PROTO |

## 1. Итог

Гипотеза подтверждена. По `/dev/ttyUSB0` работают все команды CLI: `--info`, `--nodes`, `--get/--set`,
`--export-config/--configure`, `--sendtext`, управление GPIO через RemoteHardware
(`hasRemoteHardware: true`). Обмен ничем не отличается от нативного USB — плата отдаёт полный
бинарный протокол Meshtastic (My info + Metadata + список узлов).

Практическая ценность: плату без USB-разъёма (или с занятым им) можно конфигурировать и
диагностировать по распаянному UART — тем же командами, что и по Bluetooth.

## 2. Распиновка разъёма EoRa-S3 и подключение CH340

По официальной спецификации EByte (EoRa-S3-900TB), 26-пиновый разъём:

| Пин разъёма | Метка | Функция | Подключение CH340 |
|---|---|---|---|
| 11 | U0RXD | UART0 RX платы (вход) | → TXD адаптера |
| 12 | U0TXD | UART0 TX платы (выход) | ← RXD адаптера |
| GND | GND | земля | ↔ GND адаптера |

Правила подключения:

- **Питание CH340 — только от USB хоста.** Не подключайте VCC адаптера к плате: при выключении
  или перезагрузке платы адаптер теряет питание и «пропадает» из USB (наблюдалось дважды).
- TX/RX соединяются накрест: TXD адаптера → RXD платы (U0RXD), RXD адаптера ← TXD платы (U0TXD).
- Без общего GND связи не будет.

### Частая ошибка: GPIO 47/48 — это не UART

Пины 19/20 разъёма (GPIO48/GPIO47) у EoRa-S3 — обычные GPIO, к UART отношения не имеют.
Распайка на них выглядит так: loopback-тест адаптера проходит (значит, сам адаптер исправен),
но плата молчит на всех скоростях, а ROM-лог ESP32 при загрузке не приходит.
Правильные пины — подписанные U0RXD (11) и U0TXD (12).

## 3. Конфигурация serial-модуля платы

Текущие значения (сняты `meshtastic --export-config`):

```yaml
module_config:
  serial:
    enabled: true
    mode: PROTO          # полный бинарный протокол Meshtastic (как нативный USB)
    baud: BAUD_115200
    rxd: 48              # см. примечание ниже
    txd: 47
    timeout: 1
```

- `override_console_serial_port` на прошивке 2.7.26 **не потребовался**: протокол идёт и без него
  (значение по умолчанию — false).
- Значения `rxd`/`txd` в конфиге (48/47) задают, какой GPIO модуль считает UART-ножкой. Рабочая
  связка на тестовой плате: `rxd: 48 / txd: 47` при пайке на U0RXD/U0TXD разъёма. Вариант
  `serial.rxd 44, serial.txd 43` (аппаратные UART0 ESP32-S3) проверен и **связи не дал** —
  на этой прошивке/плате рабочая именно указанная связка.
- Допустимые значения `mode` (protobuf 2.7.x): `DEFAULT`, `SIMPLE`, `PROTO`, `TEXTMSG`, `NMEA`,
  `CALTOPO`, `WS85`, `VE_DIRECT`, `MS_CONFIG`, `LOG`, `LOGTEXT`.
- Допустимые `baud`: `BAUD_DEFAULT`, `BAUD_110`, `BAUD_300`, `BAUD_600`, `BAUD_1200`, `BAUD_2400`,
  `BAUD_4800`, `BAUD_9600`, `BAUD_19200`, `BAUD_38400`, `BAUD_57600`, `BAUD_115200`, `BAUD_230400`,
  `BAUD_460800`, `BAUD_576000`, `BAUD_921600`.

Запись настроек по Bluetooth (если плата пока не подключена проводом):

```bash
meshtastic --ble <MAC-адрес-платы> --set serial.enabled true --set serial.mode PROTO --set serial.baud BAUD_115200
```

## 4. Диагностика: как искали правильные пины

| Метод | Наблюдение | Вывод |
|---|---|---|
| Loopback (RX↔TX адаптера замкнуты, 30 с) | отправлено 400 байт / принято 400, 100 эхо-событий | адаптер исправен на 100% |
| Распайка на GPIO 47/48 (обе полярности) | тишина на всех скоростях 9600–115200 | пины не UART |
| Boot-лог при подаче питания | ROM-вывод ESP32 виден на U0TXD при подаче питания | подтверждает пайку на UART0 (на GPIO 47/48 лога нет) |
| 8-байтовый «сигнал» `00 1c fc 00 e0 00 1c 00` | моменты всплесков совпали с USB-enumeration CH340 | артефакт подачи питания адаптера, не сигнал платы |
| Перепайка на U0RXD/U0TXD (пины 11/12) | `--info` сразу дал полный обмен | правильные пины найдены |

Вывод: прежде чем подозревать прошивку или настройки, проверьте адаптер loopback-ом и сверьте
распиновку с документацией производителя — «мусорные» байты на холодном старте могут быть
артефактом самого адаптера.

## 5. Проверка связи

```text
$ meshtastic --port /dev/ttyUSB0 --info

Connected to radio

Owner: Meshtastic 2bc0 (2bc0)
My info: { "myNodeNum": 797780928, "rebootCount": 76, "pioEnv": "CDEBYTE_EoRa-S3", ... }
Metadata: { "firmwareVersion": "2.7.26.54e0d8d", "hwModel": "CDEBYTE_EORA_S3",
            "hasBluetooth": true, "hasRemoteHardware": true, ... }

Nodes in mesh:
  "!2f8d2bc0": longName "Meshtastic 2bc0", hwModel CDEBYTE_EORA_S3
  "!b29f9cfc": longName "Altruist Urban",  hwModel HELTEC_V4, role SENSOR, hopsAway 0
```

## 6. Управление через Meshtastic CLI (2.7.11)

Установка (в виртуальном окружении):

```bash
python3 -m venv ~/mesh-venv
source ~/mesh-venv/bin/activate
pip install -U meshtastic
```

Ниже `meshtastic` = CLI из venv. Один и тот же синтаксис работает по serial и Bluetooth:
замените `--port /dev/ttyUSB0` на `--ble <MAC-адрес-платы>` и наоборот. Список BLE-устройств:
`meshtastic --ble-scan`.

**Важно: один клиент за раз.** Если порт/BLE уже занят (web-клиент client.meshtastic.org,
запущенный `--listen`, другой CLI) — новое соединение не установится. Проверить, кто держит
serial-порт: `fuser -v /dev/ttyUSB0`.

### 6.1 Чтение параметров (безопасно)

```bash
meshtastic --port /dev/ttyUSB0 --get lora.region
meshtastic --port /dev/ttyUSB0 --export-config > config.yaml   # полный дамп конфигурации
```

### 6.2 Запись параметров

Формат: `--set <раздел.поле> <значение>` (имена полей — как в `--export-config`).
Enum-значения передаются именами, например `PROTO`, `BAUD_115200` — числами их задавать не надо.

```bash
# радио
meshtastic --port /dev/ttyUSB0 --set lora.region RU --set lora.hopLimit 3 --set lora.txPower 20
# bluetooth
meshtastic --port /dev/ttyUSB0 --set bluetooth.enabled true --set bluetooth.fixedPin 654321
# serial-модуль (см. раздел 3)
meshtastic --port /dev/ttyUSB0 --set serial.enabled true --set serial.mode PROTO --set serial.baud BAUD_115200
# модули
meshtastic --port /dev/ttyUSB0 --set remoteHardware.enabled true --set telemetry.deviceUpdateInterval 1800
# перезагрузка после серии изменений
meshtastic --port /dev/ttyUSB0 --reboot
```

После каждого `--set` плата сама перезагружается (~20 с) — следующую команду давайте после паузы.
Существующие ключи шифрования (`security.privateKey`/`publicKey`) не перезаписывать.

### 6.3 Каналы

Каналы редактируются флагами `--ch-*`, а не через `--set`:

```bash
# посмотреть список допустимых полей канала
meshtastic --port /dev/ttyUSB0 --ch-set all all --ch-index 0

# создать канал (имя до 10 символов; индекс — первый свободный, обычно 1)
meshtastic --port /dev/ttyUSB0 --ch-add MyChannel

# настроить созданный канал: ключ, имя, аплинк в публичную сеть
meshtastic --port /dev/ttyUSB0 --ch-index 1 --ch-set psk random --ch-set name MyChannel --ch-set uplink_enabled true
```

Ключ канала задаётся как `psk random` (сгенерировать), `psk none` (без шифрования), `psk simple1`,
`psk 0x<64 hex>` или `psk base64:<ключ>` — как в URL канала из `--export-config` (поле `channel_url`).

### 6.4 Пакетное применение

Правится YAML (формат как у `--export-config`) и применяется целиком — плата перезагрузится один раз:

```bash
meshtastic --port /dev/ttyUSB0 --configure config.yaml
```

### 6.5 Отправка сообщений

```bash
# широковещательное в Primary channel (индекс 0 — по умолчанию)
meshtastic --port /dev/ttyUSB0 --sendtext "привет из канала"

# в другой канал
meshtastic --port /dev/ttyUSB0 --sendtext "привет" --ch-index 1

# личное сообщение (DM): сначала узнать точный ID узла (! + 8 hex-символов)
meshtastic --port /dev/ttyUSB0 --nodes | grep -i <имя-узла>

# отправка DM (ID — в одинарных кавычках!)
meshtastic --port /dev/ttyUSB0 --sendtext "привет" --dest '!1234abcd'
```

**Одинарные кавычки обязательны:** в интерактивном bash `!` внутри двойных кавычек запускает
history expansion — ID вида `!1234abcd` bash раскроет как «команду №1234 из истории», и CLI
получит мусор (`unrecognized arguments: ...`). Альтернативы: экранировать `\!1234abcd` или
разово отключить `set +H`.

Доставка: с флагом `--ack` CLI дождётся подтверждения доставки; время ожидания задаётся
`--timeout <сек>` (по умолчанию 300).

### 6.6 Типичные грабли

- Порт занят собственным `--listen` или web-клиентом → Ctrl+C / `fuser -v /dev/ttyUSB0`.
- После `--set` — пауза ~20 с (плата перезагружается).
- После подключения CH340 к USB плата становится доступна через ~20 с.
- BLE держит только один клиент: закройте вкладку client.meshtastic.org перед работой по `--ble`.
- `--dest` принимает `!xxxxxxxx`, `0x...` или номер узла; надёжнее полный ID с `!`.

## 7. Выводы

1. Управление Meshtastic-платой через USB–UART (CH340) на аппаратном UART0 полностью эквивалентно
   нативному USB: конфигурация, каналы, сообщения, RemoteHardware-GPIO.
2. Критична правильная распайка: U0RXD (пин 11) и U0TXD (пин 12) разъёма EoRa-S3; GPIO 47/48 — не UART.
3. Конфиг `serial.rxd 48 / txd 47` при такой пайке рабочий; вариант 44/43 связи не дал.
4. CH340 питать только от USB хоста; GND общий.
5. Режим serial-модуля — PROTO, 115200; на прошивке 2.7.26 `override_console_serial_port` не нужен.
6. Перед диагностикой: loopback-тест адаптера, затем сверка pinout с документацией производителя;
   ROM-лог ESP32 на U0TXD при подаче питания — признак правильной пайки.