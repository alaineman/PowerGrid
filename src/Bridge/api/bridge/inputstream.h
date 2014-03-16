#ifndef API_BRIDGE_INPUTSTREAM_H
#define API_BRIDGE_INPUTSTREAM_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace java {
    namespace io {
    class InputStream;
    }
}

namespace api {
namespace bridge {

/*!
 * \brief Wrapper for \c java.io.InputStream
 * This class basically wraps a \c java.io.InputStream instance.
 */
class InputStream : public Object {
public:
    RS_OBJECT(InputStream)

    /*!
     * \brief Returns the \c java.io.InputStream this object contains
     * \return the wrapped \c java.io.InputStream
     */
    JACE_PROXY_API java::io::InputStream getInputStream();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_INPUTSTREAM_H
