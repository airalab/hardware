#!/usr/bin/env python3
import time
import subprocess
import sys
import os
from serial.tools import list_ports

def play_sound(success=True):
    """Издает звук через системный динамик или alsa-utils."""
    try:
        if success:
            # Короткий высокий звук (через стандартный beep, если есть)
            os.system('echo -e "\a" > /dev/console 2>/dev/null || echo -e "\a"')
            # Альтернатива через aplay (если есть аудио-выход)
            # os.system('speaker-test -t sine -f 1000 -l 1 > /dev/null 2>&1')
        else:
            # Два коротких звука для ошибки
            for _ in range(2):
                os.system('echo -e "\a" > /dev/console 2>/dev/null || echo -e "\a"')
                time.sleep(0.2)
    except:
        pass

def flash_device(port, firmware):
    print(f"\n[+] Найдено устройство на {port}. Шью...")
    
    # Для ESP32-C3 используем esptool.py
    # Параметр --before default_reset --after hard_reset важен для конвейера
    cmd = [
        "esptool", 
        "--chip", "esp32c3", 
        "--port", port, 
        "--baud", "460800", 
        "write-flash", "0x0", firmware
    ]
    
    result = subprocess.run(cmd)
    
    if result.returncode == 0:
        print(f"[*] УСПЕХ: {port} готов.")
        play_sound(success=True)
    else:
        print(f"[!] ОШИБКА: Проблема с портом {port}.")
        play_sound(success=False)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Использование: python script.py <путь_к_бинарнику>")
        sys.exit(1)

    firmware_path = sys.argv[1]
    if not os.path.exists(firmware_path):
        print(f"Файл не найден: {firmware_path}")
        sys.exit(1)

    print(f"--- Конвейер Tasmota запущен (Linux/NixOS) ---")
    print(f"Прошивка: {firmware_path}")
    
    # Начальное состояние портов
    known_ports = set([p.device for p in list_ports.comports()])

    while True:
        current_ports = set([p.device for p in list_ports.comports()])
        new_ports = current_ports - known_ports
        
        for port in new_ports:
            flash_device(port, firmware_path)
            # После прошивки добавляем порт в исключения, 
            # чтобы не шить его снова, пока не переткнули
            known_ports.add(port)
        
        # Если порт исчез (выткнули), удаляем его из списка известных
        known_ports = known_ports.intersection(current_ports)
        
        time.sleep(0.5)
