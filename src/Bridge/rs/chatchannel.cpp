#include "chatchannel.h"
#include "chatmessage.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(ChatChannel, NodeSub)
IMPL_RSCLASS_GET(ChatChannel)

IMPL_ARRAY_METHOD(ChatChannel, getMessages, ChatMessage)

} // namespace bridge
