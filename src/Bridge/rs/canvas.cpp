#include "canvas.h"
#include "java/awt/component.h"

namespace RS {

IMPL_JACE_CONSTRUCTORS(Canvas)
IMPL_RSCLASS_GET(Canvas)

IMPL_OBJECT_METHOD(Canvas, getInternalCanvas, java::awt::Component)

} // namespace bridge
