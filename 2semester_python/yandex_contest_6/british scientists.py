import re
import random
import string


def prepare_to_british_scientists(text, letters_to_shuffle_nm):
    if isinstance(text, str):
        printage = ''
        result = re.findall(r"[\w']"
                            r"+|[\s,./?<>}\]{[!@'#№$;%^&:*()\"+=_\-\\|`~1234567890]", text)
        for i in range(len(result)):
            if (i == len(result) - 1) and (result[i] == '\n'):
                continue
            elif re.match(r"[\w]", result[i]):
                if len(result[i]) - 2 < letters_to_shuffle_nm:
                    res = list(str(result[i][1:len(result[i]) - 1]))
                    random.shuffle(res)
                else:
                    res = list(str(result[i][1:letters_to_shuffle_nm + 1]))
                    ost = list(str(result[i][letters_to_shuffle_nm + 1:len(result[i]) - 1]))
                    random.shuffle(res)
                    res = res + ost
                ans = str(result[i][0] + ''.join(res))
                if len(result[i]) == 1:
                    printage = printage + ans
                else:
                    printage = printage + ans + result[i][-1]
            else:
                printage = printage + result[i]
        if (printage == text) and (letters_to_shuffle_nm != 0) and (letters_to_shuffle_nm != 1):
            printage = ''
            for i in range(len(result)):
                if (i == len(result) - 1) and (result[i] == '\n'):
                    continue
                elif re.match(r"[\w]", result[i]):
                    if (len(result[i]) == 4) and \
                            ((letters_to_shuffle_nm != 0) or (letters_to_shuffle_nm != 1)):
                        res = list(str(result[i][1:len(result[i]) - 1]))
                        res.reverse()
                    elif len(result[i]) - 2 < letters_to_shuffle_nm:
                        res = list(str(result[i][1:len(result[i]) - 1]))
                        random.shuffle(res)
                    else:
                        res = list(str(result[i][1:letters_to_shuffle_nm + 1]))
                        ost = list(str(result[i][letters_to_shuffle_nm + 1:len(result[i]) - 1]))
                        random.shuffle(res)
                        res = res + ost
                    ans = str(result[i][0] + ''.join(res))
                    if len(result[i]) == 1:
                        printage = printage + ans
                    else:
                        printage = printage + ans + result[i][-1]
                else:
                    printage = printage + result[i]
        return printage
    # else:
    #     printage = ''
    #     for line in text:
    #         if str(line) != '\n':
    #             result = re.findall(r"[\w']"
    #                                 r"+|[\s,./?<>}\]{[!@'#№$;%^&:*()\"+=_\-\\|`~1234567890]", line)
    #             for i in range(len(result)-1):
    #                 if re.match(r"[\w]", result[i]):
    #                     if len(result[i])-2 < letters_to_shuffle_nm:
    #                         res = list(str(result[i][1:len(result[i])-1]))
    #                         random.shuffle(res)
    #                     else:
    #                         res = list(str(result[i][1:letters_to_shuffle_nm+1]))
    #                         ost = list(str(result[i][letters_to_shuffle_nm+1:len(result[i])-1]))
    #                         random.shuffle(res)
    #                         res = res + ost
    #                     ans = str(result[i][0] + ''.join(res))
    #                     printage = printage + ans + result[i][-1]
    #                     # print(ans + result[i][-1], end='')
    #                 else:
    #                     printage = printage + result[i]
    #                     # print(result[i], end='')
    #             # print("\n", end='')
    #         else:
    #             printage = printage
    #             # print('')
    #         printage = printage + '\n'
    #     return printage


print(prepare_to_british_scientists('ohHhhh my PytHon 3! like it :)', 5))
# print('')
# f = open('input.txt')
# for line in f:
#     print(prepare_to_british_scientists(line, 5))
# # print(prepare_to_british_scientists(f, 5))
# f.close()

# TODO хз как работает Make, отвергает задачу RE(1)
