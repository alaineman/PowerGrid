#include "reference.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(Reference, NodeSub)
IMPL_RSCLASS_GET(Reference)

IMPL_PRIMITIVE_METHOD(Reference, getIndex, JInt)

} // namespace bridge
} // namespace api
