#include "../artemis.h"
/**
* 
*/
struct __ArtemisComponentType {
    struct __CFObject               obj;
    ArtemisComponentManagerRef      componentManager;
    ulong                           index;
    CFClassRef                      type;   
    ArtemisTaxonomy                 taxonomy;

};

static bool ctor(void *ptr, va_list args)
{
    ArtemisComponentTypeRef this = ptr;

    this->type = va_arg(args, CFClassRef);
    this->index = va_arg(args, ulong);
    if (this->index < 0) {
        this->index = ArtemisComponentTypeIndex++;
    }
    this->taxonomy = ArtemisTaxonomy_BASIC;
    return true;
}

CFStringRef ArtemisComponentTypeGetName(ArtemisComponentTypeRef this)
{
    return CFCreate(CFString, this->obj.cls->name);
}

ulong ArtemisComponentTypeGetIndex(ArtemisComponentTypeRef this)
{
    return this->index;
}

ArtemisTaxonomy ArtemisComponentTypeGetTaxonomy(ArtemisComponentTypeRef this)
{
    return this->taxonomy;
}

static struct __CFClass class = {
	.name = "ArtemisComponentType",
	.size = sizeof(struct __ArtemisComponentType),
	.ctor = ctor,
};
CFClassRef ArtemisComponentType = &class;
