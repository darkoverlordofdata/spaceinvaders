#include "../artemis.h"
/**
*   Component Manager Class
*/
struct __ArtemisComponentManager {
    struct __CFObject                   obj;
    CFArrayRef                          componentsByType;
    ArtemisComponentPoolRef             pooledComponents;
    CFArrayRef                          deleted;
    ArtemisComponentTypeFactoryRef      typeFactory;
    ArtemisWorldRef                     world;
};

static bool ctor(void *ptr, va_list args)
{
    (void*)args;
	ArtemisComponentManagerRef this = ptr;
    this->componentsByType = CFCreate(CFArray, NULL);
    this->pooledComponents = CFCreate(ArtemisComponentPool);
    this->deleted = CFCreate(CFArray, NULL);
    this->typeFactory = CFCreate(ArtemisComponentTypeFactory);

	return true;
}

CFObjectRef ArtemisComponentManagerCreate(ArtemisComponentManagerRef this, ArtemisEntityRef owner, CFClassRef componentClass)
{   
    ArtemisComponentTypeRef type = ArtemisComponentTypeFactoryGetTypeFor(this->typeFactory, componentClass);
    CFObjectRef component;

    switch(ArtemisComponentTypeGetTaxonomy(type))
    {
        case ArtemisTaxonomy_BASIC:
            component = ArtemisComponentManagerNewInstance(this, componentClass, false);
            break;
        case ArtemisTaxonomy_POOLED:
            component = ArtemisComponentManagerNewInstance(this, componentClass, false);
            break;
        default:
            component = NULL;
            break;
    }
    ArtemisComponentManagerAddComponent(this, owner, type, component);
    return component;
}

CFObjectRef ArtemisComponentManagerNewInstance(ArtemisComponentManagerRef this, CFClassRef cls, bool constructorHasWorldParameter)
{
    if (constructorHasWorldParameter) {
        return CFCreate(cls, this->world);
    } else {
        return CFCreate(cls);
    }
}

/**
 * Removes all components from the entity associated in this manager.
 *
 * @param e
 *          the entity to remove components from
 */
void ArtemisComponentManagerRemoveComponentsOfEntity(ArtemisComponentManagerRef this, ArtemisEntityRef e)
{
    CFBitVectorRef componentBits = ArtemisEntityGetComponentBits(e);
    for (ulong i = 0; i<CFBitVectorGetCount(componentBits); i++) {
        if (CFBitVectorGetBitAtIndex(componentBits, i)) {
            switch (ArtemisComponentTypeFactoryGetTaxonomy(this->typeFactory, i)) {
                case ArtemisTaxonomy_BASIC:
                    CFArraySet(this->componentsByType, ArtemisEntityGetId(e), NULL);
                    break;

                case ArtemisTaxonomy_POOLED:
                    CFArraySet(this->componentsByType, ArtemisEntityGetId(e), NULL);
                    break;
        
                default:
                    break;
            }
        }
    }
}

/**
 * Adds the component of the given type to the entity.
 * <p>
 * Only one component of given type can be associated with a entity at the
 * same time.
 * </p>
 *
 * @param e
 *			the entity to add to
 * @param type
 *			the type of component being added
 * @param component
 *			the component to add
 */
void ArtemisComponentManagerAddComponent(ArtemisComponentManagerRef this, ArtemisEntityRef e, ArtemisComponentTypeRef type, CFObjectRef component)
{
    CFArrayRef components = CFArrayGet(this->componentsByType, ArtemisComponentTypeGetIndex(type));
    if (components == NULL) {
        components = CFCreate(CFArray, NULL);
        CFArraySet(this->componentsByType, ArtemisComponentTypeGetIndex(type), components);
    }
    CFArraySet(components, ArtemisEntityGetId(e), component);
    CFBitVectorSetBitAtIndex(ArtemisEntityGetComponentBits(e), ArtemisComponentTypeGetIndex(type), true);
}

/**
 * Removes the component of given type from the entity.
 *
 * @param e
 *			the entity to remove from
 * @param type
 *			the type of component being removed
 */
void ArtemisComponentManagerRemoveComponent(ArtemisComponentManagerRef this, ArtemisEntityRef e, ArtemisComponentTypeRef type)
{
    ulong index = ArtemisComponentTypeGetIndex(type);
    switch (ArtemisComponentTypeGetTaxonomy(type)) {
        case ArtemisTaxonomy_BASIC:
            CFArraySet(this->componentsByType, ArtemisEntityGetId(e), NULL);
            CFBitVectorSetBitAtIndex(ArtemisEntityGetComponentBits(e), index, false);
            break;

        case ArtemisTaxonomy_POOLED:
            CFArraySet(this->componentsByType, ArtemisEntityGetId(e), NULL);
            CFBitVectorSetBitAtIndex(ArtemisEntityGetComponentBits(e), index, false);
            break;
 
        default:
            break;
    }

}

/**
 * Get all components from all entities for a given type.
 *
 * @param type
 *			the type of components to get
 * @return a bag containing all components of the given type
 */
CFArrayRef ArtemisComponentManagerGetComponentsByType(ArtemisComponentManagerRef this, ArtemisComponentTypeRef type)
{
    CFArrayRef components = CFArrayGet(this->componentsByType, ArtemisComponentTypeGetIndex(type));
    if (components == NULL) {
        components = CFCreate(CFArray, NULL);
        CFArraySet(this->componentsByType, ArtemisComponentTypeGetIndex(type), components);   
    }
    return components;
}

/**
 * Get a component of an entity.
 *
 * @param e
 *			the entity associated with the component
 * @param type
 *			the type of component to get
 * @return the component of given type
 */
CFObjectRef ArtemisComponentManagerGetComponent(ArtemisComponentManagerRef this, ArtemisEntityRef e, ArtemisComponentTypeRef type)
{
    CFArrayRef components = CFArrayGet(this->componentsByType, ArtemisComponentTypeGetIndex(type));
    if (components != NULL) {
        return CFArrayGet(components, ArtemisEntityGetId(e));
    }
    return NULL;
}

/**
 * Get all component associated with an entity.
 *
 * @param e
 *			the entity to get components from
 * @param fillBag
 *			a bag to be filled with components
 * @return the {@code fillBag}, filled with the entities components
 */
CFArrayRef ArtemisComponentManagerGetComponentsFor(ArtemisComponentManagerRef this, ArtemisEntityRef e, CFArrayRef fillBag){

    CFBitVectorRef componentBits = ArtemisEntityGetComponentBits(e);
    for (ulong i = 0; i<CFBitVectorGetCount(componentBits); i++) {
        CFArrayRef c = CFArrayGet(this->componentsByType, i);
        CFArrayPush(fillBag, CFArrayGet(c, ArtemisEntityGetId(e)));
    } 
    return fillBag;
}

void ArtemisComponentManagerDeleted(ArtemisComponentManagerRef this, ArtemisEntityRef e)
{
    CFArrayPush(this->deleted, e);
}

void ArtemisComponentManagerClean(ArtemisComponentManagerRef this)
{
    if (CFArraySize(this->deleted) > 0) {
        for (ulong i=0; CFArraySize(this->deleted) > i; i++) {
            ArtemisComponentManagerRemoveComponentsOfEntity(this, CFArrayGet(this->deleted, i));
        }
    }
}

static struct __CFClass class = {
	.name = "ArtemisComponentManager",
	.size = sizeof(struct __ArtemisComponentManager),
	.ctor = ctor,
};
CFClassRef ArtemisComponentManager = &class;
