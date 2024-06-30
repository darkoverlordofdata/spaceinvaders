#pragma once
#include "CFClass.h"
#include "CFObject.h"

typedef struct __Position* PositionRef;
extern CFClassRef Position;

struct __Position {
    struct __CFObject obj;
    long    x;
    long    y;

} ;
