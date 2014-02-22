#ifndef API_BRIDGE_VARPBITS_H
#define API_BRIDGE_VARPBITS_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Varpbits : public Object {
public:
    RS_OBJECT(Varpbits)

    JACE_PROXY_API QList<JInt> getVars();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_VARPBITS_H
