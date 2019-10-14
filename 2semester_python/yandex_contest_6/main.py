import re
import random


def prepare_to_british_scientists(text, letters_to_shuffle_nm):
    result = re.findall(r"[\w']"
                        r"+|[\s,./?<>}\]{[!@'#№$;%^&:*()\"+=_\-\\|`~1234567890]", text)
    for i in range(len(result)-1):
        if re.match(r"[\w]", result[i]):
            if len(result[i])-2 < letters_to_shuffle_nm:
                res = list(str(result[i][1:len(result[i])-1]))
                random.shuffle(res)
            else:
                res = list(str(result[i][1:letters_to_shuffle_nm+1]))
                ost = list(str(result[i][letters_to_shuffle_nm+1:len(result[i])-1]))
                random.shuffle(res)
                res = res + ost
            ans = str(result[i][0] + ''.join(res))
            print(ans + result[i][-1], end='')
        else:
            print(result[i], end='')
    print("\n", end='')

