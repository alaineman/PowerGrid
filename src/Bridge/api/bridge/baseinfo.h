#ifndef API_BRIDGE_BASEINFO_H
#define API_BRIDGE_BASEINFO_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class BaseInfo : public Object {
public:
    RS_OBJECT(BaseInfo)

    JACE_PROXY_API JInt getMinX();
    JACE_PROXY_API JInt getMinY();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_BASEINFO_H
