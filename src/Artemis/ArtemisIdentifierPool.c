#include "../artemis.h"
/**
 * The most raw entity system. It should not typically be used, but you can create your own
 * entity system handling by extending this. It is recommended that you use the other provided
 * entity system implementations.
 * 
 * @author Arni Arent
 *
 */
static bool ctor(void *ptr, va_list args)
{
    (void*)args;

	ArtemisIdentifierPoolRef this = ptr; 	
    this->ids = CFCreate(CFArray, NULL);

	return true;
}


static struct __CFClass class = {
	.name = "ArtemisIdentifierPool",
	.size = sizeof(struct __ArtemisIdentifierPool),
	.ctor = ctor,
};
CFClassRef ArtemisIdentifierPool = &class;
