#include <stdbool.h>
#include "Position.h"


static bool
ctor(void *ptr, va_list args)
{
	PositionRef this = ptr;
    this->x = va_arg(args, long);
    this->y = va_arg(args, long);
	return true;
}

static struct __CFClass class = {
	.name = "Position",
	.size = sizeof(struct __Position),
	.ctor = ctor,
	// .equal = equal,
	// .hash = hash,
	// .copy = copy
};
CFClassRef Position = &class;

