#pragma once
#include "../CF/CFArray.h"
#include "../Entity.h"
// #include "Game.h"
#include "../corefw.h" // IWYU pragma: keep


typedef struct __Game* GameRef;
typedef struct __MovementSystem* MovementSystemRef;
extern CFClassRef MovementSystem;

struct __MovementSystem {
    struct __CFObject obj;
    GameRef game;

};

void MovementSystem_ProcessEach(MovementSystemRef, EntityRef);
void MovementSystem_ProcessEntities(MovementSystemRef, CFArrayRef);
bool MovementSystem_CheckProcessing(MovementSystemRef);

