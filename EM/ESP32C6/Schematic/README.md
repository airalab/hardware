**HW version: Robo-EM-ESP32C RC3**
## The Basis for Developing the Principal Scheme of Energy Monitoring

The following components form the basis for developing the principal scheme of energy monitoring:

## Power Supply Block

The power supply block of the device is built on the KP1505X chip series. These are high-performance and cost-effective power switches with PWM control, suitable for autonomous step-down devices of low power, with simple peripheral circuits and a small number of components. The device features a built-in high-voltage MOSFET to enhance system resilience against voltage spikes.Unlike traditional PWM controllers, the KP1505X does not have an internal fixed clock generator for MOSFET control, and the switching frequency can automatically adjust based on load changes. The chip uses multi-mode PWM control technology, which simplifies peripheral circuit design, improves linear regulation speed and load regulation speed, and eliminates audible noise during operation. Additionally, the chip's internal peak current detection threshold can automatically adjust according to actual load conditions, effectively reducing energy consumption in standby mode under no-load conditions.The KP1505X integrates a full set of protection functions with self-recovery: undervoltage protection VDD, cycle-by-cycle current limiting, output overvoltage protection, overheat protection, overload protection, VDD overvoltage protection, etc.To enhance power safety, the KP15051SPA scheme includes a 100-ohm limiting startup current resistor. The AC voltage enters through a fuse parallel to which a 07D471K varistor is installed. This scheme causes the varistor to activate if the voltage suddenly increases above 385 volts, leading to the fuse blowing and disconnecting the entire circuit from very high voltage that could cause severe damage or fire.The scheme also includes a DC-DC linear converter used to reduce power from both the USB Type-C port and the AC-DC power supply, lowering the supply voltage from 5 volts to 3.3 volts.**WARNING!** The power supply circuit is not isolated, so it is forbidden to touch the device when it is connected to AC power to prevent electric shock. It is also forbidden to connect the device via the Type-C port to a PC without a special isolating device, as this could damage your PC and cause electric shock.

## Energy Monitoring Scheme

In this project, the BL0940 chip is connected to the ESP32C6 via a UART interface. Using a separate chip for energy metering allows redistributing computational load to a cost-effective specialized chip, freeing more computational power for specific functions, such as connecting to a web3 cloud.The BL0940 features a built-in clock generator and is a calibration-free energy metering chip suitable for single-phase multifunctional energy meters, smart sockets, smart home appliances, charging stakes for electric bicycles, and other applications with excellent cost-performance characteristics.The BL0940 integrates two high-precision sigma-delta ADCs for simultaneous measurement of current and voltage. It can measure electrical parameters such as RMS current and voltage, active power, active energy, RMS fast current (for overload protection), and temperature, as well as display signal waveform, etc. The BL0940 outputs data via UART or SPI interfaces.The BL0940 has a patented anti-crypt design that can be combined with intelligent external hardware design to ensure that noise energy cannot be calculated in the energy pulse when there is no load.According to the documentation, the following formulas are used to calculate calibration values based on the components used in the chip's circuitry. These values are necessary for correctly calculating energy consumption parameters in the software code responsible for calculations:

- IREF=324004×(R1(Ω)×1000)Rt×1VrefIREF​=324004×Rt(R1(Ω)×1000)​×Vref​1​
- UREF=79931×R2(kΩ)×1000Vref×R3(kΩ)UREF​=Vref​×R3(kΩ)79931×R2(kΩ)×1000​
- PREF=4046×(R1(Ω)×1000)Rt×R2(kΩ)×1000Vref×Vref×R3(kΩ)PREF​=Vref​×Vref​×R3(kΩ)4046×Rt(R1(Ω)×1000)​×R2(kΩ)×1000​
- IREF=324004×(1×1000)1000×11.218IREF​=324004×1000(1×1000)​×1.2181​
- UREF=79931×0.022×10001.218×(20×5)UREF​=1.218×(20×5)79931×0.022×1000​
- PREF=4046×(1×1000)1000×0.022×10001.218×1.218×(20×5)PREF​=1.218×1.218×(20×5)4046×1000(1×1000)​×0.022×1000​
- IREF=266013IREF​=266013
- UREF=14437UREF​=14437
- PREF=600PREF​=600

The scheme is designed to work with a current transformer. In this project, the affordable and cost-effective OPCT10ATL 0-60A 1000/1 current transformer is used. Using a current transformer allows the device to be connected to the electrical network non-invasively, which also enhances operational safety.

## Microprocessor

The ESP32-C6 series of SoCs, a 32-bit RISC-V single-core microprocessor from Espressif Systems, was chosen as the processor. The ESP32-C6-MINI-1-N4 module is used in the scheme. This is a very simple and fast solution for creating custom developments because you do not need to perform additional impedance matching calculations, and during PCB production, you do not need to install additional requirements for production and impedance control. The main advantages of this SoC include its multiprotocol connectivity. It supports 2.4 GHz Wi-Fi 6 (IEEE 802.11b/g/n/ax), Bluetooth 5 (LE), Zigbee 3.0, and Thread 1.3 (802.15.4). On the PCB, the module is placed according to all design recommendations for placement on the PCB.For programming mode, a button labeled “Boot mode” is installed next to the module. To start the microcontroller in “Boot mode,” press the button before connecting the cable to the Type-C port. Another way to enter without disconnecting the cable from Type-C is to press the “Boot mode” button and, while holding it, press the “Reset” button. The microcontroller will reboot and start in firmware loading mode.

<img src="Img/info.png" width="500px"></a>

## Advantages of USB Connection

Thanks to the built-in USB Serial/JTAG controller in the SoC, the USB Type-C port can be connected directly to the microcontroller, allowing the elimination of an additional USB to UART converter. Additionally, due to the built-in JTAG controller, this port can be used for firmware debugging.

## Indication

On the PCB, there are two LED indicators. On the top layer of the PCB, there is an LED indicator for the presence of 3.3 volts necessary for powering the ESP32C6 and BL0940. It is located next to the “Reset” button. On the bottom layer of the PCB, a “Link” LED indicator is installed, connected to GPIO22 of the ESP32C6. This indicator can be programmed for various tasks, but in its basic representation, it is used to indicate the presence of a connection and errors in network connections.

## Temperature and Humidity Sensor

An external temperature and humidity sensor AHT20, operating via the I2C bus, has been added to the scheme. This sensor is not expensive and requires a very small number of additional electronic components. The presence of this sensor allows for precise control over the operating conditions of the device in the electrical panel. Data from this sensor can be additionally saved in the smart home history or web3 cloud. Also, in one of the application scenarios for this sensor, emergency notifications can be organized for a sudden increase in temperature not only inside the device's casing but also inside the installed electrical panel, which may indicate a serious problem in your power distribution node.