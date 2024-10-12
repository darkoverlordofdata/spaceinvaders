#pragma once
#include "corefw.h" // IWYU pragma: keep

typedef struct __Position* PositionRef;
extern CFClassRef Position;

struct __Position {
    struct __CFObject obj;
    long    x;
    long    y;

} ;
