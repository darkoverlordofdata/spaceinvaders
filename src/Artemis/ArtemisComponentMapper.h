#pragma once
#include "../corefw.h" // IWYU pragma: keep
#include "ArtemisWorld.h"
/**
 * High performance component retrieval from entities. Use this wherever you
 * need to retrieve components from entities often and fast.
 * 
 * @author Arni Arent
 *
 * @param <A> the class type of the component
 */
typedef struct __ArtemisComponentMapper* ArtemisComponentMapperRef;
extern CFClassRef ArtemisComponentMapper;

typedef struct __ArtemisComponentType* ArtemisComponentTypeRef;


struct __ArtemisComponentMapper {
    struct __CFObject obj;
    ArtemisWorldRef                     world;
    ArtemisComponentTypeRef             type;
    CFClassRef                          classType;
    CFArrayRef                          components;
};



CFObjectRef ArtemisComponentMapperGet(ArtemisComponentMapperRef, ArtemisEntityRef);
bool ArtemisComponentMapperHas(ArtemisComponentMapperRef, ArtemisEntityRef);
ArtemisComponentMapperRef ArtemisComponentMapperGetFor(CFClassRef, ArtemisWorldRef);

