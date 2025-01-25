#include <stdbool.h>
#include "Component.h"

int ComponentSlot(void* component)
{
    int slot=0;
    if (CFClass(component) == Status){
        slot = ComponentStatus;
    } else if (CFClass(component) == Position){
        slot = ComponentPosition;
    } else if (CFClass(component) == Sprite){
        slot = ComponentSprite;
    } else {
        slot = ComponentUnused;
    }
    return slot;

}


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

