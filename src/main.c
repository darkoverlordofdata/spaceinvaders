#include <stdbool.h>
// #include <stdio.h>
#include "CFRefPool.h"
#include "CFObject.h"
#include "CFArray.h"
#include "wasm4.h"
#include "util.h"
#include "Entity.h"
#include "Factory.h"
#include "Sprite.h"
// #include "Block.h"

EntityRef player;
CFArrayRef enemies;
CFArrayRef bullets;

const int RgbGrey   = 0x746f76;
const int RgbRed    = 0x951f15;
const int RgbOrange = 0xca3f14;
const int RgbBlue   = 0x1e1994;

// game
bool lost = false;
bool not_played = true;

typedef void (^FireBullet)(uint32_t, uint32_t);


int gun_cooldown = 0;
const int gun_cooldown_max = 15;
uint8_t gamepad = 0;

const int x_timer_reset = 5;
const int x_direction_timer_reset = x_timer_reset * 29;
int enemy_x_timer = x_timer_reset;
int enemy_x_change_direction_timer = x_direction_timer_reset;

uint32_t enemy_x_movement = 1;
uint32_t enemy_y_movement = 1;


CFRefPoolRef pool = nullptr;

EntityRef PlayerEntity;
CFArrayRef BulletEntities;
CFArrayRef EnemyEntities;

void start() {
	pool = CFNew(CFRefPool);

    void (^block)() = ^{
        PlayerEntity = CreatePlayer();
        BulletEntities = CFCreate(CFArray, NULL);
        for (int i=0; i<8; i++) {
            CFArrayPush(BulletEntities, CreateBullet());
        }
        EnemyEntities = CFCreate(CFArray, NULL);
        for (int row=0; row<3; row++) {
            for (int col=1; col<9; col++) {
                CFArrayPush(EnemyEntities, CreateEnemy(17*col - 14, 17*row + 3));
            }
        }
    };
    block();

}

/** 
 * update
 */
void update () {

	PALETTE[0]=RgbGrey;
	PALETTE[1]=RgbRed;
	PALETTE[2]=RgbOrange;
    PALETTE[3]=RgbBlue;

    if (lost) {
        PALETTE[0]=RgbRed;
        PALETTE[1]=RgbGrey;
        PALETTE[2]=RgbOrange;
        PALETTE[3]=RgbBlue;


        *DRAW_COLORS = 0b0000000000000011;
        if (not_played) {
            tone(100 | 2000 << 16, 60, 100, TONE_NOISE | TONE_MODE2);
            not_played = false;
        }
        text("Loser!", 60, 10);
        text("SKILL ISSUE!", 35, 20);
        return;
    }

    // input system
    uint32_t x1 = EntityX(PlayerEntity);
    uint32_t y1 = EntityY(PlayerEntity);
    uint32_t w1 = EntitySprite(PlayerEntity)->width;

    gamepad = *GAMEPAD1;

    if (gamepad & BUTTON_LEFT) {
        x1 -=1;
    }
    if (gamepad & BUTTON_RIGHT) {
        x1 +=1;
    }
 
    EntitySetPos(PlayerEntity, clamp(x1, 0, 160-w1), y1);


    gun_cooldown -= 1;

    // void (^fireBullet)(uint32_t, uint32_t) = ^(uint32_t x, uint32_t y){
    FireBullet fire = ^(uint32_t x, uint32_t y){

        for (size_t index=0; index < CFArraySize(BulletEntities); index++) {
            EntityRef bullet = CFArrayGet(BulletEntities, index);
            if (!EntityIsAlive(bullet)) {
                tone(800 | 200 << 16, 5, 100, TONE_TRIANGLE);
                gun_cooldown = gun_cooldown_max;
                EntitySetAlive(bullet, true);
                EntitySetPos(bullet, x, y);
                break;
            }
        }
    };


    if ((gamepad & BUTTON_1) != 0 && gun_cooldown < 0) {
        fire(EntityX(PlayerEntity)+18, EntityY(PlayerEntity)+2);
        fire(EntityX(PlayerEntity)+1, EntityY(PlayerEntity)+2);
    }

    EntityDraw(PlayerEntity);

    for (size_t index=0; index < CFArraySize(BulletEntities); index++) {
        EntityRef bullet = CFArrayGet(BulletEntities, index);
        if (EntityIsAlive(bullet)) {
            x1 = EntityX(bullet);
            long y2 = (long)EntityY(bullet) - 4;

            if (y2 < 0) {
                EntitySetAlive(bullet, false);
            }
            EntitySetPos(bullet, x1, (uint32_t)y2);
            EntityDraw(bullet);
        }
    }

    *DRAW_COLORS = 0b0010001101000000;

    enemy_x_timer -= 1;
    enemy_x_change_direction_timer -= 1;
    enemy_y_movement = 0;
    if (enemy_x_change_direction_timer <= 0) {
        enemy_x_movement = -enemy_x_movement;
        enemy_y_movement = 5;
        enemy_x_change_direction_timer = x_direction_timer_reset;
    }

    bool alive = false;
    for (size_t index=0; index < CFArraySize(EnemyEntities); index++) {
        EntityRef enemy = CFArrayGet(EnemyEntities, index);
        alive = alive | EntityIsAlive(enemy);
    }
 
    *DRAW_COLORS = 0b0000000000000010;
    if(!alive) {
        text("You're Winner", 31, 40);
        if (not_played) {
            tone(100 | 2000 << 16, 60, 100, TONE_TRIANGLE | TONE_MODE2);
            not_played = false;
        }
        return;
    }


    // collision system
    for (size_t enemy_index=0; enemy_index < CFArraySize(EnemyEntities); enemy_index++) {
        EntityRef enemy = CFArrayGet(EnemyEntities, enemy_index);
        for (size_t bullet_index=0; bullet_index < CFArraySize(BulletEntities); bullet_index++) {
            EntityRef bullet = CFArrayGet(BulletEntities, bullet_index);
            if (EntityIntersect(enemy, bullet)) {
                tone(800 | 200 << 16, 20, 70, TONE_NOISE);
                EntitySetAlive(bullet, false);
                EntitySetAlive(enemy, false);
            }
        }
        if (enemy_x_timer <= 0) {
            x1 = EntityX(enemy) + enemy_x_movement;
            y1 = EntityY(enemy) + enemy_y_movement;
            EntitySetPos(enemy, x1, y1);
            if (EntityIsAlive(enemy) && y1 > 120) {
                lost = true;
            }
        }
        if (EntityIsAlive(enemy)) {
            EntityDraw(enemy);
        }
    }

    if(enemy_x_timer <= 0) {
        enemy_x_timer = x_timer_reset;
    }


}

