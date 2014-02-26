#ifndef API_BRIDGE_ANIMATOR_H
#define API_BRIDGE_ANIMATOR_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Animation;

/**
 * \brief Performs animations
 *
 * This class is often used by objects in the Runescape world to perform some
 * kind of animation. It holds a reference to the Animation it performs.
 */
class Animator : public Object {
public:
    RS_OBJECT(Animator)

    /**
     * \brief the animation this Animator performs
     */
    JACE_PROXY_API Animation getAnimation();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ANIMATOR_H
