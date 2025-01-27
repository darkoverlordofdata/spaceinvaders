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


static struct __CFClass class = {
	.name = "ArtemisEntity",
	.size = sizeof(struct __ArtemisEntity),
	.ctor = ctor,
};
CFClassRef ArtemisEntity = &class;
