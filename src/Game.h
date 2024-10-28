#pragma once
#include "corefw.h" // IWYU pragma: keep

#include "Entity.h"

typedef struct __Game* GameRef;
extern CFClassRef Game;

struct __Game {
    struct __CFObject obj;
    bool lost;
    bool notPlayed;
    int gunCooldown;
    int enemyXTimer;
    int enemyXChangeDirectionTimer;
    UInt32 enemyXMovement;
    UInt32 enemyYMovement;
    EntityRef player;
    CFArrayRef enemies;
    CFArrayRef bullets;

};

bool Game_Start(GameRef);
bool Game_Update(GameRef);
bool Game_Over(GameRef);
bool Game_MovementSystem(GameRef);
bool Game_InputSystem(GameRef);
bool Game_DrawSystem(GameRef);
bool Game_CollisionSystem(GameRef);

