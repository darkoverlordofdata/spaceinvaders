#pragma once
#include "CFClass.h"
#include "CFObject.h"

typedef struct __Component* ComponentRef;
extern CFClassRef Component;

struct __Component {
    struct __CFObject obj;

} ;

typedef enum AspectTypes : unsigned int {
    AspectUnused     = 0x0000,
    AspectStatus     = 0x0001,
    AspectPosition   = 0x0002,
    AspectSprite     = 0x0004,

} AspectTypes;

typedef enum ComponentTypes : unsigned int {
    ComponentUnused     = 0,
    ComponentStatus     = 1,
    ComponentPosition   = 2,
    ComponentSprite     = 3,

} ComponentTypes;



