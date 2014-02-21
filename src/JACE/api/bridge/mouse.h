#ifndef API_BRIDGE_MOUSE_H
#define API_BRIDGE_MOUSE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Mouse : public Object {
public:
    RS_OBJECT(Mouse)
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_MOUSE_H
