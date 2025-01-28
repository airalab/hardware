
/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent ch	anged online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/


/******************************************************************************************************\
disable all
\******************************************************************************************************/
#ifdef CODE_IMAGE_STR
  #undef CODE_IMAGE_STR
#endif

#ifdef USE_ENERGY_SENSOR
  #undef USE_ENERGY_SENSOR
#endif

#ifdef USE_MHZ19
  #undef USE_MHZ19
#endif

#ifdef USE_SENSEAIR
  #undef USE_SENSEAIR
#endif

#ifdef USE_PMS5003
  #undef USE_PMS5003
#endif

#ifdef USE_MGS
  #undef USE_MGS
#endif

#ifdef USE_NOVA_SDS
  #undef USE_NOVA_SDS
#endif

#ifdef USE_SGP30
  #undef USE_SGP30
#endif

#ifdef USE_CCS811
  #undef USE_CCS811
#endif

#ifdef USE_SCD30
  #undef USE_SCD30
#endif

#ifdef USE_SPS30
  #undef USE_SPS30
#endif

#ifdef USE_SEN5X
  #undef USE_SEN5X
#endif

#ifdef USE_HPMA
  #undef USE_HPMA
#endif

#ifdef USE_IAQ
  #undef USE_IAQ
#endif

#ifdef USE_T67XX
  #undef USE_T67XX
#endif

#ifdef USE_VINDRIKTNING
  #undef USE_VINDRIKTNING
#endif

#ifdef USE_SCD40
  #undef USE_SCD40
#endif

#ifdef USE_HM330X
  #undef USE_HM330X
#endif

#ifdef USE_EMULATION
  #undef USE_EMULATION
#endif

#ifdef USE_EMULATION_HUE
  #undef USE_EMULATION_HUE
#endif

#ifdef USE_EMULATION_WEMO
  #undef USE_EMULATION_WEMO
#endif

#ifdef USE_TASMOTA_CLIENT
  #undef USE_TASMOTA_CLIENT
#endif

#ifdef USE_BERRY
  #undef USE_BERRY
#endif
#define USE_BERRY

#ifdef USE_BERRY_PSRAM
  #undef USE_BERRY_PSRAM
#endif
#define USE_BERRY_PSRAM

#ifdef USE_BLE_ESP32
  #undef USE_BLE_ESP32
#endif

#ifdef USE_MI_ESP32
  #undef USE_MI_ESP32
#endif

#ifdef USE_ADC_VCC
  #undef USE_ADC_VCC
#endif

#ifdef USE_DISPLAY
  #undef USE_DISPLAY
#endif

#ifdef USE_DISPLAY_MODES1TO5
  #undef USE_DISPLAY_MODES1TO5
#endif

#ifdef USE_DISPLAY_LCD
  #undef USE_DISPLAY_LCD
#endif

#ifdef USE_DISPLAY_SSD1306
  #undef USE_DISPLAY_SSD1306
#endif

#ifdef USE_DISPLAY_MATRIX
  #undef USE_DISPLAY_MATRIX
#endif

#ifdef USE_DISPLAY_ILI9341
  #undef USE_DISPLAY_ILI9341
#endif

#ifdef USE_DISPLAY_EPAPER_29
  #undef USE_DISPLAY_EPAPER_29
#endif

#ifdef USE_DISPLAY_EPAPER_42
  #undef USE_DISPLAY_EPAPER_42
#endif

#ifdef USE_DISPLAY_SH1106
  #undef USE_DISPLAY_SH1106
#endif

#ifdef USE_DISPLAY_ILI9488
  #undef USE_DISPLAY_ILI9488
#endif

#ifdef USE_DISPLAY_SSD1351
  #undef USE_DISPLAY_SSD1351
#endif

#ifdef USE_DISPLAY_RA8876
  #undef USE_DISPLAY_RA8876
#endif

#ifdef USE_DISPLAY_SEVENSEG
  #undef USE_DISPLAY_SEVENSEG
#endif

#ifdef USE_DISPLAY_ST7789
  #undef USE_DISPLAY_ST7789
#endif

#ifdef USE_DISPLAY_SSD1331
  #undef USE_DISPLAY_SSD1331
#endif

#ifdef USE_SR04
  #undef USE_SR04
#endif

#ifdef USE_VL53L0X
  #undef USE_VL53L0X
#endif

#ifdef USE_HRXL
  #undef USE_HRXL
#endif

#ifdef USE_DYP
  #undef USE_DYP
#endif

#ifdef USE_VL53L1X
  #undef USE_VL53L1X
#endif

#ifdef USE_DOMOTICZ
  #undef USE_DOMOTICZ
#endif

#ifdef USE_HLW8012
  #undef USE_HLW8012
#endif

#ifdef USE_CSE7766
  #undef USE_CSE7766
#endif

#ifdef USE_PZEM004T
  #undef USE_PZEM004T
#endif

#ifdef USE_MCP39F501
  #undef USE_MCP39F501
#endif

#ifdef USE_PZEM_AC
  #undef USE_PZEM_AC
#endif

#ifdef USE_PZEM_DC
  #undef USE_PZEM_DC
#endif

#ifdef USE_ADE7953
  #undef USE_ADE7953
#endif

#ifdef USE_SDM120
  #undef USE_SDM120
#endif

#ifdef USE_DDS2382
  #undef USE_DDS2382
#endif

#ifdef USE_SDM630
  #undef USE_SDM630
#endif

#ifdef USE_DDSU666
  #undef USE_DDSU666
#endif

#ifdef USE_SOLAX_X1
  #undef USE_SOLAX_X1
#endif

#ifdef USE_LE01MR
  #undef USE_LE01MR
#endif

#ifdef USE_BL09XX
  #undef USE_BL09XX
#endif

#ifdef USE_TELEINFO
  #undef USE_TELEINFO
#endif

#ifdef USE_IEM3000
  #undef USE_IEM3000
#endif

#ifdef USE_WE517
  #undef USE_WE517
#endif

#ifdef USE_ENERGY_DUMMY
  #undef USE_ENERGY_DUMMY
#endif

#ifdef USE_ETHERNET
  #undef USE_ETHERNET
#endif

#ifdef USE_HOME_ASSISTANT
  #undef USE_HOME_ASSISTANT
#endif
  #define USE_HOME_ASSISTANT

#ifdef USE_I2C
  #undef USE_I2C
#endif

#ifdef USE_MCP230xx
  #undef USE_MCP230xx
#endif

#ifdef USE_MCP230xx_OUTPUT
  #undef USE_MCP230xx_OUTPUT
#endif

#ifdef USE_MCP230xx_DISPLAYOUTPUT
  #undef USE_MCP230xx_DISPLAYOUTPUT
#endif

#ifdef USE_IR_REMOTE
  #undef USE_IR_REMOTE
#endif

#ifdef USE_IR_REMOTE_FULL
  #undef USE_IR_REMOTE_FULL
#endif

#ifdef USE_KNX
  #undef USE_KNX
#endif

#ifdef USE_BH1750
  #undef USE_BH1750
#endif

#ifdef USE_VEML6070
  #undef USE_VEML6070
#endif

#ifdef USE_TSL2561
  #undef USE_TSL2561
#endif

#ifdef USE_SI1145
  #undef USE_SI1145
#endif

#ifdef USE_APDS9960
  #undef USE_APDS9960
#endif

#ifdef USE_VEML6075
  #undef USE_VEML6075
#endif

#ifdef USE_MAX44009
  #undef USE_MAX44009
#endif

#ifdef USE_TSL2591
  #undef USE_TSL2591
#endif

#ifdef USE_AS3935
  #undef USE_AS3935
#endif

#ifdef USE_VEML7700
  #undef USE_VEML7700
#endif

#ifdef USE_DISCOVERY
  #undef USE_DISCOVERY
#endif

#ifdef USE_MODBUSBRIDGE
  #undef USE_MODBUSBRIDGE
#endif

#ifdef USE_MODBUSBRIDGE_TCP
  #undef USE_MODBUSBRIDGE_TCP
#endif

#ifdef USE_MQTT_TLS
  #undef USE_MQTT_TLS
#endif

#ifdef USE_RC_SWITCH
  #undef USE_RC_SWITCH
#endif

#ifdef USE_RULES
  #undef USE_RULES
#endif

#ifdef USE_EXPRESSION
  #undef USE_EXPRESSION
#endif

#ifdef SUPPORT_IF_STATEMENT
  #undef SUPPORT_IF_STATEMENT
#endif

#ifdef USE_SCRIPT
  #undef USE_SCRIPT
#endif

#ifdef USE_UFILESYS
  #undef USE_UFILESYS
#endif

#ifdef USE_SDCARD
  #undef USE_SDCARD
#endif

#ifdef GUI_TRASH_FILE
  #undef GUI_TRASH_FILE
#endif

#ifdef GUI_EDIT_FILE
  #undef GUI_EDIT_FILE
#endif

#ifdef USE_SHUTTER
  #undef USE_SHUTTER
#endif

#ifdef USE_SPI
  #undef USE_SPI
#endif

#ifdef USE_SONOFF_SC
  #undef USE_SONOFF_SC
#endif

#ifdef USE_DS18x20
  #undef USE_DS18x20
#endif

#ifdef USE_DHT
  #undef USE_DHT
#endif

#ifdef USE_SHT
  #undef USE_SHT
#endif

#ifdef USE_HTU
  #undef USE_HTU
#endif

#ifdef USE_BMP
  #undef USE_BMP
#endif

#ifdef USE_SHT3X
  #undef USE_SHT3X
#endif

#ifdef USE_LM75AD
  #undef USE_LM75AD
#endif

#ifdef USE_AZ7798
  #undef USE_AZ7798
#endif

#ifdef USE_MAX31855
  #undef USE_MAX31855
#endif

#ifdef USE_MLX90614
  #undef USE_MLX90614
#endif

#ifdef USE_MAX31865
  #undef USE_MAX31865
#endif

#ifdef USE_HIH6
  #undef USE_HIH6
#endif

#ifdef USE_DHT12
  #undef USE_DHT12
#endif

#ifdef USE_DS1624
  #undef USE_DS1624
#endif

#ifdef USE_AHT1x
  #undef USE_AHT1x
#endif

#ifdef USE_HDC1080
  #undef USE_HDC1080
#endif

#ifdef USE_MCP9808
  #undef USE_MCP9808
#endif

#ifdef USE_HP303B
  #undef USE_HP303B
#endif

#ifdef USE_LMT01
  #undef USE_LMT01
#endif

#ifdef USE_AM2320
  #undef USE_AM2320
#endif

#ifdef USE_BME68X
  #undef USE_BME68X
#endif
#define USE_BME68X

#ifdef USE_TIMERS
  #undef USE_TIMERS
#endif

#ifdef USE_TUYA_MCU
  #undef USE_TUYA_MCU
#endif

#ifdef USE_WEBSERVER
  #undef USE_WEBSERVER
#endif
#define USE_WEBSERVER

#ifdef USE_WS2812
  #undef USE_WS2812
#endif

#ifdef USE_ZIGBEE
  #undef USE_ZIGBEE
#endif

#ifdef USE_WEBCAM
  #undef USE_WEBCAM
#endif

#ifdef USE_TASMOTA_DISCOVERY
  #undef USE_TASMOTA_DISCOVERY
#endif

#ifdef ENABLE_RTSPSERVER
  #undef ENABLE_RTSPSERVER
#endif

#ifdef USE_MI_ESP32
  #undef USE_MI_ESP32
#endif

#ifdef CAMERA_MODEL_AI_THINKER
  #undef CAMERA_MODEL_AI_THINKER
#endif




  #ifdef PROJECT
  #undef PROJECT
  #endif
  #define PROJECT                "robonomics"

  #ifdef USE_DISPLAY
  #undef USE_DISPLAY
  #endif

  #ifdef _UDISP_
  #undef _UDISP_
  #endif

  #ifdef USE_DOMOTICZ
  #undef USE_DOMOTICZ                           // Disable Domoticz support
  #endif

  #ifdef USE_KNX_WEB_MENU
  #undef USE_KNX_WEB_MENU                      // Disable KNX support
  #endif

  #ifdef MODULE
  #undef MODULE
  #endif
  #define MODULE                 USER_MODULE   // [Module] Select default model (the list is kModuleNiceList() in file tasmota_template.h) USER_MODULE is the TEMPLATE

  #ifdef FALLBACK_MODULE
  #undef FALLBACK_MODULE
  #endif
  #define FALLBACK_MODULE        USER_MODULE   // to Select the default model as FALLBACK when the user does a RESET 1 

  #ifdef USER_TEMPLATE
  #undef USER_TEMPLATE
  #endif

  #ifdef FIRMWARE_EM_ESP32S3
  #warning **** Build: EM-ESP32S3 ****
    #ifdef CODE_IMAGE_STR
      #undef CODE_IMAGE_STR
    #endif
    #define CODE_IMAGE_STR "EM-ESP32S3"

    #undef DEVICE_NAME
    #define DEVICE_NAME "EM-ESP32S3"
    #undef FRIENDLY_NAME
    #define FRIENDLY_NAME "Robonomics energy monitor"

    #undef WIFI_CONFIG_TOOL
    #define WIFI_CONFIG_TOOL       WIFI_MANAGER
    #undef USE_ENHANCED_GUI_WIFI_SCAN
    #undef USE_TIMERS_WEB

    #define USE_ENERGY_SENSOR
    #define USE_BL09XX

      #define BL0940_PREF 600
      #define BL0940_UREF 14437
      #define BL0940_IREF 266013

      #define BL09XX_WRITE_COMMAND 0xA8
      #define BL09XX_READ_COMMAND 0x58

    #ifdef MODULE
    #undef MODULE
    #endif
    #define MODULE                 USER_MODULE   // [Module] Select default model (the list is kModuleNiceList() in file tasmota_template.h) USER_MODULE is the TEMPLATE

    #ifdef FALLBACK_MODULE
    #undef FALLBACK_MODULE
    #endif
    #define FALLBACK_MODULE        USER_MODULE   // to Select the default model as FALLBACK when the user does a RESET 1 

    #undef USER_TEMPLATE
    #define USER_TEMPLATE "{\"NAME\":\"Robonomics-Energy-Monitor\",\"GPIO\":[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3200,5440,1,1,576,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":1, \"CMND\":\"SetOption21 1|WattRes 2|VoltRes 2\"}"

  #endif

  #ifdef FIRMWARE_EM_ESP32C6
  #warning **** Build: EM-ESP32C6 ****
    #ifdef CODE_IMAGE_STR
    #undef CODE_IMAGE_STR
    #endif
    #define CODE_IMAGE_STR "EM-ESP32C6"

    #undef DEVICE_NAME
    #define DEVICE_NAME "EM-ESP32C6"
    #undef FRIENDLY_NAME
    #define FRIENDLY_NAME "Robonomics energy monitor"

    #undef USE_ENHANCED_GUI_WIFI_SCAN
    #undef USE_TIMERS_WEB

    #define USE_ENERGY_SENSOR
    #define USE_BL09XX

      #define BL0940_PREF 600
      #define BL0940_UREF 14437
      #define BL0940_IREF 266013

      #define BL09XX_WRITE_COMMAND 0xA8
      #define BL09XX_READ_COMMAND 0x58

    #define USE_I2C
    #undef USE_WE517
    #undef USE_SHT
    #undef USE_VEML6070 // UV sensor with conflicting I2C address
    #undef USE_AHT1x
    #undef USE_AHT2x
    #define USE_AHT2x

    #ifdef MODULE
    #undef MODULE
    #endif
    #define MODULE                 USER_MODULE   // [Module] Select default model (the list is kModuleNiceList() in file tasmota_template.h) USER_MODULE is the TEMPLATE

    #ifdef FALLBACK_MODULE
    #undef FALLBACK_MODULE
    #endif
    #define FALLBACK_MODULE        USER_MODULE   // to Select the default model as FALLBACK when the user does a RESET 1 

    #undef USER_TEMPLATE
    #define USER_TEMPLATE "{\"NAME\":\"Robonomics-Energy-Monitor\",\"GPIO\":[1,1,1,7552,3200,5440,640,608,1,1,1,1,1,1,1,1,1,1,1,1,1,1,576,1,0,0,0,0,0,0,0],\"FLAG\":0,\"BASE\":1, \"CMND\":\"SetOption21 1|WattRes 2|VoltRes 2\"}"

  #endif

  #ifdef FIRMWARE_ES_SDS_ESP8266
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: ES-SDS-ESP8266 ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "ES-SDS-ESP8266"

    #undef USER_TEMPLATE
    #define USER_TEMPLATE "{\"NAME\":\"Generic\",\"GPIO\":[1,1,1,1,1,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":18}"  // [Template] Set JSON template

  #endif

  #ifdef FIRMWARE_IR_ESP32
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: IR-ESP32 ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "IR-ESP32"

    #ifdef MODULE
    #undef MODULE
    #endif
    #define MODULE                 USER_MODULE   // [Module] Select default model (the list is kModuleNiceList() in file tasmota_template.h) USER_MODULE is the TEMPLATE

    #ifdef FALLBACK_MODULE
    #undef FALLBACK_MODULE
    #endif
    #define FALLBACK_MODULE        USER_MODULE   // to Select the default model as FALLBACK when the user does a RESET 1 

    #undef DEVICE_NAME
    #define DEVICE_NAME "IR-ESP32"
    #undef FRIENDLY_NAME
    #define FRIENDLY_NAME "Robonomics IR remote"

    // -- IR options ----------------------------
    #define USE_IR_REMOTE                            // Enable IR remote commands using library IRremoteESP8266
    #define USE_IR_REMOTE_FULL                       // Support all IR protocols from IRremoteESP8266

    #undef USER_TEMPLATE
    #define USER_TEMPLATE "{\"NAME\":\"Robonomics IR remote\",\"GPIO\":[1,1,1,1,1056,1088,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,1],\"FLAG\":0,\"BASE\":1}"

  #endif

  #ifdef FIRMWARE_IR_ESP32C6
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: IR-ESP32C6 ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef USE_GPIO_VIEWER
    #undef USE_BERRY

    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "IR-ESP32C6"

    #ifdef MODULE
    #undef MODULE
    #endif
    #define MODULE                 USER_MODULE   // [Module] Select default model (the list is kModuleNiceList() in file tasmota_template.h) USER_MODULE is the TEMPLATE

    #ifdef FALLBACK_MODULE
    #undef FALLBACK_MODULE
    #endif
    #define FALLBACK_MODULE        USER_MODULE   // to Select the default model as FALLBACK when the user does a RESET 1 

    #undef DEVICE_NAME
    #define DEVICE_NAME "IR-ESP32C6"
    #undef FRIENDLY_NAME
    #define FRIENDLY_NAME "Robonomics IR remote"
    #define FIRMWARE_IR

    // -- IR options ----------------------------
//    #define USE_IR_REMOTE                            // Enable IR remote commands using library IRremoteESP8266
    #define USE_IR_REMOTE_FULL                       // Support all IR protocols from IRremoteESP8266

    #undef USER_TEMPLATE
//    #define USER_TEMPLATE "{\"NAME\":\"Robonomics IR remote\",\"GPIO\":[1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,544,1,1056,1088,1,0,0,0,0,0,0,0,0],\"FLAG\":0,\"BASE\":1}"
    #define USER_TEMPLATE "{\"NAME\":\"Robonomics IR remote\",\"GPIO\":[1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,544,1,1056,1088,1,0,0,0,0,0,0,0,0],\"FLAG\":0,\"BASE\":1}"

  #endif

  #ifdef FIRMWARE_SWS_1G_E_ESP32
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: SWS-1G-E-ESP32 ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "SWS-1G-E-ESP32"

    #undef USER_TEMPLATE
    #define USER_TEMPLATE "{\"NAME\":\"Robonomics-1L-Switch\",\"GPIO\":[1,1,1,1,1,1,1,1,1,576,1,1,1,1,3200,5440,0,1,224,1,0,0,320,1,0,0,0,0,1,1,1,32,1,0,0,1],\"FLAG\":0,\"BASE\":1}"

  #endif

  #ifdef FIRMWARE_SWS_2G_E_ESP32
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: SWS-2G-E-ESP32 ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "SWS-2G-E-ESP32"

    #undef USER_TEMPLATE
    #define USER_TEMPLATE "{\"NAME\":\"Robonomics-2L-Switch\",\"GPIO\":[1,1,1,1,1,1,1,1,1,576,1,1,1,1,3200,5440,0,224,225,0,0,320,1,321,0,0,0,0,33,1,32,1,1,0,0,1],\"FLAG\":0,\"BASE\":1}"

  #endif

  #ifdef FIRMWARE_SWS_1G_E_ESP32C6
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: SWS-1G-E-ESP32C6 ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "SWS-1G-E-ESP32C6"

    #ifdef MODULE
    #undef MODULE
    #endif
    #define MODULE                 USER_MODULE   // [Module] Select default model (the list is kModuleNiceList() in file tasmota_template.h) USER_MODULE is the TEMPLATE

    #ifdef FALLBACK_MODULE
    #undef FALLBACK_MODULE
    #endif
    #define FALLBACK_MODULE        USER_MODULE   // to Select the default model as FALLBACK when the user does a RESET 1 

    #undef DEVICE_NAME
    #define DEVICE_NAME "SWS-1G-E-ESP32C6"
    #undef FRIENDLY_NAME
    #define FRIENDLY_NAME "Robonomics 1 gang Switch"


    #undef USER_TEMPLATE
    #define USER_TEMPLATE "{\"NAME\":\"Robonomics-1L-Switch\",\"GPIO\":[1,1,1,1,1,1,1,1,1,1,1,1,576,32,288,1,1,1,7552,1,3200,224,1,5440,0,0,0,0,0,0,0],\"FLAG\":0,\"BASE\":1}"

  #endif

  #ifdef FIRMWARE_SWS_2G_E_ESP32C6
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: SWS-2G-E-ESP32C6 ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "SWS-2G-E-ESP32C6"

    #ifdef MODULE
    #undef MODULE
    #endif
    #define MODULE                 USER_MODULE   // [Module] Select default model (the list is kModuleNiceList() in file tasmota_template.h) USER_MODULE is the TEMPLATE

    #ifdef FALLBACK_MODULE
    #undef FALLBACK_MODULE
    #endif
    #define FALLBACK_MODULE        USER_MODULE   // to Select the default model as FALLBACK when the user does a RESET 1 

    #define USE_ENERGY_SENSOR

    #undef DEVICE_NAME
    #define DEVICE_NAME "SWS-2G-E-ESP32C6"
    #undef FRIENDLY_NAME
    #define FRIENDLY_NAME "Robonomics 2 gang Switch"

    #undef USER_TEMPLATE
    #define USER_TEMPLATE "{\"NAME\":\"Robonomics-2L-Switch\",\"GPIO\":[1,32,1,1,1,1,288,1,1,1,1,1,576,1,289,33,1,1,7552,1,3200,224,225,5440,0,0,0,0,0,0,0],\"FLAG\":0,\"BASE\":1}"

  #endif

#endif  // _USER_CONFIG_OVERRIDE_H_
