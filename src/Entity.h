#pragma once
#include "CFClass.h"
#include "Sprite.h"
#include "Component.h"

typedef struct __Entity* EntityRef;
extern CFClassRef Entity;

struct __Entity {
    struct __CFObject obj;
    AspectTypes aspect;
    void* component[32];

} ;


void EntityDraw(EntityRef entity);

bool EntityIntersect(EntityRef e1, EntityRef e2);    

bool EntityIsAlive(EntityRef);
void EntitySetAlive(EntityRef, bool);
uint32_t EntityX(EntityRef);
uint32_t EntityY(EntityRef);
SpriteRef EntitySprite(EntityRef);
void EntitySetPos(EntityRef, uint32_t x, uint32_t y);

