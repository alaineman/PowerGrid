#include "graphicstoolkit.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(GraphicsToolkit)
IMPL_RSCLASS_GET(GraphicsToolkit)

IMPL_PRIMITIVE_METHOD(GraphicsToolkit, getIndex, JInt)

} // namespace bridge
} // namespace api
