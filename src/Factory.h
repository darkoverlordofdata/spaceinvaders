#pragma once
#include <stdbool.h>
#include "Entity.h"


EntityRef CreatePlayer();
EntityRef CreateBullet();
EntityRef CreateEnemy(int x, int y);