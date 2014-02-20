#include "entitynode.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(EntityNode)
IMPL_RSCLASS_GET(EntityNode)

IMPL_OBJECT_METHOD(EntityNode, getNext, EntityNode)
IMPL_OBJECT_METHOD(EntityNode, getPrevious, EntityNode)

} // namespace bridge
} // namespace api
