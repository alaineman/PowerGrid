#ifndef ABSTRACTCAMERA_H
#define ABSTRACTCAMERA_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class AbstractCameraLocationData;
class AbstractCentralLocationData;

/*!
 * \brief Abstract version of the Camera class.
 *
 * This class provides information about the Camera in the Runescape world.
 *
 * \internal needs confirmation (based on CameraLocationData)
 */
class AbstractCamera : public Object {
public:
    RS_OBJECT(AbstractCamera)

    /*!
     * \brief Returns the location of the focussed object of the Camera
     * \internal Is this it?
     */
    JACE_PROXY_API AbstractCameraLocationData getCameraLocationData();
    /*!
     * \brief Returns the actual location of the Camera.
     * \internal Is this it?
     */
    JACE_PROXY_API AbstractCentralLocationData getCentralLocationData();
private:
    DECLARE_FRIENDS
};

}
}



#endif // ABSTRACTCAMERA_H
