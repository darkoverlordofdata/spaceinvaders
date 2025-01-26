#pragma once
/**
 *
 * Artemis ECS Framework
 *
 */
typedef enum ArtemisTaxonomy {
    ArtemisTaxonomy_BASIC, 
    ArtemisTaxonomy_POOLED
} ArtemisTaxonomy;

#include "Artemis/ArtemisAspect.h"                  // IWYU pragma: keep
#include "Artemis/ArtemisComponent.h"               // IWYU pragma: keep
#include "Artemis/ArtemisComponentManager.h"        // IWYU pragma: keep
#include "Artemis/ArtemisEntity.h"                  // IWYU pragma: keep
#include "Artemis/ArtemisEntityManager.h"           // IWYU pragma: keep
#include "Artemis/ArtemisEntitySystem.h"            // IWYU pragma: keep
#include "Artemis/ArtemisWorld.h"                   // IWYU pragma: keep
#include "Artemis/ArtemisComponentMapper.h"         // IWYU pragma: keep
#include "Artemis/ArtemisComponentPool.h"           // IWYU pragma: keep
#include "Artemis/ArtemisComponentType.h"           // IWYU pragma: keep
#include "Artemis/ArtemisComponentTypeFactory.h"    // IWYU pragma: keep
#include "Artemis/ArtemisSystemIndexManager.h"      // IWYU pragma: keep
#include "Artemis/ArtemisIdentifierPool.h"          // IWYU pragma: keep
