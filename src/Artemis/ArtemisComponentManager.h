#pragma once
#include "../corefw.h" // IWYU pragma: keep
#include "ArtemisAspect.h"
#include "ArtemisComponentMapper.h"
#include "ArtemisEntity.h"
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


CFObjectRef ArtemisComponentManagerCreate(ArtemisComponentManagerRef, ArtemisEntityRef, CFClassRef);
CFObjectRef ArtemisComponentManagerNewInstance(ArtemisComponentManagerRef, CFClassRef, ArtemisWorldRef);
void ArtemisComponentManagerAddComponent(ArtemisComponentManagerRef, ArtemisEntityRef, ArtemisComponentTypeRef, CFObjectRef);
void ArtemisComponentManagerRemoveComponent(ArtemisComponentManagerRef, ArtemisEntityRef, ArtemisComponentTypeRef);
CFArrayRef ArtemisComponentManagerGetComponentsByType(ArtemisComponentManagerRef, ArtemisComponentTypeRef);
CFObjectRef ArtemisComponentManagerGetComponent(ArtemisComponentManagerRef, ArtemisEntityRef, ArtemisComponentTypeRef);
CFArrayRef ArtemisComponentManagerGetComponentsFor(ArtemisComponentManagerRef, ArtemisEntityRef, CFArrayRef);
