# Altruist Urban

Altruist Urban — ESP32-C6–based outdoor air-quality monitor with SDS011 particle sensor, ICS-43434 noise sensor, BME280 temperature, humidity and pressure sensors.

## Product Specification

- **Model ID:**
    - ES-ALTRUIST-URB-1
- **Processor & Memory:**
    - ESP32-C6-WROOM-1-N8, high-performance 32-bit single-core RISC-V CPU, up to 160 MHz
    - 320 KB ROM, 512 KB HP SRAM, 16 KB LP SRAM
    - 8 MB of Flash memory
- **Sensors:**
    - Nova SDS011, laser-based particulate-matter sensor (PM2.5, PM10)
    - Bosch BME280 (temperature, relative humidity, atmospheric pressure)
    - TDK InvenSense ICS-43434, digital MEMS microphone for ambient-noise monitoring
- **Connectivity:**
    - Wi-Fi 2.4 GHz, fully compatible with IEEE 802.11 b/g/n protocol
    - Radio module included in [ESP32-C6-WROOM-1-N8](Certificates/ESP32-C6/ESP32-C6-WROOM-1%20FCC%20Certification.pdf)
    - FCC ID: 2AC7Z-ESPC6WROOM1
- **Interface:**
    - Web interface via local IP
    - Data output to a display of the peered Altruist Insight
    - LED indication of device activity
    - USB-C port for access to firmware and logs
- **Power Supply:**
    - Operating voltage: 5 V
    - Maximum current: 0.6 A
    - Powered via USB-C connector
- **Integrations:**
    - [Home Assistant](https://www.home-assistant.io/integrations/altruist/)
    - Сustom API (via web interface)
    - InfluxDB (via web interface)
- **Device Housing Material:**
    - 3D-printed case from [PLA plastic](Certificates/Plastic%20for%203D-printing)
- **Installation:**
    - Standing
    - Wall mount
- **Dimensions & Weight:**
    - 125 x 49 x 164 mm, 214 g
- **Operation Temperature and Humidity:**
    - –25°C … +50°C
    - 10 … 90% RH

## Sensors Specification

### Nova SDS011

|           | **Range**       | **Accuracy**      |
|-----------|-----------------|-------------------|
| **PM2.5** | 0.0-999.9 μg/m3 | ±10 μg/m3 or ±15% |
| **PM10**  | 0.0-999.9 μg/m3 | ±10 μg/m3 or ±15% |

### TDK InvenSense ICS-43434 (noise)

- **Sensitivity**: −26 dB FS ±1 dB
- **Acoustic Overload Point**: 120 dB SPL
- **Signal-to-Noise Ratio**: 65 dBA
- **Frequency Range**: 60 Hz - 20 kHz

### Bosch BME280

|                          | **Range**    | **Accuracy**                                                                                       |
|--------------------------|--------------|----------------------------------------------------------------------------------------------------|
| **Temperature**          | –40 … +85°C  | ±0.5°C (0 … +65°C)<br>±1.25 °C (–20 … 0°C)<br>±1.5 °C (–40 … –20°C)                                |
| **Relative humidity**    | 0-100% RH    | ±3% RH (20-80% RH, 25°C)                                                                           |
| **Atmospheric pressure** | 300-1100 hPa | ±1.0 hPa (300-1100 hPa, 0 … +65°C)<br>±1.7 hPa (–20 … 0 °C)<br>±1.5 hPa (1100-1250 hPa, 25 … 40°C) |

## Design Options

<table>
    <tr>
        <th></th>
        <th>Color</th>
        <th>Icon</th>
        <th>Model ID</th>
        <th>Link to Plastic</th>
    </tr>
    <tr>
        <th><img src="Img/Colors_Icons/blue-smile.png" width="64" alt="Blue-Smile"></th>
        <th>Blue</th>
        <th>Smile</th>
        <th>ES-ALTRUIST-URB-1-BL-SM</th>
        <th><a href="https://eu.store.bambulab.com/products/pla-basic-filament?id=54004785217884">PLA Basic - Color : Cyan (10603)</a></th>
    </tr>
    <tr>
        <th><img src="Img/Colors_Icons/blue-deadly.png" width="64" alt="Blue-Deadly"></th>
        <th>Blue</th>
        <th>Deadly</th>
        <th>ES-ALTRUIST-URB-1-BL-DD</th>
        <th><a href="https://eu.store.bambulab.com/products/pla-basic-filament?id=54004785217884">PLA Basic - Color : Cyan (10603)</a></th>
    </tr>
    <tr>
        <th><img src="Img/Colors_Icons/blue-enjoy.png" width="64" alt="Blue-Enjoy"></th>
        <th>Blue</th>
        <th>Enjoy</th>
        <th>ES-ALTRUIST-URB-1-BL-EJ</th>
        <th><a href="https://eu.store.bambulab.com/products/pla-basic-filament?id=54004785217884">PLA Basic - Color : Cyan (10603)</a></th>
    </tr>
    <tr>
        <th><img src="Img/Colors_Icons/pink-smile.png" width="64" alt="Pink-Smile"></th>
        <th>Pink</th>
        <th>Smile</th>
        <th>ES-ALTRUIST-URB-1-PK-SM</th>
        <th><a href="http://eu.store.bambulab.com/products/pla-basic-filament?id=47794655068508">PLA Basic - Color : Magenta (10202)</a></th>
    </tr>
    <tr>
        <th><img src="Img/Colors_Icons/pink-deadly.png" width="64" alt="Pink-Deadly"></th>
        <th>Pink</th>
        <th>Deadly</th>
        <th>ES-ALTRUIST-URB-1-PK-DD</th>
        <th><a href="http://eu.store.bambulab.com/products/pla-basic-filament?id=47794655068508">PLA Basic - Color : Magenta (10202)</a></th>
    </tr>
    <tr>
        <th><img src="Img/Colors_Icons/pink-enjoy.png" width="64" alt="Pink-Enjoy"></th>
        <th>Pink</th>
        <th>Enjoy</th>
        <th>ES-ALTRUIST-URB-1-PK-EJ</th>
        <th><a href="http://eu.store.bambulab.com/products/pla-basic-filament?id=47794655068508">PLA Basic - Color : Magenta (10202)</a></th>
    </tr>
</table>
