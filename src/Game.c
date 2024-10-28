#include "Game.h"
#include "wasm4.h"
#include "util.h"
#include "Factory.h"

typedef void (^FireBullet)(UInt32, UInt32);

const int RgbGrey               = 0xfbf7f3; // seashell
const int RgbRed                = 0x20283d; // mainly red
const int RgbOrange             = 0xe5b083; // medium light orange
const int RgbGreen              = 0x426e5d; // mostly green
const int GunCooldownMax        = 15;       // timeout between shots
const int XTimerReset           = 5;
const int XDirectionTimerReset  = XTimerReset * 29;



static bool
ctor(void *ptr, va_list args)
{
	(void)args;
	GameRef this = ptr;
	return true;
}

bool Game_Start(GameRef this) 
{
	this->lost = false;
	this->notPlayed = true;
    this->gunCooldown = 0;
    this->enemyXTimer = XTimerReset;
    this->enemyXChangeDirectionTimer = XDirectionTimerReset;

    this->enemyXMovement = 1;
    this->enemyYMovement = 1;
	
	void (^block)() = ^{

		this->player = CreatePlayer();
		this->bullets = CFCreate(CFArray, NULL);
		for (int i=0; i<8; i++) {
			CFArray_Push(this->bullets, CreateBullet());
		}
		this->enemies = CFCreate(CFArray, NULL);
		for (int row=0; row<3; row++) {
			for (int col=1; col<9; col++) {
				CFArray_Push(this->enemies, CreateEnemy(17*col - 14, 17*row + 3));
			}
		}
	};
	block();
	return true;
}

bool Game_Update(GameRef this)
{
    if (Game_Over(this)) return true;
    Game_InputSystem(this);
    Game_MovementSystem(this);
    Game_DrawSystem(this);
    Game_CollisionSystem(this);
	return true;
}



bool Game_Over(GameRef this)
{
    //
    // display status
    //
	PALETTE[0]=RgbGrey;
	PALETTE[1]=RgbRed;
	PALETTE[2]=RgbOrange;
    PALETTE[3]=RgbGreen;
    *DRAW_COLORS = 0b0010001101000000;

    if (this->lost) {
        PALETTE[0]=RgbRed;
        PALETTE[1]=RgbGrey;
        PALETTE[2]=RgbOrange;
        PALETTE[3]=RgbGreen;


        *DRAW_COLORS = 0b0000000000000011;
        if (this->notPlayed) {
            tone(100 | 2000 << 16, 60, 100, TONE_NOISE | TONE_MODE2);
            this->notPlayed = false;
        }
        text("Loser!", 60, 10);
        text("SKILL ISSUE!", 35, 20);
        return true;
    }
    bool alive = false;
    for (ulong index=0; index < CFArray_Size(this->enemies); index++) {
        EntityRef enemy = CFArray_Get(this->enemies, index);
        alive = alive | Entity_IsAlive(enemy);
    }
 
    if(!alive) {
       *DRAW_COLORS = 0b0000000000000010;
        text("You're Winner", 31, 40);
        if (this->notPlayed) {
            tone(100 | 2000 << 16, 60, 100, TONE_TRIANGLE | TONE_MODE2);
            this->notPlayed = false;
        }
        return true;
    }
    return false;

}


bool Game_InputSystem(GameRef this)
{
    //
    // input system
    //
    this->gunCooldown -= 1;
    FireBullet Fire = ^(UInt32 x, UInt32 y){

        for (ulong index=0; index < CFArray_Size(this->bullets); index++) {
            EntityRef bullet = CFArray_Get(this->bullets, index);
            if (!Entity_IsAlive(bullet)) {
                tone(800 | 200 << 16, 5, 100, TONE_TRIANGLE);
                this->gunCooldown = GunCooldownMax;
                Entity_SetAlive(bullet, true);
                Entity_SetPos(bullet, x, y);
                break;
            }
        }
    };


    if ((*GAMEPAD1 & BUTTON_1) != 0 && this->gunCooldown < 0) {
        Fire(Entity_X(this->player)+18, Entity_Y(this->player)+2);
        Fire(Entity_X(this->player)+1, Entity_Y(this->player)+2);
    }
    return true;

}

bool Game_MovementSystem(GameRef this)
{
    int delta = 0;

    if (*GAMEPAD1 & BUTTON_LEFT) {
        delta = -1;
    }
    if (*GAMEPAD1 & BUTTON_RIGHT) {
        delta = +1;
    }
    int x = (int)Entity_X(this->player);
    UInt32 y = Entity_Y(this->player);
    UInt32 w = Entity_Sprite(this->player)->width;

    Entity_SetPos(this->player, clamp((UInt32)(x+delta), 0, 160-w), y);

    for (ulong index=0; index < CFArray_Size(this->bullets); index++) {
        EntityRef bullet = CFArray_Get(this->bullets, index);
        if (Entity_IsAlive(bullet)) {
            UInt32 x1 = Entity_X(bullet);
            long y1 = (long)Entity_Y(bullet) - 4;

            if (y1 < 0) {
                Entity_SetAlive(bullet, false);
            }
            Entity_SetPos(bullet, x1, (UInt32)y1);
        }
    }


    return true;
}


bool Game_DrawSystem(GameRef this)
{
    Entity_Draw(this->player);

    for (ulong index=0; index < CFArray_Size(this->bullets); index++) {
        EntityRef bullet = CFArray_Get(this->bullets, index);
        if (Entity_IsAlive(bullet)) {
            Entity_Draw(bullet);
        }
    }


    return true;
}

bool Game_CollisionSystem(GameRef this)
{
    //
    // collision system
    //
    this->enemyXTimer -= 1;
    this->enemyXChangeDirectionTimer -= 1;
    this->enemyYMovement = 0;
    if (this->enemyXChangeDirectionTimer <= 0) {
        this->enemyXMovement = -this->enemyXMovement;
        this->enemyYMovement = 5;
        this->enemyXChangeDirectionTimer = XDirectionTimerReset;
    }

    for (ulong enemy_index=0; enemy_index < CFArray_Size(this->enemies); enemy_index++) {
        EntityRef enemy = CFArray_Get(this->enemies, enemy_index);
        for (ulong bullet_index=0; bullet_index < CFArray_Size(this->bullets); bullet_index++) {
            EntityRef bullet = CFArray_Get(this->bullets, bullet_index);
            if (Entity_Intersect(enemy, bullet)) {
                tone(800 | 200 << 16, 20, 70, TONE_NOISE);
                Entity_SetAlive(bullet, false);
                Entity_SetAlive(enemy, false);
            }
        }
        if (this->enemyXTimer <= 0) {
            UInt32 x1 = Entity_X(enemy) + this->enemyXMovement;
            UInt32 y1 = Entity_Y(enemy) + this->enemyYMovement;
            Entity_SetPos(enemy, x1, y1);
            if (Entity_IsAlive(enemy) && y1 > 120) {
                this->lost = true;
            }
        }
        if (Entity_IsAlive(enemy)) {
            Entity_Draw(enemy);
        }
    }

    if(this->enemyXTimer <= 0) {
        this->enemyXTimer = XTimerReset;
    }
    return true;
}

static struct __CFClass class = {
	.name = "Game",
	.size = sizeof(struct __Game),
	.ctor = ctor,
	// .equal = equal,
	// .hash = hash,
	// .copy = copy
};
CFClassRef Game = &class;

