#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
* 
*/
typedef struct __ArtemisComponentPool* ArtemisComponentPoolRef;
extern CFClassRef ArtemisComponentPool;

struct __ArtemisComponentPool {
    struct __CFObject           obj;
    CFArrayRef                  pools;
};



