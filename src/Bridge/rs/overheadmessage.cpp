#include "overheadmessage.h"
#include "java/lang/string.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(OverheadMessage)
IMPL_RSCLASS_GET(OverheadMessage)

IMPL_OBJECT_METHOD(OverheadMessage, getMessage, String)

} // namespace bridge
