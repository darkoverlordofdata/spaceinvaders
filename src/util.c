#include <stdint.h>

uint32_t clamp(uint32_t value, uint32_t lower, uint32_t upper) {
    if (value < lower) return lower;
    if (value > upper) return upper;
    return value;
}
