#include "../artemis.h"
/**
 *
 */
struct __ArtemisEntityManager {
    struct __CFObject   obj;
    ArtemisWorldRef     world;
    CFArrayRef          entities;
    CFBitVectorRef      disabled;
    int                 active;
    int                 added;
    int                 created;
    int                 deleted;

};

static bool ctor(void *ptr, va_list args)
{
    (void*)args;
    ArtemisEntityManagerRef this = ptr;

    this->entities = CFCreate(CFArray, NULL);
    this->disabled = CFCreate(CFBitVector);
    this->active = 0;
    this->added = 0;
    this->created = 0;
    this->deleted = 0;
    return true;
}

ArtemisEntityRef ArtemisEntityManagerCreateEntityInstance(ArtemisEntityManagerRef this, CFStringRef name)
{
    (void*)this;
    (void*)name;
    return NULL;
}

void ArtemisEntityManagerAdded(ArtemisEntityManagerRef this, ArtemisEntityRef e)
{ 
    (void*)this;
    (void*)e;
}

void ArtemisEntityManagerEnabled(ArtemisEntityManagerRef this, ArtemisEntityRef e)
{ 
    (void*)this;
    (void*)e;
}

void ArtemisEntityManagerDisabled(ArtemisEntityManagerRef this, ArtemisEntityRef e)
{ 
    (void*)this;
    (void*)e;
}

void ArtemisEntityManagerDeleted(ArtemisEntityManagerRef this, ArtemisEntityRef e)
{ 
    (void*)this;
    (void*)e;
}

bool ArtemisEntityManagerIsActive(ArtemisEntityManagerRef this, ulong id)
{ 
    (void*)this;
    (void)id;
    return false;
}

bool ArtemisEntityManagerIsEnaled(ArtemisEntityManagerRef this, ulong id)
{ 
    (void*)this;
    (void)id;
    return false;
}

ArtemisEntityRef ArtemisEntityManageGetEntity(ArtemisEntityManagerRef this, ulong id)
{ 
    (void*)this;
    (void)id;
    return NULL;
}

ulong ArtemisEntityManageGetActiveEntityCount(ArtemisEntityManagerRef this)
{ 
    (void*)this;
    return 0;
}

ulong ArtemisEntityManageGetTotalCreated(ArtemisEntityManagerRef this)
{ 
    (void*)this;
    return 0;
}

ulong ArtemisEntityManageGetTotalDeleted(ArtemisEntityManagerRef this)
{ 
    (void*)this;
    return 0;
}




static struct __CFClass class = {
    .name = "ArtemisEntityManager",
    .size = sizeof(struct __ArtemisEntityManager),
    .ctor = ctor,
};
CFClassRef ArtemisEntityManager = &class;
