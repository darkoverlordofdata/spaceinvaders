#pragma once
#include <stdint.h>
// #include <stdio.h>
#include "corefw.h"

typedef struct __Shape* ShapeRef;
extern CFClassRef Shape;

struct ShapeVtbl; 

struct __Shape {
    struct __CFObject obj;
    struct ShapeVtbl const *vptr; 
    int x; 
    int y; 
};

struct ShapeVtbl {
    unsigned long (*area)(ShapeRef );
    void (*draw)(ShapeRef );
};

void Shape_ctor(void*, int, int);

void ShapeMoveBy(ShapeRef, int, int);
int ShapeGetX(ShapeRef);
int ShapeGetY(ShapeRef);

ShapeRef ShapeLargestShape(CFArrayRef);
void ShapeDrawAllShapes(CFArrayRef);

/**
 * ShapeArea
 * virtual function
 * 
 */
static inline unsigned long ShapeArea(ShapeRef this) 
{
    return (*this->vptr->area)(this);
}

/**
 * ShapeDraw
 * virtual function
 * 
 */
static inline void ShapeDraw(ShapeRef this) 
{
    (*this->vptr->draw)(this);
}
