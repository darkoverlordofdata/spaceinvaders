#pragma once
#include "../corefw.h" // IWYU pragma: keep
#include "../CF/CFArray.h"
#include "../Entity.h"

typedef struct __Game* GameRef;
typedef struct __DrawSystem* DrawSystemRef;
extern CFClassRef DrawSystem;

struct __DrawSystem {
    struct __CFObject obj;
    GameRef game;

};

void DrawSystem_ProcessEach(DrawSystemRef, EntityRef);
void DrawSystem_ProcessEntities(DrawSystemRef, CFArrayRef);
bool DrawSystem_CheckProcessing(DrawSystemRef);

