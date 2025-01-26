#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
* 
*/
typedef struct __ArtemisComponentTypeFactory* ArtemisComponentTypeFactoryRef;
extern CFClassRef ArtemisComponentTypeFactory;

extern ArtemisComponentTypeFactoryRef ArtemisAspectTypeFactory;
typedef struct __ArtemisComponentType* ArtemisComponentTypeRef;

struct __ArtemisComponentTypeFactory {
    struct __CFObject           obj;
    CFMapRef                    componentTypes;
    int                         componentTypeCount;
    CFArrayRef                  types;

};



ArtemisComponentTypeRef ArtemisComponentTypeFactoryGetTypeFor(ArtemisComponentTypeFactoryRef, CFClassRef);
ulong ArtemisComponentTypeFactoryGetIndexFor(ArtemisComponentTypeFactoryRef, CFClassRef);
// ArtemisTaxonomy ArtemisComponentTypeFactoryGetTaxonomy(ArtemisComponentTypeFactoryRef, int);
ulong ArtemisComponentTypeFactoryGetTaxonomy(ArtemisComponentTypeFactoryRef, ulong);
