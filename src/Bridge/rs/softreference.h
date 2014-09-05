#ifndef API_BRIDGE_SOFTREFERENCE_H
#define API_BRIDGE_SOFTREFERENCE_H

#include "MethodHelper.h"
#include "reference.h"
using namespace java::lang;

namespace java{
namespace lang{
namespace ref {
class SoftReference;
}
}
}


namespace RS {

class SoftReference : public Reference {
public:
    RS_OBJECT(SoftReference)

    JACE_PROXY_API java::lang::ref::SoftReference getSoftReference();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_SOFTREFERENCE_H
