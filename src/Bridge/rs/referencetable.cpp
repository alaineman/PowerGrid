#include "referencetable.h"
#include "lookuptable.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(ReferenceTable)
IMPL_RSCLASS_GET(ReferenceTable)

IMPL_PRIMITIVE_METHOD(ReferenceTable, getCRC, JInt)
IMPL_ARRAY2_METHOD(ReferenceTable, getChildIdentifiers, JInt)
IMPL_ARRAY_METHOD(ReferenceTable, getChildIdentityTables, LookupTable)
IMPL_ARRAY_METHOD(ReferenceTable, getChildIndexCounts, JInt)
IMPL_ARRAY2_METHOD(ReferenceTable, getChildIndices, JInt)
IMPL_ARRAY_METHOD(ReferenceTable, getEntryCRCs, JInt)
IMPL_ARRAY_METHOD(ReferenceTable, getEntryChildCounts, JInt)
IMPL_PRIMITIVE_METHOD(ReferenceTable, getEntryCount, JInt)
IMPL_ARRAY_METHOD(ReferenceTable, getEntryIdentifiers, JInt)
IMPL_OBJECT_METHOD(ReferenceTable, getEntryIdentityTable, LookupTable)
IMPL_PRIMITIVE_METHOD(ReferenceTable, getEntryIndexCount, JInt)
IMPL_ARRAY_METHOD(ReferenceTable, getEntryIndices, JInt)
IMPL_ARRAY_METHOD(ReferenceTable, getEntryVersions, JInt)
IMPL_PRIMITIVE_METHOD(ReferenceTable, getIndex, JInt)
IMPL_PRIMITIVE_METHOD(ReferenceTable, getRevision, JInt)

} // namespace bridge

