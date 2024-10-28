#include <stdbool.h>
#include "corefw.h" // IWYU pragma: keep
#include "Game.h"
#include "wasm4.h"





CFRefPoolRef pool = nullptr;
GameRef game;

void start() {
	pool = CFNew(CFRefPool);
    game = CFNew(Game);
    Game_Start(game);

}

/** 
 * update
 */
void update () {
    Game_Update(game);
}

