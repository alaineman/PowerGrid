#ifndef API_BRIDGE_INTERACTABLEANIMATOR_H
#define API_BRIDGE_INTERACTABLEANIMATOR_H

#include "MethodHelper.h"
#include "animator.h"
using namespace java::lang;


namespace RS {

class Interactable;
class InteractableAnimator : public Animator {
public:
    RS_OBJECT(InteractableAnimator)

    JACE_PROXY_API Interactable getEntity();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_INTERACTABLEANIMATOR_H
