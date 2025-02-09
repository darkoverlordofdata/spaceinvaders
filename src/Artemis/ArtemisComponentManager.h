#pragma once
#include "../corefw.h" // IWYU pragma: keep
#include "ArtemisManager.h"

/**
* @class ArtemisComponentManager
*/
extern CFClassRef ArtemisComponentManager;

typedef struct __ArtemisWorld*                  ArtemisWorldRef;
typedef struct __ArtemisComponentPool*          ArtemisComponentPoolRef;
typedef struct __ArtemisComponentTypeFactory*   ArtemisComponentTypeFactoryRef;


struct __ArtemisComponentManager {
    struct __ArtemisManager     base;
    // struct __CFObject                   obj;
    // ArtemisWorldRef                     world;
    CFBagRef                            componentsByType;
    ArtemisComponentPoolRef             pooledComponents;
    CFBagRef                            deleted;
    ArtemisComponentTypeFactoryRef      typeFactory;
};

typedef struct __ArtemisComponentManager*       ArtemisComponentManagerRef;
typedef struct __ArtemisComponentTypeFactory*   ArtemisComponentTypeFactoryRef;
typedef struct __ArtemisComponentPool*          ArtemisComponentPoolRef;
typedef struct __ArtemisEntity*                 ArtemisEntityRef;
typedef struct __ArtemisComponentType*          ArtemisComponentTypeRef;
typedef struct __ArtemisWorld*                  ArtemisWorldRef;

void ArtemisComponentManagerInitialize(ArtemisComponentManagerRef);
CFObjectRef ArtemisComponentManagerCreate(ArtemisComponentManagerRef, ArtemisEntityRef, CFClassRef);
CFObjectRef ArtemisComponentManagerNewInstance(ArtemisComponentManagerRef, CFClassRef, bool);
void ArtemisComponentManagerAddComponent(ArtemisComponentManagerRef, ArtemisEntityRef, ArtemisComponentTypeRef, CFObjectRef);
void ArtemisComponentManagerRemoveComponent(ArtemisComponentManagerRef, ArtemisEntityRef, ArtemisComponentTypeRef);
void ArtemisComponentManagerRemoveComponentsOfEntity(ArtemisComponentManagerRef, ArtemisEntityRef);
CFBagRef ArtemisComponentManagerGetComponentsByType(ArtemisComponentManagerRef, ArtemisComponentTypeRef);
CFObjectRef ArtemisComponentManagerGetComponent(ArtemisComponentManagerRef, ArtemisEntityRef, ArtemisComponentTypeRef);
CFBagRef ArtemisComponentManagerGetComponentsFor(ArtemisComponentManagerRef, ArtemisEntityRef, CFBagRef);
void ArtemisComponentManagerClean(ArtemisComponentManagerRef);
ArtemisComponentTypeFactoryRef ArtemisComponentManagerGetTypeFactory(ArtemisComponentManagerRef);
void ArtemisComponentManagerSetWorld(ArtemisComponentManagerRef, ArtemisWorldRef);

static void ArtemisComponentManagerAdded(ArtemisManagerRef ptr, ArtemisEntityRef e)
{
    (void*)ptr;
    (void*)e;
}

static void ArtemisComponentManagerChanged(ArtemisManagerRef ptr, ArtemisEntityRef e)
{
    (void*)ptr;
    (void*)e;
}
static void ArtemisComponentManagerEnabled(ArtemisManagerRef ptr, ArtemisEntityRef e)
{
    (void*)ptr;
    (void*)e;
}
static void ArtemisComponentManagerDisabled(ArtemisManagerRef ptr, ArtemisEntityRef e)
{
    (void*)ptr;
    (void*)e;
}

static void ArtemisComponentManagerDeleted(ArtemisManagerRef ptr, ArtemisEntityRef e)
{
    ArtemisComponentManagerRef this = (ArtemisComponentManagerRef)ptr;
    CFBagAdd(this->deleted, e);
}
