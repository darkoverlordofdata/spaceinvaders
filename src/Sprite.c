#include <stdbool.h>
#include "Sprite.h"

static bool
ctor(void *ptr, va_list args)
{
	SpriteRef sprite = ptr;

	sprite->width = (uint32_t)va_arg(args, long);
	sprite->height = (uint32_t)va_arg(args, long);
	sprite->flags = (uint32_t)va_arg(args, long);
    sprite->colors = (uint16_t)va_arg(args, long);
    sprite->data = (uint8_t*)va_arg(args, void*);


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

