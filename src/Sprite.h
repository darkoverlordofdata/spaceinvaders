#pragma once
#include "corefw.h" // IWYU pragma: keep

typedef struct __Sprite* SpriteRef;
extern CFClassRef Sprite;

struct __Sprite {
    struct __CFObject obj;
    UInt32 width;
    UInt32 height;
    UInt32 flags;
    UInt16 colors;
    UInt8  *data;

} ;

