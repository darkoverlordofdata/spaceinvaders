#include "CollisionSystem.h"

const int _XTimerReset           = 5;
const int _XDirectionTimerReset  = _XTimerReset * 29;

static bool
ctor(void *ptr, va_list args)
{
	(void)args;
	CollisionSystemRef this = ptr;
    this->xTimer = _XTimerReset;
    this->xChangeDirectionTimer = _XDirectionTimerReset;

    this->xMovement = 1;
    this->yMovement = 1;
	return true;
}

void CollisionSystem_ProcessEach(CollisionSystemRef this, EntityRef e)
{
    (void)this;
    (void)e;

}

void CollisionSystem_ProcessEntities(CollisionSystemRef this, CFArrayRef entities)
{
    for (ulong index=0; index < CFArraySize(entities); index++) {
        EntityRef e = CFArrayGet(entities, index);
        CollisionSystem_ProcessEach(this, e);
    }
}

bool CollisionSystem_CheckProcessing(CollisionSystemRef this)
{
    (void)this;
    return true;
}
