#pragma once
#include "../corefw.h" // IWYU pragma: keep0
/**
 *
 */
typedef struct __ArtemisEntityManager* ArtemisEntityManagerRef;
extern CFClassRef ArtemisEntityManager;

typedef struct __ArtemisWorld* ArtemisWorldRef;

struct __ArtemisEntityManager {
    struct __CFObject   obj;
    ArtemisWorldRef     world;
    CFArrayRef          entities;
    CFBitVectorRef      disabled;
    int                 active;
    int                 added;
    int                 created;
    int                 deleted;

};




