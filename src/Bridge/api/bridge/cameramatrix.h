#ifndef API_BRIDGE_CAMERAMATRIX_H
#define API_BRIDGE_CAMERAMATRIX_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

/**
 * \brief Representation of the camera transformation matrix.
 *
 * The matrix is a 4x4 grid containing the values that are used to transform the
 * position, scale and rotation of the 3D models to fit the position of the camera.
 * This ensures that the correct part of the world is visible on screen.
 *
 * The values in the matrix directly relate to the translation, scaling and
 * rotation of the camera.
 *
 * \internal This is according to my knowledge of 3D rendering. Note that some
 *           implementations do not give the bottom row of the matrix,
 *           they provide a 4x3 matrix instead. The bottom row can be added
 *           as needed, with values (0,0,0,1).
 */
class CameraMatrix : public Object {
public:
    RS_OBJECT(CameraMatrix)

    /**
     * \brief a list of the values in the matrix.
     * \internal We need to test this to see in which order the values in the
     *           matrix are returned.
     */
    JACE_PROXY_API QList<JFloat> getFloats();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_CAMERAMATRIX_H
