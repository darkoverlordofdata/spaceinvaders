#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
 *  @class ArtemisIdentifierPool
 */
extern CFClassRef ArtemisIdentifierPool;

typedef struct __ArtemisIdentifierPool* ArtemisIdentifierPoolRef;

int ArtemisIdentifierPoolCheckOut(ArtemisIdentifierPoolRef);
void ArtemisIdentifierPoolCheckIn(ArtemisIdentifierPoolRef, int);