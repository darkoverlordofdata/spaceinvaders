#pragma once
#include <stdbool.h>
// #include <stdio.h>
// #include "wasm4.h"
// #include "CFRefPool.h"
// #include "CFObject.h"
// #include "CFArray.h"
#include "Entity.h"
// #include "Component.h"
// #include "Status.h"
// #include "Position.h"
// #include "Sprite.h"


EntityRef CreatePlayer();
EntityRef CreateBullet();
EntityRef CreateEnemy(int x, int y);