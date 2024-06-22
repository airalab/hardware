sed -i 's/define BL0940_PREF                 600/define BL0940_PREF                 1430/g' ../tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino
sed -i 's/define BL0940_UREF                 14437/define BL0940_UREF                 33000/g' ../tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino
sed -i 's/define BL0940_IREF                 266013 /define BL0940_IREF                 275000/g' ../tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino
sed -i 's/define BL09XX_WRITE_COMMAND        0xA8/define BL09XX_WRITE_COMMAND        0xA0/g' ../tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino
sed -i 's/define BL09XX_READ_COMMAND         0x58/define BL09XX_READ_COMMAND         0x50/g' ../tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino
