#ifndef API_BRIDGE_FILESYSTEM_H
#define API_BRIDGE_FILESYSTEM_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class FileWorker;
class ReferenceTable;

class FileSystem : public Object {
public:
    RS_OBJECT(FileSystem)

    JACE_PROXY_API QList<QList<Object>> getChildBuffers();
    JACE_PROXY_API JBoolean getDiscardEntryBuffers();
    JACE_PROXY_API JInt getDiscardUnpacked();
    JACE_PROXY_API QList<Object> getEntryBuffers();
    JACE_PROXY_API FileWorker getFileWorker();
    JACE_PROXY_API ReferenceTable getReferenceTable();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_FILESYSTEM_H
