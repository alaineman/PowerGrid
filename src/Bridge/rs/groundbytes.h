#ifndef API_BRIDGE_GROUNDBYTES_H
#define API_BRIDGE_GROUNDBYTES_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class GroundBytes : public Object {
public:
    RS_OBJECT(GroundBytes)

    JACE_PROXY_API QList<QList<QList<JByte>>> getGroundBytes();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_GROUNDBYTES_H
