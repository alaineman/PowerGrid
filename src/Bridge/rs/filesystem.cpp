#include "filesystem.h"

#include "fileworker.h"
#include "referencetable.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(FileSystem)
IMPL_RSCLASS_GET(FileSystem)

IMPL_ARRAY2_METHOD(FileSystem, getChildBuffers, Object)
IMPL_OBJECT_METHOD(FileSystem, getDiscardEntryBuffers, JBoolean)
IMPL_PRIMITIVE_METHOD(FileSystem, getDiscardUnpacked, JInt)
IMPL_OBJECT_METHOD(FileSystem, getFileWorker, FileWorker)
IMPL_OBJECT_METHOD(FileSystem, getReferenceTable, ReferenceTable)

} // namespace bridge
