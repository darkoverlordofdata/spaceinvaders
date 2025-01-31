#include "../artemis.h"
/**
 * The most raw entity system. It should not typically be used, but you can create your own
 * entity system handling by extending this. It is recommended that you use the other provided
 * entity system implementations.
 * 
 * @author Arni Arent
 *
 */
struct __ArtemisIdentifierPool {
    struct __CFObject   obj;
    CFBagRef ids;
    ulong nextAvailableId;
};

static bool ctor(void *ptr, va_list args)
{
    (void*)args;

    ArtemisIdentifierPoolRef this = ptr;     
    this->ids = CFCreate(CFBag,64);

    return true;
}

ulong ArtemisIdentifierPoolCheckOut(ArtemisIdentifierPoolRef this)
{
    if (CFBagSize(this->ids) > 0) {
        return (ulong)CFIntValue(CFBagRemoveLast(this->ids));
    }
    return this->nextAvailableId;
}

void ArtemisIdentifierPoolCheckIn(ArtemisIdentifierPoolRef this, ulong index)
{
    CFBagAdd(this->ids, CFIntCreate((int64_t)index));
}

static struct __CFClass class = {
    .name = "ArtemisIdentifierPool",
    .size = sizeof(struct __ArtemisIdentifierPool),
    .ctor = ctor,
};
CFClassRef ArtemisIdentifierPool = &class;
