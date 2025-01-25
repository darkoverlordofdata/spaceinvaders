#include "../artemis.h"
/**
* 
*/

static bool ctor(void *ptr, va_list args)
{
	ArtemisComponentTypeRef this = ptr;

    this->type = va_arg(args, CFClassRef);
    this->index = va_arg(args, int);
    if (this->index < 0) {
        this->index = ArtemisComponentTypeIndex++;
    }
    this->taxonomy = ArtemisTaxonomy_BASIC;
	return true;
}


static struct __CFClass class = {
	.name = "ArtemisComponentType",
	.size = sizeof(struct __ArtemisComponentType),
	.ctor = ctor,
};
CFClassRef ArtemisComponentType = &class;
