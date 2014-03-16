#include "modelopengl.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(ModelOpenGL, AbstractModel)
IMPL_RSCLASS_GET(ModelOpenGL)

IMPL_ARRAY_METHOD(ModelOpenGL, getVerticiesX, JInt)
IMPL_ARRAY_METHOD(ModelOpenGL, getVerticiesY, JInt)
IMPL_ARRAY_METHOD(ModelOpenGL, getVerticiesZ, JInt)

} // namespace bridge
} // namespace api
