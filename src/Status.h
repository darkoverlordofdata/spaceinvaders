#pragma once
#include "CFClass.h"
#include "CFObject.h"

typedef struct __Status* StatusRef;
extern CFClassRef Status;

typedef enum CategoryEntity : unsigned int {
    CategoryNA      = 0x0000,
    CategoryPlayer  = 0x0001,
    CategoryEnemy   = 0x0002,
    CategoryBullet  = 0x0004,

} CategoryEntity;


struct __Status {
    struct __CFObject obj;
    bool alive;
    CategoryEntity id;
} ;
