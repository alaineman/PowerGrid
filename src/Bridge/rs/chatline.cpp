#include "chatline.h"

#include "java/lang/string.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(ChatLine)
IMPL_RSCLASS_GET(ChatLine)

IMPL_OBJECT_METHOD(ChatLine, getMessage, String)

} // namespace bridge
