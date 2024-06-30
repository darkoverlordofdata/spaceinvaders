#include <stdbool.h>
#include "Status.h"


static bool
ctor(void *ptr, va_list args)
{
	StatusRef this = ptr;
    this->alive = va_arg(args, long);
	this->id = (CategoryEntity)va_arg(args, long);
	return true;
}

static struct __CFClass class = {
	.name = "Status",
	.size = sizeof(struct __Status),
	.ctor = ctor,
	// .equal = equal,
	// .hash = hash,
	// .copy = copy
};
CFClassRef Status = &class;

