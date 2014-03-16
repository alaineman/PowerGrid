#ifndef API_BRIDGE_OUTPUTSTREAM_H
#define API_BRIDGE_OUTPUTSTREAM_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace java {
    namespace io {
    class OutputStream;
    }
}

namespace api {
namespace bridge {

class OutputStream : public Object {
public:
    RS_OBJECT(OutputStream)

    JACE_PROXY_API java::io::OutputStream getOutputStream();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_OUTPUTSTREAM_H
