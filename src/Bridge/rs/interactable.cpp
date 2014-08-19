#include "interactable.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(Interactable, EntityNode)
IMPL_RSCLASS_GET(Interactable)

IMPL_PRIMITIVE_METHOD(Interactable, getPlane, JByte)

} // namespace bridge
