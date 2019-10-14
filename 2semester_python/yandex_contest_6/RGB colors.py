import math
import re
import sys


def sys16(num, to_base=10, from_base=16):
    if isinstance(num, str):
        n = int(num, from_base)
    else:
        n = int(num)
    alphabet = "0123456789abcdefghijklmnopqrstuvwxyz"
    if n < to_base:
        return alphabet[n]
    else:
        return sys16(n // to_base, to_base) + alphabet[n % to_base]


def percnum(num):
    num = float(num)/100*255
    return str(math.floor(num))


def rgb(string, result):
    if "%" in string:
        for i in range(len(result)):
            result[i] = percnum(result[i])
    if (0 <= int(result[0]) <= 255) and (0 <= int(result[1]) <= 255)\
            and (0 <= int(result[0]) <= 255):
        if "rgb" in string:
            print(str(result[0]) + " " + str(result[1]) + " " + str(result[2]))
        if "rbg" in string:
            print(str(result[0]) + " " + str(result[2]) + " " + str(result[1]))
        if "grb" in string:
            print(str(result[1]) + " " + str(result[0]) + " " + str(result[2]))
        if "gbr" in string:
            print(str(result[2]) + " " + str(result[0]) + " " + str(result[1]))
        if "brg" in string:
            print(str(result[1]) + " " + str(result[2]) + " " + str(result[0]))
        if "bgr" in string:
            print(str(result[2]) + " " + str(result[1]) + " " + str(result[0]))
    else:
        print("ERROR")


string = str(input())
string.split()
string = ' '.join(string.split())
m1 = ""
m2 = ""
m3 = ""
if re.match(r'#', string):
    string = string.replace(' ', '')
    k = 0
    for i in range(len(string)):
        if string[i] in "0123456789abcdef":
            k += 1
    if k == 6:
        m3 = str(string[5]+string[6])
        m2 = str(string[3]+string[4])
        m1 = str(string[1]+string[2])
        print(sys16(m1), sys16(m2), sys16(m3))
    else:
        print("ERROR")
else:
    l = len(string)
    integ = []
    i = 0
    while i < l:
        s_int = ''
        a = string[i]
        while '0' <= a <= '9':
            s_int += a
            i += 1
            if i < l:
                a = string[i]
            else:
                break
        i += 1
        if s_int != '':
            integ.append(int(s_int))
    res = integ
    if len(res) != 3:
        print("ERROR")
        sys.exit()
    elif (re.match(r'[r,g,b]', string)) and\
            ((re.match(r"\s?\w{3}\s?\(\s?\d{1,3}\s?,"
                       r"\s?\d{1,3}\s?,\s?\d{1,3}\s?\)\s?", string)) or
             (re.match(r"\s?\w{3}\s?\(\s?\d{1,3}\s?%\s?,"
                       r"\s?\d{1,3}\s?%\s?,\s?\d{1,3}\s?%\s?\)\s?", string))):
        rgb(string, res)
    elif re.match(r"\s?\d{1,3}\s?,\s?\d{1,3}\s?,\s?\d{1,3}\s?", string):
        print(string)
    else:
        print("ERROR")
