
## Principal Scheme of the Citizen Station "Altruist"

The development of the **Citizen station "Altruist"** is based on the following key components:

### **Power Supply Block**

The power supply block is built on the [SY50282](https://github.com/airalab/hardware/blob/main/Altruist/ESP32C3/Docs/Datasheets/SY50282FAC_C178237.pdf) microchip, which is a PWM controller. It provides both current and voltage regulation, managing the Buck converter in a quasi-resonant mode to achieve high efficiency and better EMI performance.

**Power Safety:**
- The AC voltage passes through a fuse and a 07D471K varistor. If the voltage suddenly exceeds 385 V, the varistor triggers, disconnecting the circuit to prevent damage.
- The scheme also includes a DC-DC linear converter that reduces the power from 5 V to 3.3 V for connection via USB Type-C and from the AC-DC power supply.

> [!WARNING]
> ## **Important**
>
> **The power supply circuit is not isolated, so it is forbidden to touch the device when connected to the AC power grid. It is also prohibited to connect the device via the Type-C port to a PC without a special isolating device to avoid damaging the PC and electrical shock.**
> **Please study the [educational materials](https://resources.altium.com/p/isolated-vs-non-isolated-power-supplies-right-choice-without-fail) on the topic of power sources.**

### **Microprocessor**

The ESP32-C3 series of SoCs from Espressif Systems is used as the processor. The [ESP32-C3-MINI-1-N4](https://github.com/airalab/hardware/blob/main/Altruist/ESP32C3/Docs/Datasheets/ESP32-C3-MINI-1_N4_C2838502.pdf) module is applied, which supports 2.4 GHz Wi-Fi (IEEE 802.11b/g/n) and Bluetooth 5. There is a button on the board to switch the microcontroller into programming mode.

**Module Advantages:**
- No additional impedance matching calculations are required for the antenna.
- The USB Type-C port can be used directly for programming and debugging firmware thanks to the built-in USB Serial/JTAG controller.

### **Indication**

Two LED indicators are installed on the printed circuit board:
- One indicates the presence of 5 V power from the AC-DC converter.
- The other indicates the presence of 3.3 V power after the linear voltage regulator for powering the ESP32C3 and external sensors.

### **Connectors for Sensor Connection**

The board has connectors for connecting various sensors:
- **XH2.54-5P**: For the [SDS011]((https://github.com/airalab/hardware/blob/main/Altruist/ESP32C3/Docs/Datasheets/SDS011-DATASHEET.pdf)) particulate sensor.
- **HY2.0-4P**: For the [BME280](https://github.com/airalab/hardware/blob/main/Altruist/ESP32C3/Docs/Datasheets/BME280_C92489.pdf) temperature, humidity, and pressure sensor.
- **ZH1.5-5**: For the [ICS-43434](https://github.com/airalab/hardware/blob/main/Altruist/ESP32C3/Docs/Datasheets/ICS-43434_C5656610.pdf) noise sensor.
- **XH-4**: For the [RadSens](https://github.com/climateguard/RadSens/blob/master/extras/datasheets/RadSens_datasheet_ENG.pdf) radiation sensor.
- **SH1.0-4P**: For the [BN220](https://github.com/airalab/hardware/blob/main/Altruist/ESP32C3/Docs/Datasheets/BN-220%20GPS%2BAntenna%20datasheet.pdf) GPS.

---
