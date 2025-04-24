[EN](./README.md) | [RU](./README.ru.md)

To compile the firmware from the original Tasmota repository yourself, use the command
pio run -e em-esp32s3 -e es-sds-esp8266 -e ir-esp32 -e ir-esp32c6 -e sws-1g-e-esp32 -e sws-2g-e-esp32

# Robonomics Hardware Firmware Guide 
## English Version

### 1. Install ESPTool
1. Download the latest `esptool` from the [official repository](https://github.com/espressif/esptool/releases).
2. Extract the archive to a separate folder.

### 2. Download Firmware
1. Get the latest firmware for your device from [Robonomics Hardware releases](https://github.com/airalab/hardware/releases).
2. Place the firmware file (e.g., `em-esp32c6.factory.bin`) in the `esptool` folder.

### 3. Connect the Device
1. Press and hold the **Boot** button on the device.
2. Connect the device to your computer via USB-C.
3. Release the **Boot** button after connection.

### 4. Identify COM Port
- **Windows**: Use Device Manager (port will be labeled as `COMXX`, e.g., `COM3`).
- **Linux/Mac**: Run `ls /dev/tty*` to find the port (typically `/dev/ttyUSB0` or `/dev/ttyACM0`).

### 5. Erase Flash Memory
Run in the command line:
```bash
esptool.exe --port <COM_PORT> erase_flash
```
Example for COM3:
```bash
esptool.exe --port COM3 erase_flash
```

### 6. Flash the Firmware
Use the command corresponding to your device:

| Device               | Command                                                                                          |
|----------------------|--------------------------------------------------------------------------------------------------|
| Robo-EM-ESP32C6      | `esptool.exe --port <COM_PORT> --chip esp32c6 --baud 921600 write_flash 0x0 em-esp32c6.factory.bin` |
| Robo-ES-SDS-ESP8266  | `esptool.exe --port <COM_PORT> --chip esp8266 --baud 460800 write_flash 0x0 es-sds-esp8266.bin`    |
| Robo-IR-ESP32        | `esptool.exe --port <COM_PORT> --chip esp32 --baud 921600 write_flash 0x0 ir-esp32.bin`            |

### 7. Final Steps
1. Reboot the device after successful flashing.
2. Configure the device via the Tasmota web interface.

---

### Notes / Notes
- For ESP32-C6 and ESP32-S3, use `--baud 921600`. For ESP8266 use `--baud 460800`.
- If errors occur, try lowering the speed (`--baud 115200`).
- For Linux/Mac, replace `esptool.exe` with `python -m esptool`.

## Configuration

### 1. Create Script File
In the Tasmota web interface, navigate to `Tools > Manage File System` and create a new file named `/autoexec.be`.

### 2. Paste Script Content
Copy the contents from  [robonomics_send.be](https://github.com/LoSk-p/esp-robonomics-client/blob/main/examples/Tasmota_driver/robonomics_send.be) and paste it into the newly created `autoexec.be` file.

### 3. Save and Restart
Click the `Save` button. Then return to the main menu and click `Restart`. After the reboot, you should see a new button labeled `Robonomics Sending Config` in the main menu.

### 4. Configure Robonomics
You’ll find the Robonomics address of the Energy Meter at the top of the page in `Configure Robonomics` page.
To use RWS, check the `Use RWS` option and enter your `RWS Owner` address.
Make sure to add the Energy Meter’s address to the RWS devices list under your owner account.