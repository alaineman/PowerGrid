#ifndef API_BRIDGE_CAMERALOCATIONDATA_H
#define API_BRIDGE_CAMERALOCATIONDATA_H

#include "MethodHelper.h"
#include "abstractcameralocationdata.h"


namespace RS {

class EntityPosition;
class Quaternion;

/*!
 * \brief Represents the Camera Location.
 *
 * Uses the actual camera location \c Quaternion and the different angle and set-up
 * from the \c EntityPosition to correspond with the two camera styles in Runescape.
 *
 * \internal needs confirmation
 */
class CameraLocationData : public AbstractCameraLocationData {
public:
    RS_OBJECT(CameraLocationData)

    JACE_PROXY_API EntityPosition getPoint1();
    JACE_PROXY_API EntityPosition getPoint2();
    JACE_PROXY_API Quaternion getQuaternion();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_CAMERALOCATIONDATA_H
