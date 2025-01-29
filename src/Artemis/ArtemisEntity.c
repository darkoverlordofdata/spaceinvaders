#include "../artemis.h"
#include <stdlib.h>
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
    ulong                       id;
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
    this->id = va_arg(args, ulong);
    this->name = CFCreate(CFString, va_arg(args, char*));
    this->entityManager = ArtemisWorldGetEntityManager(this->world);
    this->componenetManager = ArtemisWorldGetComponentManager(this->world);
    this->systemBits = CFCreate(CFBitVector, NULL);
    this->componentBits = CFCreate(CFBitVector, NULL);

    return true;
}

/**
 * The internal id for this entity within the framework. No other entity
 * will have the same ID, but ID's are however reused so another entity may
 * acquire this ID if the previous entity was deleted.
 * 
 * @return id of the entity.
 */
ulong ArtemisEntityGetId(ArtemisEntityRef this)
{
    return this->id;
}

/**
 * Returns a BitSet instance containing bits of the components the entity possesses.
 * @return
 */
CFBitVectorRef ArtemisEntityGetComponentBits(ArtemisEntityRef this)
{
    return this->componentBits;
}

/**
 * Returns a BitSet instance containing bits of the components the entity possesses.
 * @return
 */
CFBitVectorRef ArtemisEntityGetSystemBits(ArtemisEntityRef this)
{
    return this->systemBits;
}

/**
 * Make entity ready for re-use.
 * Will generate a new uuid for the entity.
 */
void ArtemisEntityReset(ArtemisEntityRef this)
{
    CFBitVectorSetAllBits(this->systemBits, false);
    CFBitVectorSetAllBits(this->componentBits, false);
    this->uuid = ArtemisWorldRandomUUID();
}

CFObjectRef ArtemisEntityCreateComponent(ArtemisEntityRef this, CFClassRef cls, ...)
{
    (void*)this;
    (void*)cls;
    return NULL;
}

/**
 * Faster adding of components into the entity. Not neccessery to use this, but
 * in some cases you might need the extra performance.
 * 
 * @param component the component to add
 * @param args of the component
 * 
 * @return this entity for chaining.
 */
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

/**
 * Faster removal of components from a entity.
 * 
 * @param type to remove from this entity.
 * 
 * @return this entity for chaining.
 */
ArtemisEntityRef ArtemisEntityRemoveComponent(ArtemisEntityRef this, ArtemisComponentTypeRef component)
{
    (void*)this;
    (void*)component;
    return NULL;
}

/**
 * Remove component by its type.
 * @param type
 * 
 * @return this entity for chaining.
 */
ArtemisEntityRef ArtemisEntityRemoveComponentByType(ArtemisEntityRef this, CFClassRef cls)
{
    (void*)this;
    (void*)cls;
    return NULL;
}

/**
 * Checks if the entity has been added to the world and has not been deleted from it.
 * If the entity has been disabled this will still return true.
 * 
 * @return if it's active.
 */
bool ArtemisEntityIsActive(ArtemisEntityRef this)
{
    (void*)this;
    return NULL;
}

/**
 * Will check if the entity is enabled in the world.
 * By default all entities that are added to world are enabled,
 * this will only return false if an entity has been explicitly disabled.
 * 
 * @return if it's enabled
 */
bool ArtemisEntityIsEnabled(ArtemisEntityRef this)
{
    (void*)this;
    return NULL;
}

/**
 * This is the preferred method to use when retrieving a component from a
 * entity. It will provide good performance.
 * But the recommended way to retrieve components from an entity is using
 * the ComponentMapper.
 * 
 * @param type
 *            in order to retrieve the component fast you must provide a
 *            ComponentType instance for the expected component.
 * @return
 */
CFObjectRef ArtemisEntityGetComponent(ArtemisEntityRef this, ArtemisComponentTypeRef type)
{
    (void*)this;
    (void*)type;
    return NULL;
}

/**
 * Slower retrieval of components from this entity. Minimize usage of this,
 * but is fine to use e.g. when creating new entities and setting data in
 * components.
 * 
 * @param <T>
 *            the expected return component type.
 * @param type
 *            the expected return component type.
 * @return component that matches, or null if none is found.
 */
CFObjectRef ArtemisEntityGetComponentByType(ArtemisEntityRef this, CFClassRef cls)
{
    (void*)this;
    (void*)cls;
    return NULL;
}

/**
 * Returns a bag of all components this entity has.
 * You need to reset the bag yourself if you intend to fill it more than once.
 * 
 * @param fillBag the bag to put the components into.
 * @return the fillBag with the components in.
 */
CFArrayRef ArtemisEntityGetComponents(ArtemisEntityRef this, CFArrayRef components)
{
    (void*)this;
    (void*)components;
    return NULL;
}

/**
 * Refresh all changes to components for this entity. After adding or
 * removing components, you must call this method. It will update all
 * relevant systems. It is typical to call this after adding components to a
 * newly created entity.
 */
void ArtemisEntityAddToWorld(ArtemisEntityRef this)
{
    (void*)this;
}

/**
 * This entity has changed, a component added or deleted.
 */
void ArtemisEntityChangeInWorld(ArtemisEntityRef this)
{
    (void*)this;
}

/**
 * Delete this entity from the world.
 */
void ArtemisEntityDeleteFromWorld(ArtemisEntityRef this)
{
    (void*)this;
}

/**
 * (Re)enable the entity in the world, after it having being disabled.
 * Won't do anything unless it was already disabled.
 */
void ArtemisEntityEnable(ArtemisEntityRef this)
{
    (void*)this;
}

/**
 * Disable the entity from being processed. Won't delete it, it will
 * continue to exist but won't get processed.
 */
void ArtemisEntityDisable(ArtemisEntityRef this)
{
    (void*)this;
}

/**
 * Get the UUID for this entity.
 * This UUID is unique per entity (re-used entities get a new UUID).
 * @return uuid instance for this entity.
 */
CFStringRef ArtemisEntityGetUUID(ArtemisEntityRef this)
{
    (void*)this;
    return NULL;
}

/**
 * Returns the world this entity belongs to.
 * @return world of entity.
 */
ArtemisWorldRef ArtemisEntityGetWorld(ArtemisEntityRef this)
{
    (void*)this;
    return NULL;
}

/**
 * get a random uuid
 * xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
 *
 * @see https://github.com/torvalds/linux/blob/master/lib/uuid.c
 */			
CFStringRef ArtemisWorldRandomUUID() {

    int d0 = rand();
    int d1 = rand();
    int d2 = rand();
    int d3 = rand();

    unsigned char result[17] = {
        d0&0xff,
        d0>>8&0xff,
        d0>>16&0xff,
        d0>>24&0xff,
        d1&0xff,
        d1>>8&0xff,
        (d1>>16&0x0f)|0x40,     /* Set GUID version to 4 --- truly random generation */
        d1>>24&0xff,
        (d2&0x3f)|0x80,         /* Set the GUID variant to DCE */
        d2>>8&0xff,
        d2>>16&0xff,
        d2>>24&0xff,
        d3&0xff,
        d3>>8&0xff,
        d3>>16&0xff,
        d3>>24&0xff,
        0
    };

    return CFCreate(CFString, result);
 

}

static struct __CFClass class = {
    .name = "ArtemisEntity",
    .size = sizeof(struct __ArtemisEntity),
    .ctor = ctor,
};
CFClassRef ArtemisEntity = &class;
