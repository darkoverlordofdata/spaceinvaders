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
struct __ArtemisAspect {
    struct __CFObject obj;
    CFBitVectorRef  allSet;
    CFBitVectorRef  exclusionSet;
    CFBitVectorRef  oneSet;
    ArtemisWorldRef world;
};

/**
 * @param {ArtemisWorld} world
 * @param {CFBitVectorRef} allSet
 * @param {CFBitVectorRef} exclusionSet
 * @param {CFBitVectorRef} oneSet
 */
static bool ctor(void *ptr, va_list args)
{
	ArtemisAspectRef this = ptr;

	this->world = va_arg(args, ArtemisWorldRef);
	this->allSet = CFCreate(CFBitVector);
	this->exclusionSet = CFCreate(CFBitVector);
	this->oneSet = CFCreate(CFBitVector);

	return true;
}
/**
 *
 * @param {ArtemisWorld} world
 */
void ArtemisAspectSetWorld(ArtemisAspectRef this, ArtemisWorldRef world)
{
	this->world = world;
}

CFBitVectorRef ArtemisAspectGetAllSet(ArtemisAspectRef this)
{
	return this->allSet;
}

CFBitVectorRef ArtemisAspectGetExclusionSet(ArtemisAspectRef this)
{
	return this->exclusionSet;
}

CFBitVectorRef ArtemisAspectGetOneSet(ArtemisAspectRef this)
{
	return this->oneSet;
}

ulong ArtemisAspectGetIndexFor(ArtemisAspectRef this, CFClassRef cls)
{
	(void*)this;
	return ArtemisComponentTypeFactoryGetIndexFor(ArtemisAspectTypeFactory, cls);
}

/**
 * Returns an aspect where an entity must possess all of the specified component types.
 * @param {Class} type a required component type
 * @param {Array<Class>} types a required component type
 * @return {artemis.Aspect} an aspect that can be matched against entities
*/
ArtemisAspectRef ArtemisAspectAll(ArtemisAspectRef this, ...)
{
	va_list args;
	va_start(args, this);
	CFClassRef cls;
	while ((cls = va_arg(args, CFClassRef)) != NULL) {
		CFBitVectorSetBitAtIndex(this->allSet, ArtemisAspectGetIndexFor(this, cls), true);
	}
	va_end(args);
	return this;
}

/**
 * Excludes all of the specified component types from the aspect. A system will not be
 * interested in an entity that possesses one of the specified exclusion component types.
 *
 * @param {Class} type component type to exclude
 * @param {Array<Class>} types component type to exclude
 * @return {artemis.Aspect} an aspect that can be matched against entities
 */
ArtemisAspectRef ArtemisAspectExclude(ArtemisAspectRef this, ...)
{
	va_list args;
	va_start(args, this);
	CFClassRef cls;
	while ((cls = va_arg(args, CFClassRef)) != NULL) {
		CFBitVectorSetBitAtIndex(this->exclusionSet, ArtemisAspectGetIndexFor(this, cls), true);
	}
	va_end(args);
	return this;
}

/**
 * Returns an aspect where an entity must possess one of the specified component types.
 * @param {Class} type one of the types the entity must possess
 * @param {Array<Class>} types one of the types the entity must possess
 * @return {artemis.Aspect} an aspect that can be matched against entities
 */
ArtemisAspectRef ArtemisAspectOne(ArtemisAspectRef this, ...)
{
	va_list args;
	va_start(args, this);
	CFClassRef cls;
	while ((cls = va_arg(args, CFClassRef)) != NULL) {
		CFBitVectorSetBitAtIndex(this->oneSet, ArtemisAspectGetIndexFor(this, cls), true);
	}
	va_end(args);
	return this;
}



static struct __CFClass class = {
	.name = "ArtemisAspect",
	.size = sizeof(struct __ArtemisAspect),
	.ctor = ctor,
};
CFClassRef ArtemisAspect = &class;
