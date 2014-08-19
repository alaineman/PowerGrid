#include "inputstream.h"
#include "java/io/inputstream.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(InputStream)
IMPL_RSCLASS_GET(InputStream)

IMPL_OBJECT_METHOD(InputStream, getInputStream, java::io::InputStream)

} // namespace bridge
