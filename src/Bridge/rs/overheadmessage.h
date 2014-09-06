#ifndef API_BRIDGE_OVERHEADMESSAGE_H
#define API_BRIDGE_OVERHEADMESSAGE_H

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

class OverheadMessage : public Object {
public:
    RS_OBJECT(OverheadMessage)

    JACE_PROXY_API String getMessage();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_OVERHEADMESSAGE_H
