#include "MovementSystem.h"

static bool
ctor(void *ptr, va_list args)
{
	(void)args;
	MovementSystemRef this = ptr;
	return true;
}

void MovementSystem_ProcessEach(MovementSystemRef this, EntityRef e)
{
	(void)this;
    if (EntityIsAlive(e)) {
        UInt32 x1 = EntityX(e);
        long y1 = (long)EntityY(e) - 4;

        if (y1 < 0) {
            EntitySetAlive(e, false);
        }
        EntitySetPos(e, x1, (UInt32)y1);
    }

}

void MovementSystem_ProcessEntities(MovementSystemRef this, CFArrayRef entities)
{
    for (ulong index=0; index < CFArraySize(entities); index++) {
        EntityRef e = CFArrayGet(entities, index);
        MovementSystem_ProcessEach(this, e);
    }
}

bool MovementSystem_CheckProcessing(MovementSystemRef this)
{
	(void)this;
    return true;
}
