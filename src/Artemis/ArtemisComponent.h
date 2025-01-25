#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
 * A tag class. All components in the system must extend this class.
 * 
 * @author Arni Arent
 */
typedef struct __ArtemisComponent* ArtemisComponentRef;
extern CFClassRef ArtemisComponent;

struct __ArtemisComponent {
    struct __CFObject obj;

} ;

