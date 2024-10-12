#include <stdbool.h>
#include "corefw.h" // IWYU pragma: keep
#include "Game.h"
#include "wasm4.h"





CFRefPoolRef pool = nullptr;
GameRef game;

void start() {
	pool = CFNew(CFRefPool);
    game = CFNew(Game);
    GameStart(game);

}

/** 
 * update
 */
void update () {
    GameUpdate(game);
}

