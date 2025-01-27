#include "../artemis.h"
/**
 * The most raw entity system. It should not typically be used, but you can create your own
 * entity system handling by extending this. It is recommended that you use the other provided
 * entity system implementations.
 * 
 * @author Arni Arent
 *
 */
struct __ArtemisEntitySystem {
    struct __CFObject   obj;
    ulong               systemIndex;  
    ArtemisWorldRef     world;
    CFArrayRef          actives;
    ArtemisAspectRef    aspect;
    CFBitVectorRef      allSet;
    CFBitVectorRef      exclusionSet;
    CFBitVectorRef      oneSet;
    bool                passive;
    bool                dummy;
};


static bool ctor(void *ptr, va_list args)
{
    ArtemisEntitySystemRef this = ptr;     

    this->actives = CFCreate(CFArray, NULL);
    this->aspect = va_arg(args, ArtemisAspectRef);
    this->systemIndex = ArtemisSystemIndexManagerGetIndexFor(ArtemisEntitySystem);
    this->allSet = CFCreate(CFBitVector);
    this->exclusionSet = CFCreate(CFBitVector);
    this->oneSet = CFCreate(CFBitVector);
    this->dummy = false;

    return true;
}

void ArtemisEntitySystemBegin(ArtemisEntitySystemRef this)
{
    (void*)this;
}

void ArtemisEntitySystemProcess(ArtemisEntitySystemRef this)
{
    (void*)this;
}

void ArtemisEntitySystemEnd(ArtemisEntitySystemRef this)
{
    (void*)this;
}

void ArtemisEntitySystemProcessEntities(ArtemisEntitySystemRef this, CFArrayRef entities)
{
    (void*)this;
    (void*)entities;
}

bool ArtemisEntitySystemCheckProcessing(ArtemisEntitySystemRef this)
{
    (void*)this;
    return false;
}

void ArtemisEntitySystemInitialize(ArtemisEntitySystemRef this)
{
    (void*)this;
}

void ArtemisEntitySystemInserted(ArtemisEntitySystemRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisEntitySystemRemoved(ArtemisEntitySystemRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisEntitySystemCheck(ArtemisEntitySystemRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisEntitySystemRemoveFromSystem(ArtemisEntitySystemRef this, ArtemisEntityRef e)
{
    (void*)e;
    (void*)this;
}

void ArtemisEntitySystemInsertToSystem(ArtemisEntitySystemRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisEntitySystemAdded(ArtemisEntitySystemRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisEntitySystemChanged(ArtemisEntitySystemRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisEntitySystemDeleted(ArtemisEntitySystemRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisEntitySystemDisabled(ArtemisEntitySystemRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisEntitySystemEnabled(ArtemisEntitySystemRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisEntitySystemSetWorld(ArtemisEntitySystemRef this, ArtemisWorldRef world)
{
    (void*)this;
    (void*)world;
}

bool ArtemisEntitySystemIsPassive(ArtemisEntitySystemRef this)
{
    (void*)this;
    return false;
}

void ArtemisEntitySystemSetPassive(ArtemisEntitySystemRef this, bool value)
{
    (void*)this;
    (void)value;
}

CFArrayRef ArtemisEntitySystemGetActive(ArtemisEntitySystemRef this)
{
    (void*)this;
    return NULL;
}


static struct __CFClass class = {
    .name = "ArtemisEntitySystem",
    .size = sizeof(struct __ArtemisEntitySystem),
    .ctor = ctor,
};
CFClassRef ArtemisEntitySystem = &class;
