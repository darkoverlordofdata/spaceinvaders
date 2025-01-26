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
bool ArtemisEntityManagerIsActive(ArtemisEntityManagerRef, int);
bool ArtemisEntityManagerIsEnaled(ArtemisEntityManagerRef, int);
ArtemisEntityRef ArtemisEntityManageGetEntity(ArtemisEntityManagerRef, int);
int ArtemisEntityManageGetActiveEntityCount(ArtemisEntityManagerRef);
int ArtemisEntityManageGetTotalCreated(ArtemisEntityManagerRef);
int ArtemisEntityManageGetTotalDeleted(ArtemisEntityManagerRef);




