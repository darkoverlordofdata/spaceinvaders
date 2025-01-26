#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
 * The most raw entity system. It should not typically be used, but you can create your own
 * entity system handling by extending this. It is recommended that you use the other provided
 * entity system implementations.
 * 
 * @author Arni Arent
 *
 */
typedef struct __ArtemisEntitySystem* ArtemisEntitySystemRef;
extern CFClassRef ArtemisEntitySystem;

typedef struct __ArtemisWorld* ArtemisWorldRef;
typedef struct __ArtemisAspect* ArtemisAspectRef;
typedef struct __ArtemisEntity* ArtemisEntityRef;


struct __ArtemisEntitySystem {
    struct __CFObject   obj;
    int                 systemIndex;  
    ArtemisWorldRef     world;
    CFArrayRef          actives;
    ArtemisAspectRef    aspect;
    CFBitVectorRef      allSet;
    CFBitVectorRef      exclusionSet;
    CFBitVectorRef      oneSet;
    bool                passive;
    bool                dummy;
};


void ArtemisEntitySystemBegin(ArtemisEntitySystemRef);
void ArtemisEntitySystemProcess(ArtemisEntitySystemRef);
void ArtemisEntitySystemEnd(ArtemisEntitySystemRef);
void ArtemisEntitySystemProcessEntities(ArtemisEntitySystemRef, CFArrayRef);
bool ArtemisEntitySystemCheckProcessing(ArtemisEntitySystemRef);
void ArtemisEntitySystemInitialize(ArtemisEntitySystemRef);
void ArtemisEntitySystemInserted(ArtemisEntitySystemRef, ArtemisEntityRef);
void ArtemisEntitySystemRemoved(ArtemisEntitySystemRef, ArtemisEntityRef);
void ArtemisEntitySystemCheck(ArtemisEntitySystemRef, ArtemisEntityRef);
void ArtemisEntitySystemRemoveFromSystem(ArtemisEntitySystemRef, ArtemisEntityRef);
void ArtemisEntitySystemInsertToSystem(ArtemisEntitySystemRef, ArtemisEntityRef);
void ArtemisEntitySystemAdded(ArtemisEntitySystemRef, ArtemisEntityRef);
void ArtemisEntitySystemChanged(ArtemisEntitySystemRef, ArtemisEntityRef);
void ArtemisEntitySystemDeleted(ArtemisEntitySystemRef, ArtemisEntityRef);
void ArtemisEntitySystemDisabled(ArtemisEntitySystemRef, ArtemisEntityRef);
void ArtemisEntitySystemEnabled(ArtemisEntitySystemRef, ArtemisEntityRef);
void ArtemisEntitySystemSetWorld(ArtemisEntitySystemRef, ArtemisWorldRef);
bool ArtemisEntitySystemIsPassive(ArtemisEntitySystemRef);
void ArtemisEntitySystemSetPassive(ArtemisEntitySystemRef, bool);
CFArrayRef ArtemisEntitySystemGetActive(ArtemisEntitySystemRef)


