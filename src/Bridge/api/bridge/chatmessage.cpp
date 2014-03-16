#include "chatmessage.h"
#include "java/lang/string.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(ChatMessage, NodeSub)
IMPL_RSCLASS_GET(ChatMessage)

IMPL_OBJECT_METHOD(ChatMessage, getClanChat, String)
IMPL_OBJECT_METHOD(ChatMessage, getDisplayName, String)
IMPL_PRIMITIVE_METHOD(ChatMessage, getIndex, JInt)
IMPL_OBJECT_METHOD(ChatMessage, getMessage, String)
IMPL_OBJECT_METHOD(ChatMessage, getOther, String)
IMPL_OBJECT_METHOD(ChatMessage, getSender, String)

} // namespace bridge
} // namespace api
