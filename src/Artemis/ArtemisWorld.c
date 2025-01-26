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
struct __ArtemisWorld {
    struct __CFObject           obj;
    float                       delta;
    CFMapRef                    managers;
    CFMapRef                    systems;
    CFArrayRef                  added;
    CFArrayRef                  changed;
    CFArrayRef                  deleted;
    CFArrayRef                  enable;
    CFArrayRef                  disable;
    ArtemisEntityManagerRef     em;
    ArtemisComponentManagerRef  cm;
};

static bool ctor(void *ptr, va_list args)
{
    (void*)args;
	ArtemisWorldRef this = ptr;
    this->managers = CFCreate(CFMap, NULL);
    this->systems = CFCreate(CFMap, NULL);
    this->added = CFCreate(CFArray, NULL);
    this->changed = CFCreate(CFArray, NULL);
    this->deleted = CFCreate(CFArray, NULL);
    this->enable = CFCreate(CFArray, NULL);
    this->disable = CFCreate(CFArray, NULL);

	return true;
}


static struct __CFClass class = {
	.name = "ArtemisWorld",
	.size = sizeof(struct __ArtemisWorld),
	.ctor = ctor,
};
CFClassRef ArtemisWorld = &class;
