#pragma once
#include "../corefw.h" // IWYU pragma: keep
#include "ArtemisComponentMapper.h"
/**
* 
*/
typedef struct __ArtemisComponentPool* ArtemisComponentPoolRef;
extern CFClassRef ArtemisComponentPool;

struct __ArtemisComponentPool {
    struct __CFObject           obj;
    CFArrayRef                  pools;
};



CFObjectRef ArtemisComponentPoolObtain(ArtemisComponentPoolRef, CFClassRef, ArtemisComponentTypeRef);
void ArtemisComponentPoolFree(ArtemisComponentPoolRef, CFObjectRef, ArtemisComponentTypeRef);
void ArtemisComponentPoolFreeByIndex(ArtemisComponentPoolRef, CFObjectRef, int typeIndex);