#ifndef API_BRIDGE_CANVAS_H
#define API_BRIDGE_CANVAS_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace java {
 namespace awt {
  class Component; // We don't have a specific AWT Canvas class.
 }
}

namespace api {
namespace bridge {

class Canvas : public Object {
public:
    RS_OBJECT(Canvas)

    JACE_PROXY_API java::awt::Component getInternalCanvas();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_CANVAS_H
