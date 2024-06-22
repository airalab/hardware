# Importing re module 
import re 

# Importing FileInput from fileinput module 
from fileinput import FileInput 
def replacetext(search_text,replace_text): 
  
    # Opening the file in read and write mode 
    with open('./tasmota/tasmota_xnrg_energy/xnrg_14_bl09xx.ino','r+') as f: 
  
        # Reading the file data and store 
        # it in a file variable 
        file = f.read() 
          
        # Replacing the pattern with the string 
        # in the file data 
        file = re.sub(search_text, replace_text, file) 
  
        # Setting the position to the top 
        # of the page to insert data 
        f.seek(0) 
          
        # Writing replaced data in the file 
        f.write(file) 
  
        # Truncating the file size 
        f.truncate() 
  
    # Return "Text replaced" string 
    return "Text replaced"
  
print(replacetext("define BL0940_PREF                 1430", "define BL0940_PREF                 600")) 
print(replacetext("define BL0940_UREF                 33000", "define BL0940_UREF                 14437")) 
print(replacetext("define BL0940_IREF                 275000", "define BL0940_IREF                 266013")) 
print(replacetext("define BL09XX_WRITE_COMMAND        0xA0", "define BL09XX_WRITE_COMMAND        0xA8")) 
print(replacetext("define BL09XX_READ_COMMAND         0x50", "define BL09XX_READ_COMMAND         0x58")) 
