#include "../artemis.h"
/**
* 
*/
struct __ArtemisComponentTypeFactory {
    struct __CFObject           obj;
    CFMapRef                    componentTypes;
    int                         componentTypeCount;
    CFArrayRef                  types;

};

static bool ctor(void *ptr, va_list args)
{
    (void*)args;
    ArtemisComponentTypeFactoryRef this = ptr;

    this->componentTypes = CFCreate(CFMap, NULL);
    this->types = CFCreate(CFArray, NULL);
    this->componentTypeCount = 0;
    ArtemisAspectTypeFactory = this;

    return true;
}

ArtemisComponentTypeRef ArtemisComponentTypeFactoryGetTypeFor(ArtemisComponentTypeFactoryRef this, CFClassRef cls)
{
    (void*)this;
    (void*)cls;
    return NULL;
}

ulong ArtemisComponentTypeFactoryGetIndexFor(ArtemisComponentTypeFactoryRef this, CFClassRef cls)
{
    (void*)this;
    (void*)cls;
    return 0;
}

ArtemisTaxonomy ArtemisComponentTypeFactoryGetTaxonomy(ArtemisComponentTypeFactoryRef this, ulong index)
{
    (void*)this;
    (void)index;
    return 0;
}

static struct __CFClass class = {
    .name = "ArtemisComponentTypeFactory",
    .size = sizeof(struct __ArtemisComponentTypeFactory),
    .ctor = ctor,
};
CFClassRef ArtemisComponentTypeFactory = &class;
