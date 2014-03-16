#include "abstractserver.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(AbstractServer)
IMPL_RSCLASS_GET(AbstractServer)

IMPL_PRIMITIVE_METHOD(AbstractServer, getFlag, JInt)

}
}
