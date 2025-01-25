#pragma once
#include "../corefw.h" // IWYU pragma: keep0
/**
 * Used to generate a unique bit for each system.
 * Only used internally in EntitySystem.
 */
int ArtemisSystemIndexManagerGetIndexFor(CFClassRef es);
