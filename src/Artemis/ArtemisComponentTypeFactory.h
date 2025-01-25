#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
* 
*/
typedef struct __ArtemisComponentTypeFactory* ArtemisComponentTypeFactoryRef;
extern CFClassRef ArtemisComponentTypeFactory;

extern ArtemisComponentTypeFactoryRef ArtemisAspectTypeFactory;

struct __ArtemisComponentTypeFactory {
    struct __CFObject           obj;
    CFMapRef                    componentTypes;
    int                         componentTypeCount;
    CFArrayRef                  types;

};



