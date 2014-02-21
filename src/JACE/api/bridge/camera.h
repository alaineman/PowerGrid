#ifndef API_BRIDGE_CAMERA_H
#define API_BRIDGE_CAMERA_H

#include "MethodHelper.h"
#include "abstractcamera.h"

namespace api {
namespace bridge {

class Camera : public AbstractCamera {
public:
    RS_OBJECT(Camera)
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_CAMERA_H
