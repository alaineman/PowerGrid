#include "fileondisk.h"
#include "java/io/file.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(FileOnDisk)
IMPL_RSCLASS_GET(FileOnDisk)

IMPL_OBJECT_METHOD(FileOnDisk, getFile, java::io::File)

} // namespace bridge
