#include "util.h"

UInt32 clamp(UInt32 value, UInt32 lower, UInt32 upper) {
    if (value < lower) return lower;
    if (value > upper) return upper;
    return value;
}
