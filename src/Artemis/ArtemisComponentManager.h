#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
* 
*/
typedef struct __ArtemisComponentManager* ArtemisComponentManagerRef;
extern CFClassRef ArtemisComponentManager;

typedef struct __ArtemisComponentTypeFactory* ArtemisComponentTypeFactoryRef;
typedef struct __ArtemisComponentPool* ArtemisComponentPoolRef;

struct __ArtemisComponentManager {
    struct __CFObject obj;
    CFArrayRef                          componentsByType;
    ArtemisComponentPoolRef             pooledComponents;
    CFArrayRef                          deleted;
    ArtemisComponentTypeFactoryRef      typeFactory;
};




