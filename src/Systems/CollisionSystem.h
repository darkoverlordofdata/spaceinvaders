#pragma once
#include "../CF/CFArray.h"
#include "../Entity.h"
// #include "Game.h"
#include "../corefw.h" // IWYU pragma: keep


typedef struct __Game* GameRef;
typedef struct __CollisionSystem* CollisionSystemRef;
extern CFClassRef CollisionSystem;

struct __CollisionSystem {
    struct __CFObject obj;
    GameRef game;
    int xTimer;
    int xChangeDirectionTimer;
    UInt32 xMovement;
    UInt32 yMovement;

};

void CollisionSystem_ProcessEach(CollisionSystemRef, EntityRef);
void CollisionSystem_ProcessEntities(CollisionSystemRef, CFArrayRef);
bool CollisionSystem_CheckProcessing(CollisionSystemRef);

