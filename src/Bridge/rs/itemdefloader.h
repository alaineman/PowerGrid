#ifndef API_BRIDGE_ITEMDEFLOADER_H
#define API_BRIDGE_ITEMDEFLOADER_H

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

class Cache;
class ItemDefLoader : public Object {
public:
    RS_OBJECT(ItemDefLoader)

    JACE_PROXY_API QList<String> getDefaultActions();
    JACE_PROXY_API QList<String> getDefaultGroundActions();
    JACE_PROXY_API JInt getItemCount();
    JACE_PROXY_API Cache getItemDefCache();
    JACE_PROXY_API Cache getItemModelCache();
    JACE_PROXY_API JInt getLanguage();
    JACE_PROXY_API JBoolean isMembers();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_ITEMDEFLOADER_H
