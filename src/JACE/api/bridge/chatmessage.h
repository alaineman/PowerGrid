#ifndef API_BRIDGE_CHATMESSAGE_H
#define API_BRIDGE_CHATMESSAGE_H

#include "MethodHelper.h"
#include "nodesub.h"
using namespace java::lang;

namespace java {
 namespace lang {
  class String;
 }
}

namespace api {
namespace bridge {

class ChatMessage : public NodeSub {
public:
    RS_OBJECT(ChatMessage)

    JACE_PROXY_API String getClanChat();
    JACE_PROXY_API String getDisplayName();
    JACE_PROXY_API JInt getIndex();
    JACE_PROXY_API String getMessage();
    JACE_PROXY_API String getOther();
    JACE_PROXY_API String getSender();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_CHATMESSAGE_H
