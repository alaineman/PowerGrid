#include "modeldirectx.h"
#include "toolkitdirectx.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(ModelDirectX, AbstractModel)
IMPL_RSCLASS_GET(ModelDirectX)

IMPL_OBJECT_METHOD(ModelDirectX, getToolkit, ToolkitDirectX)
IMPL_ARRAY_METHOD(ModelDirectX, getTriangleAlphas, JByte)
IMPL_ARRAY_METHOD(ModelDirectX, getTriangleColors, JShort)
IMPL_PRIMITIVE_METHOD(ModelDirectX, getTriangleCount, JInt)
IMPL_ARRAY_METHOD(ModelDirectX, getTriangleX, JShort)
IMPL_ARRAY_METHOD(ModelDirectX, getTriangleY, JShort)
IMPL_ARRAY_METHOD(ModelDirectX, getTriangleZ, JShort)
IMPL_PRIMITIVE_METHOD(ModelDirectX, getVertexCount, JInt)
IMPL_ARRAY_METHOD(ModelDirectX, getVerticesX, JInt)
IMPL_ARRAY_METHOD(ModelDirectX, getVerticesY, JInt)
IMPL_ARRAY_METHOD(ModelDirectX, getVerticesZ, JInt)

} // namespace bridge
