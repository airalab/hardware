Status: tested

tested factory:
* JLCPCB

Features:

1. Support of any USB power supply with QC2, QC3 or USB-PD (Power Delivery) specification

2. Operating in the local library, without the need for cloud access

3. Support of Home Assistant via the MQTT protocol (to configure the device, please visit Tasmota docs)

Hardware specification:

- Viewing angle 360°
- CPU: ESP32 series of SoCs, Xtensa 32-­bit LX6 microprocessor, up to 240 MHz
- Memory: 448 KB ROM, 520 KB SRAM, 8 MB FLASH
- Wireless protocol: IEEE 802.11b/g/n (2.4 GHz Wi-Fi)
- Input voltage: DC 5V USB-C (QC2, QC3, PD)
- Standby consumption: 95mA
- Weight: 36g

Firmware:

- Powered by Tasmota, an open firmware distributed under GNU GPLv3, the firmware can be upgraded via USB-C or OTA.
- The driver enables sending IR codes through an IR transmitter and receiving them through an IR receiver via IRremoteESP8266 library.
