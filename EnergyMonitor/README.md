**HW version: Robo-EM-ESP32C RC3**
Status: Ok
tested factory: 
* JLCPCB
---
**Description**
	Single-phase energy monitoring
**Story:**
	This device was developed by the Robotonomics team. The main idea that prompted the creation of this device is the rejection of cloud solutions from manufacturers of IOT devices. 
	Join the community and purchase a [device.](https://robonomics.network/devices/)  We will be glad to see anyone who wants to develop the project of this device.
 
**Features:**
1. Monitor energy consumption, whether that's an individual estate or an entire building
2. The included software provides vital insight that can help to control and save energy in the future
3. Monitoring works on the local network and does not require access to the cloud
4. Support of Home Assistant via the MQTT protocol (to configure the device, please visit [Tasmota docs](https://tasmota.github.io/docs/ )

**Cautions**
- In general, a current transformer (CT) should never be open-circuited while it is connected to a current-carrying conductor. A transformer is potentially dangerous if it is open-circuited.
- When the circuit is open, with current flowing in the primary winding, the secondary winding of the transformer will try to continue driving the current to what is effectively an infinite resistance. This will create high and potentially dangerous voltage on the secondary winding.
- Some CT’s have built-in protection, some have protective Zener diodes as is the case with the SCT-013-000 recommended for use in this project. If the CT is a voltage output type, it has a built-in burden resistor. Thus, it cannot be opened.

**Hardware specification:**
- Input Voltage: AC 100-240V 50/60Hz
- Measuring Range: 0.1-60A
- Current transformer: OPCT10ATL 0-60A 1000/1
- Wireless Protocol: IEEE 802.15.4 radio, Thread, Zigbee and Bluetooth 5 (LE), 2.4GHz  Wi-Fi6 (802.11 b/g/n/ax)
- CPU: ESP32-C6 series of SoCs, 32-bit RISC-V single-core microprocessor
- Memory: 320 KB ROM, 512 KB SRAM, 4 MB FLASH
- USB-C for development and updates

Firmware:
- Powered by Tasmota, an open firmware distributed under GNU GPLv3, the firmware can be upgraded via USB-C or OTA.
- To learn more and download the latest firmware, visit:
https://tasmota.github.io/docs/Power-Monitoring-Calibration
https://tasmota.github.io/docs/Commands/#power-monitoring