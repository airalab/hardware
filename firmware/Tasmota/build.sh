#!/bin/bash

if hash platformio 2>/dev/null; then
	echo "  platformio already installed"
else
	echo "  platformio not installed, installing it now"
	pip install -U pip setuptools platformio
fi

if [ -d "Tasmota" ]; then
	echo "Directory Tasmota already installed"
else
	echo "Directory does exist. Cloning source from github."
	git clone https://github.com/arendst/Tasmota.git
fi

if patch -R -p1 -s -f --dry-run < patch/xnrg_14_bl09xx.diff; then
        echo "Tasmota xnrg_14_bl09xx already patched"
else
        echo "Patching xnrg_14_bl09xx module"
	patch -p1 < patch/xnrg_14_bl09xx.diff
fi

if [ -f Tasmota/tasmota/user_config_override.h ]; then
        echo "File user_config_override.h already exists"
else
        echo "Copy user_config_override.h "
	ln -s ../../user_config_override.h Tasmota/tasmota/user_config_override.h
#	cp user_config_override.h Tasmota/tasmota/user_config_override.h
fi

if [ -f Tasmota/platformio_tasmota_cenv.ini ]; then
        echo "File platformio_tasmota_cenv.ini already exists"
else
        echo "Copy platformio_tasmota_cenv.ini "
	ln -s ../platformio_tasmota_cenv.ini Tasmota/platformio_tasmota_cenv.ini
#        cp platformio_tasmota_cenv.ini Tasmota/platformio_tasmota_cenv.ini
fi

pio run -e em-esp32s3 -e es-sds-esp8266 -e ir-esp32 -e ir-esp32c6 -e sws-1g-e-esp32 -e sws-2g-e-esp32 -d ./Tasmota/
