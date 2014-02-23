#include "server.h"
#include "java/lang/string.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(Server, AbstractServer)
IMPL_RSCLASS_GET(Server)

IMPL_OBJECT_METHOD(Server, getActivity, String)
IMPL_OBJECT_METHOD(Server, getAddress, String)
IMPL_PRIMITIVE_METHOD(Server, getID, JLong)

} // namespace bridge
} // namespace api
