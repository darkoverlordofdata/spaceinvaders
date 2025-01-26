#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
 * The entity class. Cannot be instantiated outside the framework, you must
 * create new entities using World.
 * 
 * @author Arni Arent
 * 
 */
typedef struct __ArtemisEntity* ArtemisEntityRef;
extern CFClassRef ArtemisEntity;

typedef struct __ArtemisWorld* ArtemisWorldRef;
typedef struct __ArtemisEntityManager* ArtemisEntityManagerRef;
typedef struct __ArtemisComponentManager* ArtemisComponentManagerRef;
typedef struct __ArtemisComponentType* ArtemisComponentTypeRef;

struct __ArtemisEntity {
    struct __CFObject           obj;
    CFStringRef                 uuid;
    CFStringRef                 name;
    int                         id;
    CFBitVectorRef              componentBits;
    CFBitVectorRef              systemBits;
    ArtemisWorldRef             world;
    ArtemisEntityManagerRef     entityManager;
    ArtemisComponentManagerRef  componenetManager;
};

int ArtemisEntityGetId(ArtemisEntityRef);
CFBitVectorRef ArtemisEntityGetComponentBits(ArtemisEntityRef);
CFBitVectorRef ArtemisEntityGetSystemBits(ArtemisEntityRef);
void ArtemisEntityReset(ArtemisEntityRef);
CFObjectRef ArtemisEntityCreateComponent(ArtemisEntityRef, CFClassRef, ...);
ArtemisEntityRef ArtemisEntityAddComponent(ArtemisEntityRef, CFObjectRef, ...);
ArtemisComponentTypeRef ArtemisEntityGetTypeFor(ArtemisEntityRef, CFObjectRef);

ArtemisEntityRef ArtemisEntityRemoveComponentInstance(ArtemisEntityRef, CFObjectRef);
ArtemisEntityRef ArtemisEntityRemoveComponent(ArtemisEntityRef, ArtemisComponentTypeRef);
ArtemisEntityRef ArtemisEntityRemoveComponentByType(ArtemisEntityRef, CFClassRef);
bool ArtemisEntityIsActive(ArtemisEntityRef);
bool ArtemisEntityIsEnabled(ArtemisEntityRef);
CFObjectRef ArtemisEntityGetComponent(ArtemisEntityRef, ArtemisComponentTypeRef);
CFObjectRef ArtemisEntityGetComponentByType(ArtemisEntityRef, CFClassRef);
CFArrayRef ArtemisEntityGetComponents(ArtemisEntityRef, CFArrayRef);
void ArtemisEntityAddToWorld(ArtemisEntityRef);
void ArtemisEntityDeleteFromWorld(ArtemisEntityRef);
void ArtemisEntityEnable(ArtemisEntityRef);
void ArtemisEntityDisable(ArtemisEntityRef);
CFStringRef ArtemisEntityGetUUID(ArtemisEntityRef);
ArtemisWorldRef ArtemisEntityGetWorld(ArtemisEntityRef);


