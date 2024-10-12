#include <stdbool.h>
#include "Sprite.h"
#include "corefw.h"

static bool
ctor(void *ptr, va_list args)
{
	SpriteRef sprite = ptr;

	sprite->width = (UInt32)va_arg(args, long);
	sprite->height = (UInt32)va_arg(args, long);
	sprite->flags = (UInt32)va_arg(args, long);
    sprite->colors = (UInt16)va_arg(args, long);
    sprite->data = (UInt8*)va_arg(args, void*);


	return true;
}



static struct __CFClass class = {
	.name = "Sprite",
	.size = sizeof(struct __Sprite),
	.ctor = ctor,
	// .equal = equal,
	// .hash = hash,
	// .copy = copy
};
CFClassRef Sprite = &class;

