#include "rect.h"  /* Rectangle class interface */
#include <stdio.h> /* for printf() */
#include <stdlib.h>

/**
 * constructor
 * 
 * @param {int} x
 * @param {int} y
 * @param {int} width
 * @param {int} height
 */
static bool 
ctor(void *ptr, va_list args) 
{
    RectangleRef this = ptr;
    Shape_ctor(&this->base, va_arg(args, int), va_arg(args, int));
    this->width = va_arg(args, int); 
    this->height = va_arg(args, int);

    static struct ShapeVtbl const vtbl = {&RectangleArea, &RectangleDraw };
    this->base.vptr = &vtbl;    

    return true;
}


/**
 * toString
 */
static CFStringRef 
toString(void *ptr) 
{
    RectangleRef this = ptr;
    CFStringRef s = Shape->toString(ptr);

    const char *mask = "\t%s\n\tRectangle x:%d y:%d width:%d height:%d\n";


    int len = snprintf(NULL, 0, mask, CFStringC(s), this->base.x,
                        this->base.y, this->width, this->height);
    char *buffer = calloc(1, len + 2);
    snprintf(buffer, len + 1, "\t%s\n\tRectangle x:%d y:%d width:%d height:%d\n",
                CFStringC(s), this->base.x, this->base.y, this->width,
                this->height);
    return CFCreate(CFString, buffer);
}

static struct __CFClass class = {
        .name = "Rectangle",
        .size = sizeof(struct __Rectangle),
        .ctor = ctor,
    .toString = toString
};
CFClassRef Rectangle = &class;
