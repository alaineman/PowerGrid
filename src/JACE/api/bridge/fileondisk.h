#ifndef API_BRIDGE_FILEONDISK_H
#define API_BRIDGE_FILEONDISK_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace java {
 namespace io {
  class File;
 }
}
namespace api {
namespace bridge {

class FileOnDisk : public Object {
public:
    RS_OBJECT(FileOnDisk)

    JACE_PROXY_API java::io::File getFile();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_FILEONDISK_H
