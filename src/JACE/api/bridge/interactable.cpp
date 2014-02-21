#include "interactable.h"


namespace api {
namespace bridge {
IMPL_JACE_CONSTRUCTORS(Interactable)
IMPL_RSCLASS_GET(Interactable)

IMPL_PRIMITIVE_METHOD(Interactable, getPlane, JByte)

} // namespace bridge
} // namespace api
