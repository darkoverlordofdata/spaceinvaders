#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
* 
*/
typedef struct __ArtemisComponentTypeFactory* ArtemisComponentTypeFactoryRef;
extern CFClassRef ArtemisComponentTypeFactory;

extern ArtemisComponentTypeFactoryRef ArtemisAspectTypeFactory;
typedef struct __ArtemisComponentType* ArtemisComponentTypeRef;

// typedef enum ArtemisTaxonomy {
//     ArtemisTaxonomy_BASIC, 
//     ArtemisTaxonomy_POOLED
// } ArtemisTaxonomy;

struct __ArtemisComponentTypeFactory {
    struct __CFObject           obj;
    CFMapRef                    componentTypes;
    int                         componentTypeCount;
    CFArrayRef                  types;

};



ArtemisComponentTypeRef ArtemisComponentTypeFactoryGetTypeFor(ArtemisComponentTypeFactoryRef, CFClassRef);
int ArtemisComponentTypeFactoryGetIndexFor(ArtemisComponentTypeFactoryRef, CFClassRef);
// ArtemisTaxonomy ArtemisComponentTypeFactoryGetTaxonomy(ArtemisComponentTypeFactoryRef, int);
ulong ArtemisComponentTypeFactoryGetTaxonomy(ArtemisComponentTypeFactoryRef, int);
