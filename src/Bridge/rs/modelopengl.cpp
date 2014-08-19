#include "modelopengl.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(ModelOpenGL, AbstractModel)
IMPL_RSCLASS_GET(ModelOpenGL)

IMPL_ARRAY_METHOD(ModelOpenGL, getVerticesX, JInt)
IMPL_ARRAY_METHOD(ModelOpenGL, getVerticesY, JInt)
IMPL_ARRAY_METHOD(ModelOpenGL, getVerticesZ, JInt)

} // namespace bridge
