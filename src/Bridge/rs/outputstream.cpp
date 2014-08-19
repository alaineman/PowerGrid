#include "outputstream.h"
#include "java/io/outputstream.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(OutputStream)
IMPL_RSCLASS_GET(OutputStream)

IMPL_OBJECT_METHOD(OutputStream, getOutputStream, java::io::OutputStream)

} // namespace bridge
