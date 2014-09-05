#include "interface.h"
#include "interfacechild.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(Interface)
IMPL_RSCLASS_GET(Interface)

IMPL_ARRAY_METHOD(Interface, getChildren, InterfaceChild)

} // namespace bridge
