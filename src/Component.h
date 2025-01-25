#pragma once
#include "corefw.h" // IWYU pragma: keep

typedef struct __Component* ComponentRef;
extern CFClassRef Component;
extern CFClassRef Status;
extern CFClassRef Position;
extern CFClassRef Sprite;


struct __Component {
    struct __CFObject obj;

} ;

int ComponentSlot(void* component);


typedef enum AspectType : unsigned int {
    AspectUnused     = 0x0000,
    AspectStatus     = 0x0001,
    AspectPosition   = 0x0002,
    AspectSprite     = 0x0004,

} AspectType;

typedef enum ComponentType : unsigned int {
    ComponentUnused     = 0,
    ComponentStatus     = 1,
    ComponentPosition   = 2,
    ComponentSprite     = 3,

} ComponentTypes;

typedef enum EntityType : unsigned int {
    EntityUnknown       = 0,
    EntityPlayer        = 1,
    EntityBullet        = 2,
    EntityEnemy         = 3,

} EntityType;



