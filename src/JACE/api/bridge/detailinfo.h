#ifndef API_BRIDGE_DETAILINFO_H
#define API_BRIDGE_DETAILINFO_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class DetailInfo : public Object {
public:
    RS_OBJECT(DetailInfo)

    JACE_PROXY_API JInt getLevel();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_DETAILINFO_H
