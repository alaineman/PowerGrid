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

/*!
 * \brief Wrapper around java.io.File
 * This class basically wraps a \c java.io.File instance.
 *
 */
class FileOnDisk : public Object {
public:
    RS_OBJECT(FileOnDisk)

    /*!
     * \brief Returns the File associated with this object
     * \return the \c java.io.File instance this object wraps.
     */
    JACE_PROXY_API java::io::File getFile();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_FILEONDISK_H
