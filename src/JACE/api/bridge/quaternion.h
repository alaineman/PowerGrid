#ifndef API_BRIDGE_QUATERNION_H
#define API_BRIDGE_QUATERNION_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

/*!
 * \brief Represents the Camera Location.
 *
 * The data of the location of the camera. This is build up with an
 * 3-dimensional coordinate system and an angle \c getA() method.
 *
 * \internal needs confirmation
 */
class Quaternion : public Object {
public:
    RS_OBJECT(Quaternion)

    JACE_PROXY_API JFloat getA();
    JACE_PROXY_API JFloat getX();
    JACE_PROXY_API JFloat getY();
    JACE_PROXY_API JFloat getZ();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_QUATERNION_H
