#ifndef API_BRIDGE_REFERENCETABLE_H
#define API_BRIDGE_REFERENCETABLE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class LookupTable;
class ReferenceTable : public Object {
public:
    RS_OBJECT(ReferenceTable)

    JACE_PROXY_API JInt getCRC();
    JACE_PROXY_API QList<QList<JInt>> getChildIdentifiers();
    JACE_PROXY_API QList<LookupTable> getChildIdentityTables();
    JACE_PROXY_API QList<JInt> getChildIndexCounts();
    JACE_PROXY_API QList<QList<JInt>> getChildIndices();
    JACE_PROXY_API QList<JInt> getEntryCRCs();
    JACE_PROXY_API QList<JInt> getEntryChildCounts();
    JACE_PROXY_API JInt getEntryCount();
    JACE_PROXY_API QList<JInt> getEntryIdentifiers();
    JACE_PROXY_API LookupTable getEntryIdentityTable();
    JACE_PROXY_API JInt getEntryIndexCount();
    JACE_PROXY_API QList<JInt> getEntryIndices();
    JACE_PROXY_API QList<JInt> getEntryVersions();
    JACE_PROXY_API JInt getIndex();
    JACE_PROXY_API JInt getRevision();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_REFERENCETABLE_H
