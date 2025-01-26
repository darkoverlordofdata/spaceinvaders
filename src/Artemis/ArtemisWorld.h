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
typedef struct __ArtemisEntitySystem* ArtemisEntitySystemRef;
typedef struct __ArtemisComponentMapper* ArtemisComponentMapperRef;

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




ArtemisEntityManagerRef ArtemisWorldGetEntityManager(ArtemisWorldRef);
ArtemisComponentManagerRef ArtemisWorldGetComponentManager(ArtemisWorldRef);
CFObjectRef ArtemisWorldSetManager(ArtemisWorldRef, CFObjectRef);
CFObjectRef ArtemisWorldGetManager(ArtemisWorldRef, CFClassRef);
void ArtemisWorldDeleteManager(ArtemisWorldRef, CFObjectRef);
double ArtemisWorldGetDelta(ArtemisWorldRef);
void ArtemisWorldSetDelta(ArtemisWorldRef, double);
void ArtemisWorldAddEntity(ArtemisWorldRef, ArtemisEntityRef);
void ArtemisWorldChangedEntity(ArtemisWorldRef, ArtemisEntityRef);
void ArtemisWorlDeleteEntity(ArtemisWorldRef, ArtemisEntityRef);
void ArtemisWorldEnable(ArtemisWorldRef, ArtemisEntityRef);
void ArtemisWorldDisable(ArtemisWorldRef, ArtemisEntityRef);
ArtemisEntityRef ArtemisWorldCreateEntity(ArtemisWorldRef, CFStringRef);
ArtemisEntityRef ArtemisWorldGetEntity(ArtemisWorldRef, int);
CFArrayRef ArtemisWorldGetSystems(ArtemisWorldRef);
ArtemisEntitySystemRef ArtemisWorldSetSystem(ArtemisWorldRef, ArtemisEntitySystemRef, bool);
void ArtemisWorldDeleteSystem(ArtemisWorldRef, ArtemisEntitySystemRef);
void ArtemisWorldNotifySystems(ArtemisWorldRef, CFObjectRef, ArtemisEntityRef);
void ArtemisWorldNotifyManagers(ArtemisWorldRef, CFObjectRef, ArtemisEntityRef);
ArtemisEntitySystemRef ArtemisWorldGetSystem(ArtemisWorldRef, CFClassRef);
void ArtemisWorldCheck(ArtemisWorldRef, CFArrayRef, CFObjectRef);
void ArtemisWorldProcess(ArtemisWorldRef);
ArtemisComponentMapperRef ArtemisWorldGetMapper(ArtemisWorldRef, CFClassRef);
void ArtemisWorldSetEntityTemplate(ArtemisWorldRef, CFStringRef, CFObjectRef);
ArtemisEntityRef ArtemisWorldCreateEntityFromTemplate(ArtemisWorldRef, CFStringRef, ...);


