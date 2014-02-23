#include "modelld.h"
#include "toolkitld.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(ModelLD, AbstractModel)
IMPL_RSCLASS_GET(ModelLD)

IMPL_OBJECT_METHOD(ModelLD, getToolkit, ToolkitLD)
IMPL_ARRAY_METHOD(ModelLD, getTriangleAlphas, JByte)
IMPL_ARRAY_METHOD(ModelLD, getTriangleColors, JShort)
IMPL_PRIMITIVE_METHOD(ModelLD, getTriangleCount, JInt)
IMPL_ARRAY_METHOD(ModelLD, getTriangleX, JShort)
IMPL_ARRAY_METHOD(ModelLD, getTriangleY, JShort)
IMPL_ARRAY_METHOD(ModelLD, getTriangleZ, JShort)
IMPL_PRIMITIVE_METHOD(ModelLD, getVertexCount, JInt)
IMPL_ARRAY_METHOD(ModelLD, getVerticiesX, JInt)
IMPL_ARRAY_METHOD(ModelLD, getVerticiesY, JInt)
IMPL_ARRAY_METHOD(ModelLD, getVerticiesZ, JInt)

} // namespace bridge
} // namespace api
