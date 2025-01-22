<a href="https://github.com/airalab/hardware" style="vertical-align: inherit;" target="_blank"><img src="https://img.shields.io/github/stars/airalab/hardware" alt="GitHub Repo Stars" class="not-medium-zoom-image" style="display: inline; vertical-align: inherit;" /></a>&nbsp;<a href="https://github.com/airalab/hardware/issues" style="vertical-align: inherit;" target="_blank"><img src="https://img.shields.io/github/issues/airalab/hardware" alt="GitHub Issues" class="not-medium-zoom-image" style="display: inline; vertical-align: inherit;" /></a>&nbsp;<a href="https://github.com/airalab/hardware" style="vertical-align: inherit;" target="_blank"><img src="https://img.shields.io/github/repo-size/airalab/hardware" alt="GitHub Repo Size" class="not-medium-zoom-image" style="display: inline; vertical-align: inherit;" /></a>&nbsp;<a href="https://github.com/airalab/hardware/blob/main/LICENSE" style="vertical-align: inherit;" target="_blank"><img src="https://img.shields.io/github/license/airalab/hardware" alt="GitHub License" class="not-medium-zoom-image" style="display: inline; vertical-align: inherit;" /></a>

## Robonomics Hardware Team

The Robonomics Hardware team is involved in developing open-source hardware.

## Devices Developed by Robonomics Hardware

The Robonomics Hardware team focuses on developing open-source hardware solutions. Below is a list of devices they have developed:


| Device Name                                    | ID (Version)      | Project Description                            | Production Files                                                                                                |
| ---------------------------------------------- | ----------------- | ---------------------------------------------- | --------------------------------------------------------------------------------------------------------------- |
| [Energy Monitoring](/EM/ESP32C6)               | EM-ESP32C6        | [Description](/EM/ESP32C6/README.md)           | [PCB](/EM/ESP32C6/PCB/README.md)                                                                                |
| [Energy Monitoring](/EM/ESP32S3)               | EM-ESP32S3        | [Description](/EM/ESP32S3/README.md)           | [PCB](/EM/ESP32S3/PCB/README.md)                                                                                |
| [Altruist Outdoor Sensor](/Altruist/README.md) | ESP32C3           | [Description](/Altruist/ESP32C3/README.md)     | [PCB](/Altruist/ESP32C3/PCB/README.md)                                                                          |
| [Altruist Outdoor Sensor](/Altruist/README.md) | ES-SDS-ESP8266-AC | [Description](/Altruist/ESP8266/AC/README.md)  | [PCB](/Altruist/ESP8266/AC/PCB/README.md)                                                                       |
| [Altruist Outdoor Sensor](/Altruist/README.md) | ES-SDS-ESP8266-DC | [Description](/Altruist/ESP8266/DC/README.md)  | [PCB](/Altruist/ESP8266/DC/PCB/README.md)                                                                       |
| [Hikikomori](/Hikikomori/ESP32C6)              | Hiki-ESP32C6      | [Description](/Hikikomori/ESP32C6/README.md)   | [PCB](/Hikikomori/ESP32C6/PCB/README.md)                                                                        |
| Universal IR Remote Control                    | IR-ESP32C6        | [Description](/IR/ESP32C6/README.md)           | [PCB](/IR/ESP32C6/PCB/README.md)                                                                                |
| Universal IR Remote Control                    | IR-ESP32          | [Description](/IR/ESP32/README.md)             | [PCB](/IR/ESP32/PCB/README.md)                                                                                  |
| Smart Switch 2 Gang                            | SWS-1G-E-ESP32    | [Description](/SWS/1G-E/ESP32/README.md)       | [Main Board](/SWS/1G-E/ESP32/PCB/Main_board/README.md) [Power Board](/SWS/2G-E/ESP32/PCB/Power_board/README.md) |
| Smart Switch 2 Gang                            | SWS-2G-E-ESP32    | [Description](/SWS/2G-E/ESP32/README.md)       | [Main Board](/SWS/2G-E/ESP32/PCB/Main_board/README.md) [Power Board](/SWS/2G-E/ESP32/PCB/Power_board/README.md) |

---

### Project Structure

```plaintext
└── ID/                             # ID device series
    └── SUB_ID/                     # SUB_ID device (if there) 
    ...
    └── CPU_ID/                     # Microcontroller name
        ...
        └── AC or DC                # Power type (if there)
            ...
            ├── Typography/         # Files for ordering printed products from a printing house
            ├── PCB/                # Files for ordering from a PCB factory
            └── Project/            # EDA projects
```
