#include <stdint.h>

uint16_t satsum(uint16_t x, uint16_t y) {

    uint16_t s = x + y;

    if (s < x || s < y) {
        return (uint16_t)(-1);
    }

    return x + y;
}
