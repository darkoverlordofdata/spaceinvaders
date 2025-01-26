#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
* 
*/

typedef struct __ArtemisComponentType* ArtemisComponentTypeRef;
extern CFClassRef ArtemisComponentType;

typedef enum ArtemisTaxonomy {
    ArtemisTaxonomy_BASIC, 
    ArtemisTaxonomy_POOLED
} ArtemisTaxonomy;

typedef struct __ArtemisComponentManager* ArtemisComponentManagerRef;

extern int ArtemisComponentTypeIndex;

struct __ArtemisComponentType {
    struct __CFObject               obj;
    ArtemisComponentManagerRef      componentManager;
    int                             index;
    CFClassRef                      type;
    ArtemisTaxonomy                 taxonomy;

};



CFStringRef ArtemisComponentTypeGetName(ArtemisComponentTypeRef);
ulong ArtemisComponentTypeGetIndex(ArtemisComponentTypeRef);
ulong ArtemisComponentTypeGetTaxonomy(ArtemisComponentTypeRef);
