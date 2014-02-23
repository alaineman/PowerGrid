#include "inputstream.h"
#include "java/io/inputstream.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(InputStream)
IMPL_RSCLASS_GET(InputStream)

IMPL_OBJECT_METHOD(InputStream, getInputStream, java::io::InputStream)

} // namespace bridge
} // namespace api
