#include "reference.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(Stream, NodeSub)
IMPL_RSCLASS_GET(Stream)

IMPL_PRIMITIVE_METHOD(Reference, getIndex, JInt)

} // namespace bridge
} // namespace api
