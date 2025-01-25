#pragma once
#include "../corefw.h" // IWYU pragma: keep
#include "../Entity.h"
/**
* 
*/
typedef struct __ArtemisComponentManager* ArtemisComponentManagerRef;
extern CFClassRef ArtemisComponentManager;

struct __ArtemisComponentManager {
    struct __CFObject obj;
    CFArrayRef      componentsByType;
    CFObjectRef     pooledComponents;
    CFArrayRef      deleted;
    CFObjectRef     typeFactory;
};




