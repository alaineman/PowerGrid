#include "canvas.h"
#include "java/awt/component.h"
namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(Canvas)
IMPL_RSCLASS_GET(Canvas)

IMPL_OBJECT_METHOD(Canvas, getInternalCanvas, java::awt::Component)

} // namespace bridge
} // namespace api
