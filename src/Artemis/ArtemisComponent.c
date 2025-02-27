#include "../artemis.h"
/**
 * A tag class. All components in the system must extend this class.
 * 
 * @author Arni Arent
 */
struct __ArtemisComponent {
    struct __CFObject obj;
};


static bool ctor(void *ptr, va_list args)
{
    (void*)args;
    ArtemisComponentRef this = ptr;

    return true;
}


static struct __CFClass class = {
    .name = "ArtemisComponent",
    .size = sizeof(struct __ArtemisComponent),
    .ctor = ctor,
};
CFClassRef ArtemisComponent = &class;
