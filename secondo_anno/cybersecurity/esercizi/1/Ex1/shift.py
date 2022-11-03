stringa = "hello" # inserire una stringa qui
key = 2;

def shift(stringa, key):
    stringa1 = ""
    for i in range(len(stringa)):
        stringa1 += chr(ord(stringa[i]) + key) 
    return stringa1

stringa = shift(stringa, 2)
# print(stringa)
