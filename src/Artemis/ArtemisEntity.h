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




