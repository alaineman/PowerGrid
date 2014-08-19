#ifndef ANIMATION_H
#define ANIMATION_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

/*!
 * \brief Represents a single animation
 *
 * Animator objects make use of this class to specify the animation to perform.
 */
class Animation : public Object {
public:
    RS_OBJECT(Animation)

    /*!
     * \brief Retunrns the unique id for the animation
     */
    JACE_PROXY_API JInt getID();
    JACE_PROXY_API JInt getShieldDisplayed();
    JACE_PROXY_API JInt getWalkingProperties();
    JACE_PROXY_API JInt getWeaponDisplayed();

private:
    DECLARE_FRIENDS
};

}
#endif // ANIMATION_H
