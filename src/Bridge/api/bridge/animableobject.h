#ifndef API_BRIDGE_ANIMABLEOBJECT_H
#define API_BRIDGE_ANIMABLEOBJECT_H

#include "MethodHelper.h"
#include "animable.h"

namespace api {
namespace bridge {

class ObjectDefLoader;
class ModelLD;

class AnimableObject : public Animable {
public:
    RS_OBJECT(AnimableObject)

    JACE_PROXY_API JInt getID();
    JACE_PROXY_API ModelLD getLDModel();
    JACE_PROXY_API JInt getLocationX();
    JACE_PROXY_API JInt getLocationY();
    JACE_PROXY_API ObjectDefLoader getObjectDefLoader();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ANIMABLEOBJECT_H
