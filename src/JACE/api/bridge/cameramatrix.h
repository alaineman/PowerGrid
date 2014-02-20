#ifndef API_BRIDGE_CAMERAMATRIX_H
#define API_BRIDGE_CAMERAMATRIX_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class CameraMatrix : public Object {
public:
    RS_OBJECT(CameraMatrix)

    JACE_PROXY_API QList<JFloat> getID();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_CAMERAMATRIX_H
