# Meshtastic IoT Bridge: Altruist Urban + Heltec + Raspberry Pi

## Project Overview

A testbed for transmitting air quality sensor data from **Altruist Urban** (ESP32-C6) through **Heltec HTIT-WB32LA V4** via LoRa/Meshtastic to a **Raspberry Pi 4B + MeshAdv-Pi-Hat (E22-900M30S)** gateway node. Data from remote locations (without Wi-Fi/Internet) is delivered through the mesh network to an internet-connected node and published to a local MQTT broker.

**[🇷🇺 Русская версия](README.ru.md)**

---

## Testbed Components

### Setup 1: Transmitter (Remote / Field Node)

| Component | Model | Notes |
|-----------|-------|-------|
| Sensor | Altruist Urban | ESP32-C6, SDS011, BME280, ICS43434 |
| LoRa Board | Heltec HTIT-WB32LA V4 | SX1262, 868 MHz |
| Firmware | Meshtastic 2.7.26.54e0d8d | HELTEC_V4 |
| Node ID | `!b29f9cfc` | MAC: 80:f1:b2:9f:9c:fc |
| USB | `/dev/ttyACM0` | Espressif USB JTAG/serial debug unit (303a:1001) |

### Setup 2: Receiver (Gateway Node)

| Component | Model | Notes |
|-----------|-------|-------|
| SBC | Raspberry Pi 4B 4GB | Ubuntu 24.04 LTS (aarch64) |
| LoRa Module | MeshAdv-Pi-Hat E22-900M30S | SX1262, 30dBm |
| Firmware | meshtasticd 2.7.26 | PORTDUINO |
| Node ID | `!014c406b` | MAC: e4:5f:01:4c:40:6b |
| API | TCP `:4403` | Web UI `:80` |

---

## Wiring Diagram

### Altruist Urban → Heltec (UART)

| Altruist Urban | Direction | Heltec GPIO | Notes |
|----------------|---|---|-------|
| IO22 (TXD) | → | GPIO 48 (RXD) | Sensor data → Heltec |
| IO20 (RXD) | ← | GPIO 47 (TXD) | Heltec → sensor (reverse channel) |
| GND | — | GND | Common ground required |

![Altruist Urban → Heltec Wiring Diagram](images/altruist-heltec-wiring.jpg)

*Wiring diagram: Altruist Urban (Robonomics) → Heltec HTIT-WB32LA V4*  
*Red = GND, Yellow = IO22→GPIO48, Green = GPIO47→IO20, Brown = 3.3V*

⚠️ **Important**: Altruist Urban sends data at 115200 baud. Common GND is mandatory.
Note: IO22/IO20 are pins on the Altruist Urban side; on the Heltec, GPIO 48 (receive) and GPIO 47 (transmit) are used.

### MeshAdv-Pi-Hat → Raspberry Pi 4B (GPIO)

| Pi GPIO | Function | Notes |
|---------|----------|-------|
| GPIO 21 | CS (SPI) | Chip Select |
| GPIO 16 | IRQ | Interrupt |
| GPIO 20 | Busy | SX1262 Busy pin |
| GPIO 18 | Reset | Hardware reset |
| GPIO 13 | TXen | TX enable |
| GPIO 12 | RXen | RX enable |

SPI uses standard pins: GPIO 10 (MOSI), GPIO 9 (MISO), GPIO 11 (SCK).

---

## Software Setup

### 1. Raspberry Pi (Gateway)

```bash
# Install meshtasticd from official PPA
sudo add-apt-repository ppa:meshtastic/beta
sudo apt update
sudo apt install meshtasticd

# LoRa module configuration /etc/meshtasticd/config.yaml
```

**`/etc/meshtasticd/config.yaml`:**

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

Webserver:
  Port: 80
```

```bash
# VFS permissions
sudo chown -R meshtasticd:meshtasticd /var/lib/meshtasticd/
sudo usermod -aG spi,gpio meshtasticd

# Start service
sudo systemctl enable --now meshtasticd

# Verify
meshtastic --host localhost --info
```

### 2. Region Setup

The region depends on the network the node operates in:

```bash
# Russia / RU region
meshtastic --host localhost --set lora.region RU

# Europe / 868 MHz
meshtastic --host localhost --set lora.region EU_868
```

### 3. Heltec (Field Node)

```bash
# Connect via USB on Pi (or from PC)
meshtastic --port /dev/ttyACM0 --info

# Configure Serial Module to receive data from Altruist
meshtastic --port /dev/ttyACM0 --set serial.enabled true
meshtastic --port /dev/ttyACM0 --set serial.mode TEXTMSG   # text mode (enum: TEXTMSG = 3; value 2 = PROTO!)
meshtastic --port /dev/ttyACM0 --set serial.rxd 48         # Receive from Altruist IO22
meshtastic --port /dev/ttyACM0 --set serial.txd 47         # Transmit to Altruist IO20
meshtastic --port /dev/ttyACM0 --set serial.baud BAUD_115200
meshtastic --port /dev/ttyACM0 --set serial.timeout 1      # 1 second silence = transmit
meshtastic --port /dev/ttyACM0 --set serial.echo true
```

⚠️ **Critical**: `serial.mode` and `serial.baud` take **enum names**, not numbers.
The CLI accepts names directly; a number only sets the enum index, which is easy to mix up:
- `serial.mode`: `DEFAULT` = 0, `SIMPLE` = 1, `PROTO` = 2, **`TEXTMSG` = 3**, `NMEA` = 4
- `serial.baud`: the bitrate is set by name — **`BAUD_115200`** (plain `115200` is outside the enum range and will be rejected)

### 4. Link Verification

Send test from Heltec:
```bash
meshtastic --port /dev/ttyACM0 --sendtext "TEST"
```

Check on Pi:
```bash
sudo journalctl -u meshtasticd -f | grep "text msg"
```

Expected result:
```
Received text msg from=0xb29f9cfc, msg=TEST
```

---

## Experiment Results

### Direct Link (Heltec ↔ Pi)

| Parameter | Value |
|-----------|-------|
| Distance | ~ indoor / same room |
| SNR | ~6.0 – 7.25 dB |
| RSSI | ~-2 … -20 dBm |
| Hops | 0 (Direct) |
| Frequency | 869.525 MHz |
| Preset | LongFast (SF11, BW250) |
| TX Power | 27 dBm |

### Data Format from Altruist Urban

Data arrives via UART every 30–60 seconds. Current firmware sends **JSON** (delivered into
Meshtastic as a text message on the primary channel):

```json
{"id":"4DsxFHkjmofsEphBRYXodAW8NmQXmmX5cC3tj428AGnCa9WL","ts":1789649752,"p1":4.9,"p2":3.8,"t":23.8,"h":43.4,"p":100456,"n":49,"nm":67,"s":"X8I2V3Z/yjNo4vHf7QTqYUvKXGnZ4ANFYu5zcaavpsjtCHAjTIHED2yBPC/ymJIlyFyzIIrPGEYKqJfxNC/jCA=="}
```

| Field | Type | Meaning |
|-------|------|---------|
| `id` | base58, 44 chars | Packet ID (32 bytes) |
| `ts` | unix time | Timestamp (seconds) |
| `p1` / `p2` | µg/m³ | PM2.5 / PM10 |
| `t` / `h` | °C / % | Temperature / humidity |
| `p` | Pa | Barometric pressure |
| `n` / `nm` | dB | Noise metrics (ICS-43434 microphone) |
| `s` | base64, 64 bytes | Packet signature |

<details>
<summary>Legacy format (pre-update firmware): hex strings with `##`</summary>

```
6a21dd03b0b2cabe61c0bc4c6033f7cfbe95d1128bea863d844837a83c46a6de...##
[extractRuntimeVersions] cache hit spec=42 tx=3#
67e1e9551465c8afe26421c844cc6c378e8085f9acc054c25138f18be9707f4f...##
```

- **Hex strings** ending with `##` — signatures/hashes (SDS011/BME280 packets)
- **Text labels** like `[extractRuntimeVersions]` — runtime logs
- **Binary characters** (`▒`) may appear in the stream

</details>

### City Mesh Retransmission

To forward sensor data into the city mesh, **channel 1 ("city network")** was added on the
Heltec: the primary channel (index 0) receives the sensor JSON over UART, and channel 1
retransmits this data into the city mesh. List configured channels:

```bash
meshtastic --port /dev/ttyACM0 --ch-set all all --ch-index 0
```

Adding a new channel and setting its name:

```bash
meshtastic --port /dev/ttyACM0 --ch-add city
meshtastic --port /dev/ttyACM0 --ch-set name city --ch-index 1
```

> Note: there are no `--channels` or `--ch-name` flags in the CLI (verified on 2.7.11) —
> a channel name is set via `--ch-set name <name> --ch-index N`.

### Bidirectional Communication

| Direction | Working |
|-----------|---------|
| 406B → 9CFC | ✅ (text messages) |
| 9CFC → 406B | ✅ (text + serial data) |
| 9CFC → 406B (via city mesh) | Requires common channel URL |

---

## MQTT Integration

### Installing Mosquitto on Pi

```bash
sudo apt install mosquitto mosquitto-clients

# Create user
sudo touch /etc/mosquitto/passwd
sudo mosquitto_passwd -b /etc/mosquitto/passwd mesh mesh123
sudo chown mosquitto:mosquitto /etc/mosquitto/passwd
sudo chmod 640 /etc/mosquitto/passwd

# External listener /etc/mosquitto/conf.d/10-ext.conf
```

**`/etc/mosquitto/conf.d/10-ext.conf`:**
```
listener 1883 0.0.0.0
allow_anonymous false
password_file /etc/mosquitto/passwd
```

```bash
sudo systemctl restart mosquitto
```

### Meshtastic MQTT Module

**⚠️ Issue**: Built-in MQTT Module in `meshtasticd` (PORTDUINO) is unstable — packets are not published, configuration errors `Unknown module config type 14/15/16`.

### Working Solution: Python Bridge (journalctl → MQTT)

```bash
pip install paho-mqtt
```

Script listens to `journalctl -u meshtasticd`, parses lines `Received text msg from=0xb29f9cfc`, and publishes JSON to MQTT.

**Topics:**
- `altruist/b29f9cfc/text` — text messages
- `altruist/b29f9cfc/raw` — unrecognized data

**Example payload:**
```json
{
  "source": "0xb29f9cfc",
  "msg_id": "0x4d1099c6",
  "text": "6a21dd03b0b2cabe...##",
  "timestamp": 1785828186
}
```

---

## Known Issues

| Issue | Cause | Solution |
|-------|-------|----------|
| Heltec doesn't see Altruist UART | `timeout=120`, data streams continuously | Set `serial.timeout 1` |
| Heltec reboots during setup | NVS write takes time | Wait 5 sec between commands |
| Web UI empty/crashes | meshtasticd Web UI V2.6.7 unstable | Use `journalctl` or Python API |
| meshtasticd MQTT not working | PORTDUINO firmware limitation | Use Python bridge |
| Heltec mode resets to PROTO | After re-flash/factory reset serial.mode falls back to `DEFAULT` (0) | Check `--get serial.mode`; the text bridge needs `TEXTMSG` (3), not `PROTO` (2) |

---

## Next Steps

1. **City mesh integration** — obtain `Primary channel URL` from city admin and apply to both nodes
2. **Data isolation** — configure private channel or use DM via Python proxy
3. **Scaling** — add Pi Zero 2 W as UART proxy at remote location
4. **Home Assistant** — subscribe HA to MQTT topics `altruist/#`

---

## License

MIT / Public Domain. Open Source project based on Meshtastic (GPL).

---

## See Also

- [docs/UART_CH340.md](docs/UART_CH340.md) — controlling a Meshtastic board (EByte EoRa-S3) over UART via a CH340 adapter without a USB port: wiring, diagnostics, full CLI access.
