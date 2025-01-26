#include "../artemis.h"
/**
* The primary instance for the framework. It contains all the managers.
* 
* You must use this to create, delete and retrieve entities.
* 
* It is also important to set the delta each game loop iteration, and initialize before game loop.
* 
* @author Arni Arent
* 
*/
struct __ArtemisComponentPool {
    struct __CFObject           obj;
    CFArrayRef                  pools;
};

static bool ctor(void *ptr, va_list args)
{
    (void*)args;
	ArtemisComponentPoolRef this = ptr;

	this->pools = CFCreate(CFArray, CFCreate(CFArray, NULL), NULL);
	return true;
}


static struct __CFClass class = {
	.name = "ArtemisComponentPool",
	.size = sizeof(struct __ArtemisComponentPool),
	.ctor = ctor,
};
CFClassRef ArtemisComponentPool = &class;
