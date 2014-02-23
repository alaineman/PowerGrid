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

class InputStream : public Object {
public:
    RS_OBJECT(InputStream)

    JACE_PROXY_API java::io::InputStream getInputStream();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_INPUTSTREAM_H
