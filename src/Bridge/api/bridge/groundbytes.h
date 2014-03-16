#ifndef API_BRIDGE_GROUNDBYTES_H
#define API_BRIDGE_GROUNDBYTES_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class GroundBytes : public Object {
public:
    RS_OBJECT(GroundBytes)

    JACE_PROXY_API QList<QList<QList<JByte>>> getBytes();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_GROUNDBYTES_H
