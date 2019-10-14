import string
import re



# def strings(filename, min_str_len=4):
#
#     # regexp = bytes('[' + string.printable + ']{' + str(min_str_len) + ',}', encoding='utf-8')
#
#     with open(filename, mode='rb') as f:
#         found_str = ""
#         while True:
#             data = f.read(60000000)
#             if not data:
#                 break
#             for char in data:
#                 if chr(char) in string.printable:
#                     found_str += chr(char)
#                 elif len(found_str) >= min_str_len:
#                     yield found_str
#                     found_str = ""
#                 else:
#                     found_str = ""
#
#
# for s in strings('in.bin'):
#     print(s)

# import subprocess

# args = ("bin/bar", "-c", "somefile.xml", "-d", "text.txt", "-r", "aString", "-f", "anotherString")
# Or just:
# args = "bin/bar -c somefile.xml -d text.txt -r aString -f anotherString".split()
# popen = subprocess.Popen("in.bin", stdout=subprocess.PIPE)
# popen.wait()
# output = popen.stdout.read()
# print(output)

        #
        #
        # while True:
        #     sym = f.read(256)
        #
        #     if len(sym) == 0:
        #         if len(result) >= min_str_len:
        #             yield result
        #         return
        #
        #     for i in sym:
        #         if i in bytes(string.printable, encoding='utf-8'):
        #             result += chr(i)
        #         else:
        #             if len(result) >= min_str_len:
        #                 yield result
        #             result = ''


import re
import string


def strings(filename, min_str_len=4):

    chars = string.printable

    regexp = bytes('[' + chars + ']{' + str(min_str_len) + ',}', encoding='utf-8')
    pattern = re.compile(regexp)

    def process(stream):
        data = stream.read()
        return pattern.findall(data)

    f = open(filename, mode='rb')

    for found_str in process(f):
        yield found_str.decode('utf-8')


for x in strings('in.bin'):
    print(x)