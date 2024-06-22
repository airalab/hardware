sed -i 's/define BL0940_PREF                 1430/define BL0940_PREF                 600/g' ../tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino
sed -i 's/define BL0940_UREF                 33000/define BL0940_UREF                 14437/g' ../tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino
sed -i 's/define BL0940_IREF                 275000/define BL0940_IREF                 266013/g' ../tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino
sed -i 's/define BL09XX_WRITE_COMMAND        0xA0/define BL09XX_WRITE_COMMAND        0xA8/g' ../tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino
sed -i 's/define BL09XX_READ_COMMAND         0x50/define BL09XX_READ_COMMAND         0x58/g' ../tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino
