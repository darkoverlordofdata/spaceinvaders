#include "../artemis.h"
/**
* The primary instance for the framework. It contains all the managers.
* 
* You must use this to create, delete and retrieve entities.
* 
* It is also important to set the delta each game loop iteration, and initialize before game loop.
* 
* @author Arni Arent
* 
*/
struct __ArtemisWorld {
    struct __CFObject           obj;
    float                       delta;
    CFMapRef                    managers;
    CFMapRef                    systems;
    CFArrayRef                  added;
    CFArrayRef                  changed;
    CFArrayRef                  deleted;
    CFArrayRef                  enable;
    CFArrayRef                  disable;
    ArtemisEntityManagerRef     em;
    ArtemisComponentManagerRef  cm;
};

static bool ctor(void *ptr, va_list args)
{
    (void*)args;
    ArtemisWorldRef this = ptr;
    this->managers = CFCreate(CFMap, NULL);
    this->systems = CFCreate(CFMap, NULL);
    this->added = CFCreate(CFArray, NULL);
    this->changed = CFCreate(CFArray, NULL);
    this->deleted = CFCreate(CFArray, NULL);
    this->enable = CFCreate(CFArray, NULL);
    this->disable = CFCreate(CFArray, NULL);

    return true;
}

ArtemisEntityManagerRef ArtemisWorldGetEntityManager(ArtemisWorldRef this)
{
    (void*)this;
    return NULL;
}

ArtemisComponentManagerRef ArtemisWorldGetComponentManager(ArtemisWorldRef this)
{
    (void*)this;
    return NULL;
}

CFObjectRef ArtemisWorldSetManager(ArtemisWorldRef this, CFObjectRef manager)
{
    (void*)this;
    (void*)manager;
    return NULL;
}

CFObjectRef ArtemisWorldGetManager(ArtemisWorldRef this, CFClassRef cls)
{
    (void*)this;
    (void*)cls;
    return NULL;
}

void ArtemisWorldDeleteManager(ArtemisWorldRef this, CFObjectRef manager)
{
    (void*)this;
    (void*)manager;
}

double ArtemisWorldGetDelta(ArtemisWorldRef this)
{
    (void*)this;
    return 0.0;
}

void ArtemisWorldSetDelta(ArtemisWorldRef this, double delta)
{
    (void*)this;
    (void)delta;
}

void ArtemisWorldAddEntity(ArtemisWorldRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisWorldChangedEntity(ArtemisWorldRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisWorldDeleteEntity(ArtemisWorldRef this, ArtemisEntityRef e)
{
    (void*)e;
    (void*)this;
}

void ArtemisWorldEnable(ArtemisWorldRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisWorldDisable(ArtemisWorldRef this, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}
ArtemisEntityRef ArtemisWorldCreateEntity(ArtemisWorldRef this, CFStringRef name)
{
    (void*)this;
    (void*)name;
    return NULL;
}

ArtemisEntityRef ArtemisWorldGetEntity(ArtemisWorldRef this, ulong id)
{
    (void*)this;
    (void)id;
    return NULL;
}

CFArrayRef ArtemisWorldGetSystems(ArtemisWorldRef this)
{
    (void*)this;
    return NULL;
}

ArtemisEntitySystemRef ArtemisWorldSetSystem(ArtemisWorldRef this, ArtemisEntitySystemRef, bool)
{
    (void*)this;
    return NULL;
}

void ArtemisWorldDeleteSystem(ArtemisWorldRef this, ArtemisEntitySystemRef system)
{
    (void*)this;
    (void*)system;
}

void ArtemisWorldNotifySystems(ArtemisWorldRef this, CFObjectRef, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

void ArtemisWorldNotifyManagers(ArtemisWorldRef this, CFObjectRef, ArtemisEntityRef e)
{
    (void*)this;
    (void*)e;
}

ArtemisEntitySystemRef ArtemisWorldGetSystem(ArtemisWorldRef this, CFClassRef cls)
{
    (void*)this;
    (void*)cls;
    return NULL;
}

void ArtemisWorldCheck(ArtemisWorldRef this, CFArrayRef, CFObjectRef o)
{
    (void*)this;
    (void*)o;
}

void ArtemisWorldProcess(ArtemisWorldRef this)
{
    (void*)this;
}

ArtemisComponentMapperRef ArtemisWorldGetMapper(ArtemisWorldRef this, CFClassRef cls)
{
    (void*)this;
    (void*)cls;
    return NULL;
}

void ArtemisWorldSetEntityTemplate(ArtemisWorldRef this, CFStringRef, CFObjectRef cls)
{
    (void*)this;
    (void*)cls;
}

ArtemisEntityRef ArtemisWorldCreateEntityFromTemplate(ArtemisWorldRef this, CFStringRef name, ...)
{
    (void*)this;
    (void*)name;
    return NULL;
}




static struct __CFClass class = {
    .name = "ArtemisWorld",
    .size = sizeof(struct __ArtemisWorld),
    .ctor = ctor,
};
CFClassRef ArtemisWorld = &class;
