#ifndef API_BRIDGE_CHATCHANNEL_H
#define API_BRIDGE_CHATCHANNEL_H

#include "MethodHelper.h"
#include "nodesub.h"

namespace api {
namespace bridge {

class ChatMessage;
class ChatChannel : public NodeSub {
public:
    RS_OBJECT(ChatChannel)

    JACE_PROXY_API QList<ChatMessage> getMessages();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_CHATCHANNEL_H
