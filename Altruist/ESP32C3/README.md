#Altruist Outdoor Sensor

**Altruist** is a smart sensor that collects environmental data and combines it into a decentralized sensor map.

<img src="https://github.com/airalab/hardware/blob/main/Altruist/ESP32C3/Img/3D-view-Altruist-title.png" width="500px">

With the **Altruist** Outdoor Sensor, you become a force in decentralized environmental monitoring. Capture noise, dust, and temperature data—encrypted, mapped, and shared across a distributed network.
Experience the power of true DePIN (Decentralized Physical Infrastructure Network) — a revolutionary technological movement brought to life and thriving for years on our [decentralized sensor map](https://sensors.social/).

**Hardware specification**
- Input Voltage  AC 100-240V 50/60Hz
- Wireless protocol: Supports 2.4GHz Wi-Fi 6 (802.11 b/g/n) and Bluetooth 5 (LE), Zigbee with onboard antenna
- Equipped with a high-performance 32-bit RISC-V processor with clock speed up to 160 MHz, and a low-power 32-bit RISC-V processor with clock speed up to 20MHz
- Memory: 320KB ROM, 512KB of HP SRAM, 16KB LP SRAM and 4MB Flash memory
- USB-C for firmware development and updates
- PM sensor: SDS011 laser PM2.5/PM10 sensor
- Support sensors : 
-  T&H : SHT3X,BME280,HTU21D
- Noise Level Sensor:  I2S INMP441, ICS-43434
- GPS: BN220-GSP
- Geiger counter : [Radsens](https://github.com/climateguard/RadSens)

**Advanced Peripheral Interfaces:**
     Digital interfaces:
        – Two UART for PM sensors, GPS
        – I2C for atmospheric pressure, temperature, humidity, geiger counter, CO2, TVOC and other gas sensors
        – I2S for connecting digital microphones for noise analysis
Built-in AC -DC 5V 0.35A power supply
Built-in connectors :
- HY2.0-4P : i2c for atmospheric pressure, temperature, humidity.
- XH-4AW:  i2c for geiger counter
- ZH-5AW: i2s for digital microphones
- XH-5P : for SDS011 PM sensor
- SH1.0-4PWT: UART for GPS
- Screw Terminal Blocks : for AC connection