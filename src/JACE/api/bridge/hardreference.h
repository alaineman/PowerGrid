#ifndef API_BRIDGE_HARDREFERENCE_H
#define API_BRIDGE_HARDREFERENCE_H

#include "MethodHelper.h"
#include "reference.h"

namespace api {
namespace bridge {

class HardReference : public Reference {
public:
    RS_OBJECT(HardReference)

    JACE_PROXY_API Object getHardReference();
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_HARDREFERENCE_H
