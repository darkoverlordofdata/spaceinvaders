#pragma once
#include "../corefw.h" // IWYU pragma: keep
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

typedef struct __ArtemisEntityManager* ArtemisEntityManagerRef;
typedef struct __ArtemisComponentManager* ArtemisComponentManagerRef;
typedef struct __ArtemisEntity* ArtemisEntityRef;

struct __ArtemisWorld {
    struct __CFObject           obj;
    float                       delta;
    CFMapRef                    managers;
    CFMapRef                    systems;
    CFArrayRef                  added;
    CFArrayRef                  changed;
    CFArrayRef                  deleted;
    CFArrayRef                  enable;
    CFArrayRef                  disable;
    ArtemisEntityManagerRef     em;
    ArtemisComponentManagerRef  cm;
};



ArtemisEntityRef ArtemisWorldCreateEntity(ArtemisWorldRef);

