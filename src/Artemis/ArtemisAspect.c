#include "../artemis.h"
/**
 * An Aspects is used by systems as a matcher against entities, to check if a system is
 * interested in an entity. Aspects define what sort of component types an entity must
 * possess, or not possess.
 *
 * This creates an aspect where an entity must possess A and B and C:
 * Aspect.getAspectForAll(A.class, B.class, C.class)
 *
 * This creates an aspect where an entity must possess A and B and C, but must not possess U or V.
 * Aspect.getAspectForAll(A.class, B.class, C.class).exclude(U.class, V.class)
 *
 * This creates an aspect where an entity must possess A and B and C, but must not possess U or V, but must possess one of X or Y or Z.
 * Aspect.getAspectForAll(A.class, B.class, C.class).exclude(U.class, V.class).one(X.class, Y.class, Z.class)
 *
 * You can create and compose aspects in many ways:
 * Aspect.getEmpty().one(X.class, Y.class, Z.class).all(A.class, B.class, C.class).exclude(U.class, V.class)
 * is the same as:
 * Aspect.getAspectForAll(A.class, B.class, C.class).exclude(U.class, V.class).one(X.class, Y.class, Z.class)
 *
 * @author Arni Arent
 *
 */
static bool
ctor(void *ptr, va_list args)
{
	ArtemisAspectRef this = ptr;

	this->world = va_arg(args, ArtemisWorldRef);
    this->allSet = CFCreate(CFBitVector);
    this->exclusionSet = CFCreate(CFBitVector);
    this->oneSet = CFCreate(CFBitVector);

	return true;
}


static struct __CFClass class = {
	.name = "ArtemisAspect",
	.size = sizeof(struct __ArtemisAspect),
	.ctor = ctor,
};
CFClassRef ArtemisAspect = &class;
