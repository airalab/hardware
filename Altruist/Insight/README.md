# Altruist Insight

Altruist Insight — ESP32-C6–based indoor air-quality monitor with SCD41 carbon dioxide sensor, BME680 temperature / humidity / pressure sensors, 4.2" e-paper display, SD-card logging.

## Product Specification

- **Model ID:**
    - ES-ALTRUIST-INST-1
- **Processor & Memory:**
    - ESP32-C6-WROOM-1-N8, high-performance 32-bit single-core RISC-V CPU, up to 160 MHz
    - 320 KB ROM, 512 KB HP SRAM, 16 KB LP SRAM
    - 8 MB of Flash memory
    - MicroSD (support up to 4GB for local data)
- **Sensors:**
    - Sensirion SCD41, photoacoustic NDIR sensor (CO2)
    - Bosch BME680 (temperature, relative humidity, atmospheric pressure)
- **Connectivity:**
    - Wi-Fi 2.4 GHz, fully compatible with IEEE 802.11 b/g/n protocol
    - Radio module included in [ESP32-C6-WROOM-1-N8](Certificates/ESP32-C6/ESP32-C6-WROOM-1%20FCC%20Certification.pdf)
    - FCC ID: 2AC7Z-ESPC6WROOM1
- **Interface:**
    - 4.2’’ E-Paper display
    - LED indicators (28 LEDs)
    - 3 buttons
    - Web interface via local IP
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
- **Dimensions & Weight:**
    - 95 x 11 x 81 mm, 75 g
- **Operation Temperature and Humidity:**
    - 0°C … +40°C
    - 10 … 90% RH

## Sensors Specification

### Sensirion SCD41 (CO2)

- Range: 400-5000 ppm
- Accuracy: ±40.0 ppm ± 5.0%

### Bosch BME680

|                          | **Range**    | **Accuracy**                                                                                                        |
|--------------------------|--------------|---------------------------------------------------------------------------------------------------------------------|
| **Temperature**          | –40 … +85°C  | ±0.5°C (+25°C)<br>±1.0°C (0 … +65°C)                                                                                |
| **Relative humidity**    | 0-100% RH    | ±3% RH (20-80% RH, 25°C)                                                                                            |
| **Atmospheric pressure** | 300-1100 hPa | ±0.6 hPa (300-1100 hPa, 0 … +65°C)<br>±0.12 hPa (700-900 hPa, +25 … +40°C)<br>±0.12 hPa (900-1100 hPa, +25 … +40°C) |

## Design Options

<table>
    <tr>
        <th></th>
        <th>Color</th>
        <th>Model ID</th>
        <th>Link to Plastic</th>
    </tr>
    <tr>
        <th><img src="Img/Colors/cyan.png" width="64" alt="Cyan"></th>
        <th>Cyan</th>
        <th>ES-ALTRUIST-INST-1-CYAN</th>
        <th><a href="https://eu.store.bambulab.com/products/pla-basic-filament?id=54004785217884">PLA Basic - Color : Cyan (10603)</a></th>
    </tr>
    <tr>
        <th><img src="Img/Colors/magenta.png" width="64" alt="Magenta"></th>
        <th>Magenta</th>
        <th>ES-ALTRUIST-INST-1-MGNT</th>
        <th><a href="http://eu.store.bambulab.com/products/pla-basic-filament?id=47794655068508">PLA Basic - Color : Magenta (10202)</a></th>
    </tr>
    <tr>
        <th></th>
        <th>Orange</th>
        <th>ES-ALTRUIST-INST-1-ORNG</th>
        <th><a href="https://eu.store.bambulab.com/products/pla-basic-filament?t=1773913736103&id=42911327879387">PLA Basic - Color : Orange (10300)</a></th>
    </tr>
    <tr>
        <th></th>
        <th>Jade White</th>
        <th>ES-ALTRUIST-INST-1-JDWT</th>
        <th><a href="https://eu.store.bambulab.com/products/pla-basic-filament?t=1773913736103&id=42911327846619">PLA Basic - Color : Jade White (10100)</a></th>
    </tr>
    <tr>
        <th></th>
        <th>Black</th>
        <th>ES-ALTRUIST-INST-1-BLCK</th>
        <th><a href="https://eu.store.bambulab.com/products/pla-basic-filament?t=1773913736103&id=42911327846619">PLA Basic - Color : Black (10101)</a></th>
    </tr>
</table>
