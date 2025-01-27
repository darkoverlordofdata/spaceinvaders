#pragma once
#include "../corefw.h" // IWYU pragma: keep0
/**
 *  @class ArtemisEntityManager
 */
extern CFClassRef ArtemisEntityManager;

typedef struct __ArtemisEntityManager*  ArtemisEntityManagerRef;
typedef struct __ArtemisWorld*          ArtemisWorldRef;
typedef struct __ArtemisEntity*         ArtemisEntityRef;

ArtemisEntityRef ArtemisEntityManagerCreateEntityInstance(ArtemisEntityManagerRef, CFStringRef);
void ArtemisEntityManagerAdded(ArtemisEntityManagerRef, ArtemisEntityRef);
void ArtemisEntityManagerEnabled(ArtemisEntityManagerRef, ArtemisEntityRef);
void ArtemisEntityManagerDisabled(ArtemisEntityManagerRef, ArtemisEntityRef);
void ArtemisEntityManagerDeleted(ArtemisEntityManagerRef, ArtemisEntityRef);
bool ArtemisEntityManagerIsActive(ArtemisEntityManagerRef, ulong);
bool ArtemisEntityManagerIsEnaled(ArtemisEntityManagerRef, ulong);
ArtemisEntityRef ArtemisEntityManageGetEntity(ArtemisEntityManagerRef, ulong);
ulong ArtemisEntityManageGetActiveEntityCount(ArtemisEntityManagerRef);
ulong ArtemisEntityManageGetTotalCreated(ArtemisEntityManagerRef);
ulong ArtemisEntityManageGetTotalDeleted(ArtemisEntityManagerRef);




