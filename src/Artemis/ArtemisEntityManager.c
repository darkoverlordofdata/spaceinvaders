#include "ArtemisEntityManager.h"
/**
 *
 */
static bool
ctor(void *ptr, va_list args)
{
    (void*)args;
	ArtemisEntityManagerRef this = ptr;

    this->entities = CFCreate(CFArray, NULL);
    this->disabled = CFCreate(CFBitVector);
    this->active = 0;
    this->added = 0;
    this->created = 0;
    this->deleted = 0;
	return true;
}


static struct __CFClass class = {
	.name = "ArtemisEntityManager",
	.size = sizeof(struct __ArtemisEntityManager),
	.ctor = ctor,
};
CFClassRef ArtemisEntityManager = &class;
