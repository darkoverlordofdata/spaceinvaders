#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
* 
*/
typedef struct __ArtemisComponentPool* ArtemisComponentPoolRef;
extern CFClassRef ArtemisComponentPool;

typedef struct __ArtemisComponentType* ArtemisComponentTypeRef;

struct __ArtemisComponentPool {
    struct __CFObject           obj;
    CFArrayRef                  pools;
};



CFObjectRef ArtemisComponentPoolObtain(ArtemisComponentPoolRef, CFClassRef, ArtemisComponentTypeRef);
void ArtemisComponentPoolFree(ArtemisComponentPoolRef, CFObjectRef, ArtemisComponentTypeRef);
void ArtemisComponentPoolFreeByIndex(ArtemisComponentPoolRef, CFObjectRef, int typeIndex);