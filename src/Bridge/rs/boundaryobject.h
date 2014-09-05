#ifndef API_BRIDGE_BOUNDARYOBJECT_H
#define API_BRIDGE_BOUNDARYOBJECT_H

#include "MethodHelper.h"
#include "boundary.h"


namespace RS {

class ModelLD;
class ObjectDefLoader;

class BoundaryObject : public Boundary {
public:
    RS_OBJECT(BoundaryObject)

    JACE_PROXY_API JInt getID();
    JACE_PROXY_API ModelLD getModel();
    JACE_PROXY_API JDouble getLocalX();
    JACE_PROXY_API JDouble getLocalY();
    JACE_PROXY_API JInt getLocationX();
    JACE_PROXY_API JInt getLocationY();
    JACE_PROXY_API ObjectDefLoader getObjectDefLoader();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_BOUNDARYOBJECT_H
