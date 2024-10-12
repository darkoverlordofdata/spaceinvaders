#include "Systems.h"

static bool
ctor(void *ptr, va_list args)
{
	(void)args;
	InputSystemRef sprite = ptr;
	return true;
}



static struct __CFClass class = {
	.name = "InputSystem",
	.size = sizeof(struct __InputSystem),
	.ctor = ctor,
	// .equal = equal,
	// .hash = hash,
	// .copy = copy
};
CFClassRef InputSystem = &class;

