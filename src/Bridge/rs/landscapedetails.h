#ifndef API_BRIDGE_LANDSCAPEDETAILS_H
#define API_BRIDGE_LANDSCAPEDETAILS_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class Landscape;
class Tile;
class CameraMatrix;

class LandscapeDetails : public Object {
public:
    RS_OBJECT(LandscapeDetails)

    JACE_PROXY_API QList<Landscape> getLandscape();
    JACE_PROXY_API QList<QList<QList<Tile>>> getRegionData();
    JACE_PROXY_API CameraMatrix getCameraMatrix(); //TODO verify this.
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_LANDSCAPEDETAILS_H
