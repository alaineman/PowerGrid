#ifndef API_BRIDGE_ITEMDEF_H
#define API_BRIDGE_ITEMDEF_H

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

class HashTable;
class ItemDefLoader;
class ItemDef : public Object {
public:
    RS_OBJECT(ItemDef)

    JACE_PROXY_API QList<String> getActions();
    JACE_PROXY_API QList<String> getGroundActions();
    JACE_PROXY_API JInt getID();
    JACE_PROXY_API ItemDefLoader getItemDefLoader();
    JACE_PROXY_API String getName();
    JACE_PROXY_API HashTable getNodeTable();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ITEMDEF_H
