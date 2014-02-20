#ifndef ABSTRACTCAMERA_H
#define ABSTRACTCAMERA_H

#include "MethodHelper.h"

#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class AbstractCameraLocationData;
class AbstractCentralLocationData;

class AbstractCamera : public Object {
public:
    RS_OBJECT(AbstractCamera)

    JACE_PROXY_API AbstractCameraLocationData getCameraLocationData();
    JACE_PROXY_API AbstractCentralLocationData getCentralLocationData();
private:
    DECLARE_FRIENDS
};

}
}



#endif // ABSTRACTCAMERA_H
