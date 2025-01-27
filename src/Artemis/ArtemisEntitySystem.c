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
    int                 systemIndex;  
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


static struct __CFClass class = {
	.name = "ArtemisEntitySystem",
	.size = sizeof(struct __ArtemisEntitySystem),
	.ctor = ctor,
};
CFClassRef ArtemisEntitySystem = &class;
