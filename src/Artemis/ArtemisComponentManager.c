#include "../artemis.h"
/**
* 
*/
static bool
ctor(void *ptr, va_list args)
{
    (void*)args;
	ArtemisComponentManagerRef this = ptr;
    this->componentsByType = CFCreate(CFArray, NULL);
    this->pooledComponents = NULL;
    this->deleted = CFCreate(CFArray, NULL);
    this->typeFactory = NULL;

	return true;
}


static struct __CFClass class = {
	.name = "ArtemisComponentManager",
	.size = sizeof(struct __ArtemisComponentManager),
	.ctor = ctor,
};
CFClassRef ArtemisComponentManager = &class;
