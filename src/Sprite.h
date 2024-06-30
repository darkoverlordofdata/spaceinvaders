#pragma once
#include "CFClass.h"
#include "CFObject.h"

typedef struct __Sprite* SpriteRef;
extern CFClassRef Sprite;

struct __Sprite {
    struct __CFObject obj;
    uint32_t width;
    uint32_t height;
    uint32_t flags;
    uint16_t colors;
    uint8_t  *data;

} ;

