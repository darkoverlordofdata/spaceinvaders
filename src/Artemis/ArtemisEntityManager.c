#include "../artemis.h"
#include "ArtemisComponentManager.h"
#include "ArtemisIdentifierPool.h"
/**
 *
 */
struct __ArtemisEntityManager {
    struct __CFObject           obj;
    ArtemisWorldRef             world;
    CFArrayRef                  entities;
    CFBitVectorRef              disabled;
    ulong                         active;
    ulong                         added;
    ulong                         created;
    ulong                         deleted;
    ArtemisIdentifierPoolRef    identifierPool;

};

static bool ctor(void *ptr, va_list args)
{
    (void*)args;
    ArtemisEntityManagerRef this = ptr;

    this->entities = CFCreate(CFArray, NULL);
    this->disabled = CFCreate(CFBitVector);
    this->identifierPool = CFCreate(ArtemisIdentifierPool);
    this->active = 0;
    this->added = 0;
    this->created = 0;
    this->deleted = 0;
    return true;
}

ArtemisEntityRef ArtemisEntityManagerCreateEntityInstance(ArtemisEntityManagerRef this, CFStringRef name)
{
    ArtemisEntityRef e = CFCreate(ArtemisEntity, ArtemisIdentifierPoolCheckOut(this->identifierPool), name);
    this->created++;
    return e;
}

void ArtemisEntityManagerAdded(ArtemisEntityManagerRef this, ArtemisEntityRef e)
{ 
    this->active++;
    this->added++;
    CFArraySet(this->entities, ArtemisEntityGetId(e), e);
}

void ArtemisEntityManagerEnabled(ArtemisEntityManagerRef this, ArtemisEntityRef e)
{ 
    CFBitVectorSetBitAtIndex(this->disabled, ArtemisEntityGetId(e), false);
}

void ArtemisEntityManagerDisabled(ArtemisEntityManagerRef this, ArtemisEntityRef e)
{ 
    CFBitVectorSetBitAtIndex(this->disabled, ArtemisEntityGetId(e), true);
}

void ArtemisEntityManagerDeleted(ArtemisEntityManagerRef this, ArtemisEntityRef e)
{
    CFArraySet(this->entities, ArtemisEntityGetId(e), NULL);
    CFBitVectorSetBitAtIndex(this->disabled, ArtemisEntityGetId(e), false);
    ArtemisIdentifierPoolCheckIn(this->identifierPool, ArtemisEntityGetId(e));
    this->active--;
    this->deleted++;
}

/**
 * Check if this entity is active.
 * Active means the entity is being actively processed.
 * 
 * @param entityId
 * @return true if active, false if not.
 */
bool ArtemisEntityManagerIsActive(ArtemisEntityManagerRef this, ulong id)
{ 
    return (CFArrayGet(this->entities, id) != NULL);
}

/**
 * Check if the specified entityId is enabled.
 * 
 * @param entityId
 * @return true if the entity is enabled, false if it is disabled.
 */
bool ArtemisEntityManagerIsEnabled(ArtemisEntityManagerRef this, ulong entityId)
{ 
    return CFBitVectorGetBitAtIndex(this->disabled, entityId);
}

/**
 * Get a entity with this id.
 * 
 * @param entityId
 * @return the entity
 */
ArtemisEntityRef ArtemisEntityManageGetEntity(ArtemisEntityManagerRef this, ulong entityId)
{
    return CFArrayGet(this->entities, entityId);
}

/**
 * Get how many entities are active in this world.
 * @return how many entities are currently active.
 */
ulong ArtemisEntityManageGetActiveEntityCount(ArtemisEntityManagerRef this)
{ 
    return this->active;
}

/**
 * Get how many entities have been created in the world since start.
 * Note: A created entity may not have been added to the world, thus
 * created count is always equal or larger than added count.
 * @return how many entities have been created since start.
 */
ulong ArtemisEntityManageGetTotalCreated(ArtemisEntityManagerRef this)
{
    return this->created; 
}

/**
 * Get how many entities have been added to the world since start.
 * @return how many entities have been added.
 */
ulong ArtemisEntityManageGetTotalAdded(ArtemisEntityManagerRef this)
{
    return this->added;
}

/**
 * Get how many entities have been deleted from the world since start.
 * @return how many entities have been deleted since start.
 */
ulong ArtemisEntityManageGetTotalDeleted(ArtemisEntityManagerRef this)
{ 
    return this->deleted;
}




static struct __CFClass class = {
    .name = "ArtemisEntityManager",
    .size = sizeof(struct __ArtemisEntityManager),
    .ctor = ctor,
};
CFClassRef ArtemisEntityManager = &class;
