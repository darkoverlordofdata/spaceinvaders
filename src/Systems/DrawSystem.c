#include "DrawSystem.h"

static bool
ctor(void *ptr, va_list args)
{
	(void)args;
	DrawSystemRef this = ptr;
	return true;
}

void DrawSystem_ProcessEach(DrawSystemRef this, EntityRef e)
{
	(void)this;
    if (EntityIsAlive(e)) {
        EntityDraw(e);
    }

}

void DrawSystem_ProcessEntities(DrawSystemRef this, CFArrayRef entities)
{
    for (ulong index=0; index < CFArraySize(entities); index++) {
        EntityRef e = CFArrayGet(entities, index);
        DrawSystem_ProcessEach(this, e);
    }
}

bool DrawSystem_CheckProcessing(DrawSystemRef this)
{
	(void)this;
    return true;
}
