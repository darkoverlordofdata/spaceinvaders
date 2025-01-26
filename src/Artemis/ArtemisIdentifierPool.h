#pragma once
#include "../corefw.h" // IWYU pragma: keep
/*
 * Used only internally to generate distinct ids for entities and reuse them.
 */
typedef struct __ArtemisIdentifierPool* ArtemisIdentifierPoolRef;
extern CFClassRef ArtemisIdentifierPool;


struct __ArtemisIdentifierPool {
    struct __CFObject   obj;
    CFArrayRef ids;
    int nextAvailableId;
};

int ArtemisIdentifierPoolCheckOut(ArtemisIdentifierPoolRef);
void ArtemisIdentifierPoolCheckIn(ArtemisIdentifierPoolRef, int);