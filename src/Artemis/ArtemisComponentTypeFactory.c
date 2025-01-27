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


static struct __CFClass class = {
    .name = "ArtemisComponentTypeFactory",
    .size = sizeof(struct __ArtemisComponentTypeFactory),
    .ctor = ctor,
};
CFClassRef ArtemisComponentTypeFactory = &class;
