#ifndef API_BRIDGE_CENTRALLOCATIONDATA_H
#define API_BRIDGE_CENTRALLOCATIONDATA_H

#include "MethodHelper.h"
#include "abstractcentrallocationdata.h"

namespace api {
namespace bridge {

class EntityPosition;

class CentralLocationData : public AbstractCentralLocationData {
public:
    RS_OBJECT(CentralLocationData)

    JACE_PROXY_API EntityPosition getPoint1();
    JACE_PROXY_API EntityPosition getPoint2();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_CENTRALLOCATIONDATA_H
