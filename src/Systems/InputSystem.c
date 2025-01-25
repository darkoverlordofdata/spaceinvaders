#include "InputSystem.h"

static bool
ctor(void *ptr, va_list args)
{
	(void)args;
	InputSystemRef this = ptr;
	return true;
}

void InputSystem_ProcessEach(InputSystemRef this, EntityRef e)
{
	(void)this;
	(void)e;
}

void InputSystem_ProcessEntities(InputSystemRef this, CFArrayRef entities)
{
	(void)this;
	(void)entities;

}

bool InputSystem_CheckProcessing(InputSystemRef this)
{
	(void)this;
    return true;
}
