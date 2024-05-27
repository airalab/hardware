Features:

1. Monitor energy consumption, whether that's an individual estate or an entire building

2. The included software provides vital insight that can help to control and save energy in the future

3. Monitoring works on the local network and does not require access to the cloud

4. Support of Home Assistant via the MQTT protocol (to configure the device, please visit Tasmota docs)

Cautions

In general, a current transformer (CT) should never be open-circuited while it is connected to a current-carrying conductor. A transformer is potentially dangerous if it is open-circuited.

When the circuit is open, with current flowing in the primary winding, the secondary winding of the transformer will try to continue driving the current to what is effectively an infinite resistance. This will create high and potentially dangerous voltage on the secondary winding.

Some CT’s have built-in protection, some have protective Zener diodes as is the case with the SCT-013-000 recommended for use in this project. If the CT is a voltage output type, it has a built-in burden resistor. Thus, it cannot be opened.

Hardware specification:

- Input Voltage: AC 100-240V 50/60Hz
- Measuring Range: 0.1-80A
- Wireless Protocol: IEEE 802.11b/g/n (2.4 GHz Wi-Fi)
- CPU: ESP32-S3 MCU-based system on a chip (SoC) dual-core microprocessor (Xtensa 32-bit LX7), up to 240 MHz
- Memory: 448 KB ROM, 520 KB SRAM, 8 MB FLASH
- USB-C for development and updates

Firmware:

- Powered by Tasmota, an open firmware distributed under GNU GPLv3, the firmware can be upgraded via USB-C or OTA.
- To learn more and download the latest firmware, visit:
https://tasmota.github.io/docs/Power-Monitoring-Calibration
https://tasmota.github.io/docs/Commands/#power-monitoring
