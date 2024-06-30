#include <stdbool.h>
#include "Component.h"



static bool
ctor(void *ptr, va_list args)
{
	(void)args;
	ComponentRef this = ptr;
	return true;
}

static struct __CFClass class = {
	.name = "Component",
	.size = sizeof(struct __Component),
	.ctor = ctor,
	// .equal = equal,
	// .hash = hash,
	// .copy = copy
};
CFClassRef Component = &class;

