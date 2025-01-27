#include "../artemis.h"
/**
 * The entity class. Cannot be instantiated outside the framework, you must
 * create new entities using World.
 * 
 * @author Arni Arent
 * 
 */
struct __ArtemisEntity {
    struct __CFObject           obj;
    CFStringRef                 uuid;
    CFStringRef                 name;
    int                         id;
    CFBitVectorRef              componentBits;
    CFBitVectorRef              systemBits;
    ArtemisWorldRef             world;
    ArtemisEntityManagerRef     entityManager;
    ArtemisComponentManagerRef  componenetManager;
};

static bool ctor(void *ptr, va_list args)
{
    ArtemisEntityRef this = ptr;
    this->world = va_arg(args, ArtemisWorldRef);
    this->id = va_arg(args, int);
    this->name = CFCreate(CFString, va_arg(args, char*));
    this->entityManager = ArtemisWorldGetEntityManager(this->world);
    this->componenetManager = ArtemisWorldGetComponentManager(this->world);
    this->systemBits = CFCreate(CFBitVector, NULL);
    this->componentBits = CFCreate(CFBitVector, NULL);

    return true;
}

ulong ArtemisEntityGetId(ArtemisEntityRef this)
{
    (void*)this;
    return 0;
}

CFBitVectorRef ArtemisEntityGetComponentBits(ArtemisEntityRef this)
{
    (void*)this;
    return NULL;
}

CFBitVectorRef ArtemisEntityGetSystemBits(ArtemisEntityRef this)
{
    (void*)this;
    return NULL;
}

void ArtemisEntityReset(ArtemisEntityRef this)
{
    (void*)this;
}

CFObjectRef ArtemisEntityCreateComponent(ArtemisEntityRef this, CFClassRef cls, ...)
{
    (void*)this;
    (void*)cls;
    return NULL;
}

ArtemisEntityRef ArtemisEntityAddComponent(ArtemisEntityRef this, CFObjectRef component, ...)
{
    (void*)this;
    (void*)component;
    return NULL;
}

ArtemisComponentTypeRef ArtemisEntityGetTypeFor(ArtemisEntityRef this, CFObjectRef component)
{
    (void*)this;
    (void*)component;
    return NULL;
}

ArtemisEntityRef ArtemisEntityRemoveComponentInstance(ArtemisEntityRef this, CFObjectRef component)
{
    (void*)this;
    (void*)component;
    return NULL;
}

ArtemisEntityRef ArtemisEntityRemoveComponent(ArtemisEntityRef this, ArtemisComponentTypeRef component)
{
    (void*)this;
    (void*)component;
    return NULL;
}

ArtemisEntityRef ArtemisEntityRemoveComponentByType(ArtemisEntityRef this, CFClassRef cls)
{
    (void*)this;
    (void*)cls;
    return NULL;
}

bool ArtemisEntityIsActive(ArtemisEntityRef this)
{
    (void*)this;
    return NULL;
}

bool ArtemisEntityIsEnabled(ArtemisEntityRef this)
{
    (void*)this;
    return NULL;
}

CFObjectRef ArtemisEntityGetComponent(ArtemisEntityRef this, ArtemisComponentTypeRef type)
{
    (void*)this;
    (void*)type;
    return NULL;
}

CFObjectRef ArtemisEntityGetComponentByType(ArtemisEntityRef this, CFClassRef cls)
{
    (void*)this;
    (void*)cls;
    return NULL;
}

CFArrayRef ArtemisEntityGetComponents(ArtemisEntityRef this, CFArrayRef components)
{
    (void*)this;
    (void*)components;
    return NULL;
}

void ArtemisEntityAddToWorld(ArtemisEntityRef this)
{
    (void*)this;
}

void ArtemisEntityDeleteFromWorld(ArtemisEntityRef this)
{
    (void*)this;
}

void ArtemisEntityEnable(ArtemisEntityRef this)
{
    (void*)this;
}

void ArtemisEntityDisable(ArtemisEntityRef this)
{
    (void*)this;
}

CFStringRef ArtemisEntityGetUUID(ArtemisEntityRef this)
{
    (void*)this;
    return NULL;
}

ArtemisWorldRef ArtemisEntityGetWorld(ArtemisEntityRef this)
{
    (void*)this;
    return NULL;
}


static struct __CFClass class = {
    .name = "ArtemisEntity",
    .size = sizeof(struct __ArtemisEntity),
    .ctor = ctor,
};
CFClassRef ArtemisEntity = &class;
