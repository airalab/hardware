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

  #define PROJECT                "robonomics"

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

  #ifdef FIRMWARE_EM-ESP32S3
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: EM-ESP32S3 ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "EM-ESP32S3"

    #undef USER_TEMPLATE
    #define USER_TEMPLATE "{\"NAME\":\"Robonomics-Energy-Monitor\",\"GPIO\":[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3200,5440,1,1,576,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":1, \"CMND\":\"SetOption21 1|WattRes 2|VoltRes 2\"}"

  #endif

  #ifdef FIRMWARE_ES-SDS-ESP8266
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
  #ifdef FIRMWARE_IR-ESP32
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: IR-ESP32 ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "IR-ESP32"

    #undef USER_TEMPLATE
    #define USER_TEMPLATE "{\"NAME\":\"Robonomics IR remote\",\"GPIO\":[1,1,1,1,1056,1088,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,1],\"FLAG\":0,\"BASE\":1}"

  #endif

  #ifdef FIRMWARE_IR-ESP32C6
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: IR-ESP32C6 ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "SWS-1G-E-ESP32"

//    #undef USER_TEMPLATE
//    #define USER_TEMPLATE "{\"NAME\":\"Generic\",\"GPIO\":[1,1,1,1,1,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":18}"  // [Template] Set JSON template

  #endif

  #ifdef FIRMWARE_SWS-1G-E-ESP32
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

  #ifdef FIRMWARE_SWS-2G-E-ESP32
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

#endif  // _USER_CONFIG_OVERRIDE_H_
