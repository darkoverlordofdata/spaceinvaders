#pragma once
#include "../corefw.h" // IWYU pragma: keep
#include "ArtemisAspect.h"
#include "stdbool.h"
/**
 * The most raw entity system. It should not typically be used, but you can create your own
 * entity system handling by extending this. It is recommended that you use the other provided
 * entity system implementations.
 * 
 * @author Arni Arent
 *
 */
typedef struct __ArtemisEntitySystem* ArtemisEntitySystemRef;
extern CFClassRef ArtemisEntitySystem;

typedef struct __ArtemisWorld* ArtemisWorldRef;
typedef struct __ArtemisAspect* ArtemisAspectRef;

struct __ArtemisEntitySystem {
    struct __CFObject   obj;
    int                 systemIndex;  
    ArtemisWorldRef     world;
    CFArrayRef          actives;
    ArtemisAspectRef    aspect;
    CFBitVectorRef      allSet;
    CFBitVectorRef      exclusionSet;
    CFBitVectorRef      oneSet;
    bool                passive;
    bool                dummy;
};




