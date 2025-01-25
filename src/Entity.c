#include <stdbool.h>
#include "Entity.h"
#include "Component.h"
#include "Status.h"
#include "Position.h"
#include "Sprite.h"
#include "wasm4.h"


static bool
ctor(void *ptr, va_list args)
{
	EntityRef this = ptr;

    this->kind = (EntityType)va_arg(args, long);
    this->aspect = (AspectType)va_arg(args, long);

    for (void* component = va_arg(args, void*); component != NULL; component = va_arg(args, void*))
        this->component[ComponentSlot(component)] = component;
    return true;
}
uint32_t EntityX(EntityRef this)
{
    PositionRef pos = this->component[ComponentPosition];
    return (uint32_t)pos->x;
}
uint32_t EntityY(EntityRef this)
{
    PositionRef pos = this->component[ComponentPosition];
    return (uint32_t)pos->y;
}

void EntitySetPos(EntityRef this, uint32_t x, uint32_t y)
{
    PositionRef pos = this->component[ComponentPosition];
    pos->x = (long)x;
    pos->y = (long)y;
}

bool EntityIsAlive(EntityRef this)
{
    StatusRef status = this->component[ComponentStatus];
    return status->alive;
}

void EntitySetAlive(EntityRef this, bool value)
{
    StatusRef status = this->component[ComponentStatus];
    status->alive = value;
}
SpriteRef EntitySprite(EntityRef this)
{
    return (SpriteRef)this->component[ComponentSprite];
}

void EntityDraw(EntityRef this) {
    SpriteRef sprite = this->component[ComponentSprite];
    PositionRef pos = this->component[ComponentPosition];
    *DRAW_COLORS = sprite->colors;
    blit(sprite->data, (int)pos->x, (int)pos->y, 
        sprite->width, sprite->height, sprite->flags);
}

bool EntityIntersect(EntityRef this, EntityRef that) {
    SpriteRef sprite = this->component[ComponentSprite];

    PositionRef this_pos = this->component[ComponentPosition];
    StatusRef this_status = this->component[ComponentStatus];

    PositionRef that_pos = that->component[ComponentPosition];
    StatusRef that_status = that->component[ComponentStatus];

    if (this_status->alive && that_status->alive) {
        if (that_pos->x > this_pos->x && that_pos->x < this_pos->x + (long)sprite->width
        && that_pos->y > this_pos->y && that_pos->y < this_pos->y + (long)sprite->height)
            return true;
    }
    return false;
}


static struct __CFClass class = {
	.name = "Entity",
	.size = sizeof(struct __Entity),
	.ctor = ctor,
	// .equal = equal,
	// .hash = hash,
	// .copy = copy
};
CFClassRef Entity = &class;

