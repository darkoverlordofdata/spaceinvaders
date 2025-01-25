#pragma once
#include "../CF/CFArray.h"
#include "../Entity.h"
// #include "Game.h"
#include "../corefw.h" // IWYU pragma: keep


typedef struct __Game* GameRef;
typedef struct __InputSystem* InputSystemRef;
extern CFClassRef InputSystem;

struct __InputSystem {
    struct __CFObject obj;
    GameRef game;

};

void InputSystem_ProcessEach(InputSystemRef, EntityRef);
void InputSystem_ProcessEntities(InputSystemRef, CFArrayRef);
bool InputSystem_CheckProcessing(InputSystemRef);

