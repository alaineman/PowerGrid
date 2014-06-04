#ifndef API_BRIDGE_CHATLINE_H
#define API_BRIDGE_CHATLINE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace java {
namespace lang {
class String;
}
}

namespace api {
namespace bridge {

class ChatLine : public Object {
public:
    RS_OBJECT(ChatLine)

    /**
     * @brief Returns the message on this line
     * @return the message on this line.
     */
    JACE_PROXY_API String getMessage();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_CHATLINE_H
