#pragma once
#include "../corefw.h" // IWYU pragma: keep
/**
 * A tag class. All components in the system must extend this class.
 * 
 * @author Arni Arent
 */
extern CFClassRef ArtemisComponent;
typedef struct __ArtemisComponent* ArtemisComponentRef;

struct __ArtemisComponent {
    struct __CFObject obj;

} ;

