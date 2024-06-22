import re 
from fileinput import FileInput 
def replacetext(search_text,replace_text): 
    with open('./tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino','r+') as f: 
        file = f.read() 
        file = re.sub(search_text, replace_text, file) 
        f.seek(0) 
        f.write(file) 
        f.truncate() 
    return "Text replaced"
print(replacetext("define BL0940_PREF                 1430", "define BL0940_PREF                 600")) 
print(replacetext("define BL0940_UREF                 33000", "define BL0940_UREF                 14437")) 
print(replacetext("define BL0940_IREF                 275000", "define BL0940_IREF                 266013")) 
print(replacetext("define BL09XX_WRITE_COMMAND        0xA0", "define BL09XX_WRITE_COMMAND        0xA8")) 
print(replacetext("define BL09XX_READ_COMMAND         0x50", "define BL09XX_READ_COMMAND         0x58")) 
