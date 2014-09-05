#include "softreference.h"
#include "java/lang/ref/softreference.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(SoftReference, Reference)
IMPL_RSCLASS_GET(SoftReference)

IMPL_OBJECT_METHOD(SoftReference, getSoftReference, java::lang::ref::SoftReference)

} // namespace bridge

