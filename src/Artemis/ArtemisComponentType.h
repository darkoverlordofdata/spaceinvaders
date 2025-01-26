#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
 *  @class ArtemisComponentType
 */
extern CFClassRef ArtemisComponentType;

typedef struct __ArtemisComponentType*      ArtemisComponentTypeRef;
typedef struct __ArtemisComponentManager*   ArtemisComponentManagerRef;

extern int ArtemisComponentTypeIndex;

CFStringRef ArtemisComponentTypeGetName(ArtemisComponentTypeRef);
ulong ArtemisComponentTypeGetIndex(ArtemisComponentTypeRef);
ulong ArtemisComponentTypeGetTaxonomy(ArtemisComponentTypeRef);
