#include "stream.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(Stream, Node)
IMPL_RSCLASS_GET(Stream)

IMPL_ARRAY_METHOD(Stream, getBuffer, JByte)
IMPL_PRIMITIVE_METHOD(Stream, getOffset, JInt)


} // namespace bridge

