#pragma once
#include "shape.h" 

typedef struct __Circle* CircleRef;
extern CFClassRef Circle;

struct __Circle {
    struct __Shape base; 
    int rad;
};

/**
 * CircleArea
 * 
 */
static inline unsigned long CircleArea(ShapeRef ptr) 
{
    CircleRef this = (CircleRef)ptr; 
    return 3U * this->rad * this->rad;
}

/**
 * CircleDraw
 * 
 */
static inline void CircleDraw(ShapeRef ptr) 
{
    CircleRef this = (CircleRef)ptr;
    printf("Circle_draw_(x=%d,y=%d,rad=%d)\n", this->base.x, this->base.y, this->rad);
}
