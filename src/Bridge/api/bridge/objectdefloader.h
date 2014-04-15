#ifndef API_BRIDGE_OBJECTDEFLOADER_H
#define API_BRIDGE_OBJECTDEFLOADER_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

// Forward declarations of Java API classes
namespace java {
namespace lang {
  class String;
}
}

namespace api {
namespace bridge {

class Cache;
class ObjectComposite;
class ObjectDefLoader : public Object {
public:
    RS_OBJECT(ObjectDefLoader)

    JACE_PROXY_API ObjectComposite getComposite();
    JACE_PROXY_API Cache getDefCache();
    JACE_PROXY_API QList<String> getGroundActions();
    JACE_PROXY_API Cache getModelCache();
    JACE_PROXY_API JBoolean isShowingActions();

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_OBJECTDEFLOADER_H
