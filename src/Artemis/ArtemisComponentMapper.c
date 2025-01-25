#include "ArtemisComponentMapper.h"
#include "ArtemisWorld.h"
#include <stdarg.h>
/**
 * High performance component retrieval from entities. Use this wherever you
 * need to retrieve components from entities often and fast.
 * 
 * @author Arni Arent
 *
 * @param <A> the class type of the component
 */
static bool
ctor(void *ptr, va_list args)
{
    (void*)args;
	ArtemisComponentMapperRef this = ptr;
    this->classType = va_arg(args, CFObjectRef);
	this->world = va_arg(args, ArtemisWorldRef);
    this->type = NULL;
    this->components = NULL;
	return true;
}


static struct __CFClass class = {
	.name = "ArtemisComponentMapper",
	.size = sizeof(struct __ArtemisComponentMapper),
	.ctor = ctor,
};
CFClassRef ArtemisComponentMapper = &class;
