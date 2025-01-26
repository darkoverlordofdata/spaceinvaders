#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
* 
*/
extern CFClassRef ArtemisComponentManager;

typedef struct __ArtemisComponentManager*       ArtemisComponentManagerRef;
typedef struct __ArtemisComponentTypeFactory*   ArtemisComponentTypeFactoryRef;
typedef struct __ArtemisComponentPool*          ArtemisComponentPoolRef;
typedef struct __ArtemisEntity*                 ArtemisEntityRef;
typedef struct __ArtemisComponentType*          ArtemisComponentTypeRef;


CFObjectRef ArtemisComponentManagerCreate(ArtemisComponentManagerRef, ArtemisEntityRef, CFClassRef);
CFObjectRef ArtemisComponentManagerNewInstance(ArtemisComponentManagerRef, CFClassRef, bool);
void ArtemisComponentManagerAddComponent(ArtemisComponentManagerRef, ArtemisEntityRef, ArtemisComponentTypeRef, CFObjectRef);
void ArtemisComponentManagerRemoveComponent(ArtemisComponentManagerRef, ArtemisEntityRef, ArtemisComponentTypeRef);
void ArtemisComponentManagerRemoveComponentsOfEntity(ArtemisComponentManagerRef, ArtemisEntityRef);
CFArrayRef ArtemisComponentManagerGetComponentsByType(ArtemisComponentManagerRef, ArtemisComponentTypeRef);
CFObjectRef ArtemisComponentManagerGetComponent(ArtemisComponentManagerRef, ArtemisEntityRef, ArtemisComponentTypeRef);
CFArrayRef ArtemisComponentManagerGetComponentsFor(ArtemisComponentManagerRef, ArtemisEntityRef, CFArrayRef);
void ArtemisComponentManagerDeleted(ArtemisComponentManagerRef, ArtemisEntityRef);
void ArtemisComponentManagerClean(ArtemisComponentManagerRef);