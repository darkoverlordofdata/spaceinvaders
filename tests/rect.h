#pragma once
#include "shape.h" 

typedef struct __Rectangle* RectangleRef;
extern CFClassRef Rectangle;

struct __Rectangle {
    struct __Shape base; 
    int width;
    int height;
};

/**
 * RectangleArea
 * 
 */
static inline unsigned long RectangleArea(ShapeRef ptr) 
{
  RectangleRef this = (RectangleRef)ptr; 
  return (unsigned long)this->width * (unsigned long)this->height;
}

/**
 * RectangleDraw
 * 
 */
static inline void RectangleDraw(ShapeRef ptr) 
{
  RectangleRef this = (RectangleRef)ptr; 
  printf("Rectangle_draw_(x=%d,y=%d,width=%d,height=%d)\n", ShapeGetX(ptr),
          ShapeGetY(ptr), this->width, this->height);
}

