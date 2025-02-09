#pragma once
#include "../corefw.h" // IWYU pragma: keep0
#include "ArtemisManager.h"
#include "ArtemisIdentifierPool.h"
#include "ArtemisEntity.h"
/**
 *  @class ArtemisEntityManager
 */
extern CFClassRef ArtemisEntityManager;

typedef struct __ArtemisEntityManager*  ArtemisEntityManagerRef;
typedef struct __ArtemisWorld*          ArtemisWorldRef;
typedef struct __ArtemisEntity*         ArtemisEntityRef;

struct __ArtemisEntityManager {
    struct __ArtemisManager     base;
    // struct __CFObject           obj;
    // ArtemisWorldRef             world;
    CFBagRef                    entities;
    CFBitVectorRef              disabled;
    ulong                       active;
    ulong                       added;
    ulong                       created;
    ulong                       deleted;
    ArtemisIdentifierPoolRef    identifierPool;

};


ArtemisEntityRef ArtemisEntityManagerCreateEntityInstance(ArtemisEntityManagerRef, CFStringRef);
bool ArtemisEntityManagerIsActive(ArtemisEntityManagerRef, ulong);
bool ArtemisEntityManagerIsEnaled(ArtemisEntityManagerRef, ulong);
ArtemisEntityRef ArtemisEntityManageGetEntity(ArtemisEntityManagerRef, ulong);
ulong ArtemisEntityManageGetActiveEntityCount(ArtemisEntityManagerRef);
ulong ArtemisEntityManageGetTotalCreated(ArtemisEntityManagerRef);
ulong ArtemisEntityManageGetTotalAdded(ArtemisEntityManagerRef);
ulong ArtemisEntityManageGetTotalDeleted(ArtemisEntityManagerRef);
void ArtemisEntityManageSetWorld(ArtemisEntityManagerRef, ArtemisWorldRef);



static void ArtemisEntityManagerAdded(ArtemisManagerRef ptr, ArtemisEntityRef e)
{ 
    ArtemisEntityManagerRef this = (ArtemisEntityManagerRef)ptr;
    this->active++;
    this->added++;
    CFBagSet(this->entities, ArtemisEntityGetId(e), e);
}

static void ArtemisEntityManagerChanged(ArtemisManagerRef ptr, ArtemisEntityRef e)
{
    (void*)ptr;
    (void*)e;
}

static void ArtemisEntityManagerEnabled(ArtemisManagerRef ptr, ArtemisEntityRef e)
{ 
    ArtemisEntityManagerRef this = (ArtemisEntityManagerRef)ptr;
    CFBitVectorSetBitAtIndex(this->disabled, ArtemisEntityGetId(e), false);
}

static void ArtemisEntityManagerDisabled(ArtemisManagerRef ptr, ArtemisEntityRef e)
{ 
    ArtemisEntityManagerRef this = (ArtemisEntityManagerRef)ptr;
    CFBitVectorSetBitAtIndex(this->disabled, ArtemisEntityGetId(e), true);
}

static void ArtemisEntityManagerDeleted(ArtemisManagerRef ptr, ArtemisEntityRef e)
{
    ArtemisEntityManagerRef this = (ArtemisEntityManagerRef)ptr;
    CFBagSet(this->entities, ArtemisEntityGetId(e), NULL);
    CFBitVectorSetBitAtIndex(this->disabled, ArtemisEntityGetId(e), false);
    ArtemisIdentifierPoolCheckIn(this->identifierPool, ArtemisEntityGetId(e));
    this->active--;
    this->deleted++;
}
