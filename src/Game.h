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

bool GameStart(GameRef);
bool GameUpdate(GameRef);
bool GameOver(GameRef);
bool GameMovementSystem(GameRef);
bool GameInputSystem(GameRef);
bool GameDrawSystem(GameRef);
bool GameCollisionSystem(GameRef);

