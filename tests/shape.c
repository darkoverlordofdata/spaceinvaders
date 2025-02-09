#include "shape.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

static unsigned long _ShapeArea(ShapeRef this);
static void _ShapeDraw(ShapeRef this);

void Shape_ctor(void* ptr, int x, int y)
{
    ShapeRef this = ptr;
    this->x = x;
    this->y = y;

}


/**
 * constructor
 * 
 * @param {int} x
 * @param {int} y
 * @param {int} width
 */
static bool 
ctor(void *ptr, va_list args)
{
    ShapeRef this = ptr;
    Shape_ctor(this, va_arg(args, int), va_arg(args, int));

    // static struct ShapeVtbl const vtbl = { &_ShapeArea, &_ShapeDraw };
    // this->vptr = &vtbl;

    return true;
}

/**
 * toString
 */
static CFStringRef 
toString(void *ptr) 
{
    char* mask = "Shape x:%d y:%d";

    ShapeRef this = ptr;
    int len = snprintf(NULL, 0, mask, this->x, this->y);
    char* s = calloc(1, len+2);
    if (s == NULL) return NULL;
    snprintf(s, len+1, mask, this->x, this->y);
    CFStringRef str = CFCreate(CFString, s);
    free(s);
    return str;

}

// /**
//  * ShapeArea virtual function
//  */
// static unsigned long _ShapeArea(ShapeRef this) 
// {
//     (void)this;
//     assert(0);
//     return 0;

// }

// /**
//  * ShapeDraw virtual function
//  */
// static void _ShapeDraw(ShapeRef this) 
// {
//     (void)this;
//     assert(0);
// }



/**
 * ShapeMoveBy
 *
 * @param {int} dx
 * @param {int} dy
 */
void ShapeMoveBy(ShapeRef this, int dx, int dy) 
{
    this->x += dx;
    this->y += dy;
}


/**
 * ShapeGetX
 */
int ShapeGetX(ShapeRef this) 
{
    return this->x;
}

/**
 * ShapeGetX
 */
int ShapeGetY(ShapeRef this) 
{
    return this->y;
}


/**
 * ShapeLargestShape
 * 
 * finds the largest-area shape in the collection 
 */
ShapeRef ShapeLargestShape(CFArrayRef shapes) 
{
    ShapeRef s = NULL;//(Shape *)0;

    for (int i = 0, max=0; i < CFArraySize(shapes); ++i) {
        int area = ShapeArea(CFArrayGet(shapes, i)); /* virtual call */
        if (area > max) {
            max = area;
            s = CFArrayGet(shapes, i);
        }
    }
    return s; /* the largest shape in the array shapes[] */
}

/* 
 * ShapeDrawAllShapes
 *
 * draw all Shapes on the screen 
 */
void ShapeDrawAllShapes(CFArrayRef shapes) 
{
    for (int i = 0; i < CFArraySize(shapes); ++i) {
        ShapeDraw(CFArrayGet(shapes, i)); /* virtual call */
    }
}


static struct __CFClass class = {
        .name = "Shape",
        .size = sizeof(struct __Shape),
        .ctor = ctor,
    .toString = toString
};
CFClassRef Shape = &class;


