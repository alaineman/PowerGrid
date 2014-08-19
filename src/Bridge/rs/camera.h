#ifndef API_BRIDGE_CAMERA_H
#define API_BRIDGE_CAMERA_H

#include "MethodHelper.h"
#include "abstractcamera.h"


namespace RS {

class Camera : public AbstractCamera {
public:
    RS_OBJECT(Camera)
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_CAMERA_H
