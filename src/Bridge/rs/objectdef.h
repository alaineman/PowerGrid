#ifndef API_BRIDGE_OBJECTDEF_H
#define API_BRIDGE_OBJECTDEF_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

// Forward declarations of Java API classes
namespace java {
namespace lang {
  class String;
}
}


namespace RS {

class ObjectDefLoader;
class ObjectDef : public Object {
public:
    RS_OBJECT(ObjectDef)

    JACE_PROXY_API QList<String> getActions();
    JACE_PROXY_API JInt getID();
    JACE_PROXY_API QList<JShort> getModifiedColors();
    JACE_PROXY_API String getName();
    JACE_PROXY_API ObjectDefLoader getObjectDefLoader();
    JACE_PROXY_API QList<JShort> getOriginalColors();
    JACE_PROXY_API JBoolean isWalkable();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_OBJECTDEF_H
