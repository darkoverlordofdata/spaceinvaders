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
typedef struct __ArtemisClass* ArtemisClassRef;

extern int ArtemisComponentTypeIndex;

struct __ArtemisComponentType {
    struct __CFObject               obj;
    ArtemisComponentManagerRef      componentManager;
    int                             index;
    ArtemisClassRef                 type;
    ArtemisTaxonomy                 taxonomy;

};



