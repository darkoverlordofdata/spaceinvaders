#pragma once
#include "corefw.h" // IWYU pragma: keep
#include "Sprite.h"
#include "Component.h"

typedef struct __Entity* EntityRef;
extern CFClassRef Entity;

struct __Entity {
    struct __CFObject obj;
    AspectType aspect;
    EntityType kind;
    void* component[32];

} ;


void        Entity_Draw(EntityRef entity);
bool        Entity_Intersect(EntityRef e1, EntityRef e2);    
bool        Entity_IsAlive(EntityRef);
void        Entity_SetAlive(EntityRef, bool);
uint32_t    Entity_X(EntityRef);
uint32_t    Entity_Y(EntityRef);
SpriteRef   Entity_Sprite(EntityRef);
void        Entity_SetPos(EntityRef, uint32_t x, uint32_t y);

