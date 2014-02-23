#ifndef API_BRIDGE_CAMERALOCATIONDATA_H
#define API_BRIDGE_CAMERALOCATIONDATA_H

#include "MethodHelper.h"
#include "abstractcameralocationdata.h"

namespace api {
namespace bridge {

class EntityPosition;
class Quaternion;

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
} // namespace api

#endif // API_BRIDGE_CAMERALOCATIONDATA_H
