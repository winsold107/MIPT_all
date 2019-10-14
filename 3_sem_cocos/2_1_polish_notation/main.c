#include <stdio.h>

// Для хранения множеств используем 16 байт
char result[8], buffer[8];

void perform(char* buf, char* res, const char c, const int* encode) {

    for (int i = 0; i < 8; ++i) {

        if (c == '&') {
            res[i] &= buf[i];
        }
        else if (c == '|') {
            res[i] = res[i] | buf[i];
        }
        else if (c == '~') {
            res[i] = ~res[i];
        }
        else if (c == '^') {
            res[i] = res[i] ^ buf[i];
        }
        else {
            int code = encode[(int)c];
            *(buf + (code / 8)) |= 1 << (code % 8);
            return;
        }
    }

    for (int j = 0; j < 8; ++j) {
        buf[j] = '\0';
    }


}

int main() {

    //////////////////////////////////////////////////////////////
    char decode[62];

    int i = 0;
    char c;

    for (c = '0'; c <= '9'; decode[i++] = c++);
    for (c = 'A'; c <= 'Z'; decode[i++] = c++);
    for (c = 'a'; c <= 'z'; decode[i++] = c++);

    int encode[256];
    for (i = 0; i < 256; encode[i++] = '\0');

    for (i = 0; i < 62; ++i) {
        encode[(int)decode[i]] = i;
    }

    //////////////////////////////////////////////////////////////

    for (i = 0; i < 8; ++i) {
        result[i] = '\0';
        buffer[i] = '\0';
    }

    while ((i = getchar()) != EOF) {
        perform(buffer, result, i, encode);
    }

    int j;
    for (i = 0; i < 8; ++i) {
        for (j = 0; (i == 7) ? (j < 6) : (j < 8); j++) {

            if ((result[i] >> j) & 1) {
                c = decode[i*8+j];
                printf("%c", c);
            }
        }
    }
    return 0;
}
