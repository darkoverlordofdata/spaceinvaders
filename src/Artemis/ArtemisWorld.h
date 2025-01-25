#pragma once
#include "../corefw.h" // IWYU pragma: keep
#include "../Entity.h"
/**
* The primary instance for the framework. It contains all the managers.
* 
* You must use this to create, delete and retrieve entities.
* 
* It is also important to set the delta each game loop iteration, and initialize before game loop.
* 
* @author Arni Arent
* 
*/
typedef struct __ArtemisWorld* ArtemisWorldRef;
extern CFClassRef ArtemisWorld;

struct __ArtemisWorld {
    struct __CFObject obj;
    float       delta;
    CFMapRef    managers;
    CFMapRef    systems;
    CFArrayRef  added;
    CFArrayRef  changed;
    CFArrayRef  deleted;
    CFArrayRef  enable;
    CFArrayRef  disable;
    CFObjectRef em;
    CFObjectRef cm;
};



EntityRef ArtemisWorldCreateEntity(ArtemisWorldRef);

