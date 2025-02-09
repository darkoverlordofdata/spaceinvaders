#include "circle.h"  /* Circle class interface */
#include <stdio.h> /* for printf() */
#include <stdlib.h>

/**
 * constructor
 * 
 * @param {int} x
 * @param {int} y
 * @param {int} radius
 */
static bool 
ctor(void *ptr, va_list args)
{
    CircleRef this = ptr;
    Shape_ctor(&this->base, va_arg(args, int), va_arg(args, int));
    this->rad = va_arg(args, int); 

    static struct ShapeVtbl const vtbl = { &CircleArea, &CircleDraw };
    this->base.vptr = &vtbl;               

    return true;
}

/**
 * toString
 */
static CFStringRef 
toString(void *ptr) 
{
    CircleRef this = ptr; 
    const char* mask = "\t%s\n\tCircle x:%d y:%d rad:%d\n";

    CFStringRef s = Shape->toString(ptr);
    int len = snprintf(NULL, 0, "\t%s\n\tCircle x:%d y:%d rad:%d\n", CFStringC(s), this->base.x, this->base.y, this->rad);
    char* buffer = calloc(1, len+2);
    snprintf(buffer, len+1, "\t%s\n\tCircle x:%d y:%d rad:%d\n", CFStringC(s), this->base.x, this->base.y, this->rad);
    return CFCreate(CFString, buffer);
}


static struct __CFClass class = {
        .name = "Circle",
        .size = sizeof(struct __Circle),
        .ctor = ctor,
    .toString = toString
};
CFClassRef Circle = &class;


