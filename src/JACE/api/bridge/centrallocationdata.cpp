#include "centrallocationdata.h"
#include "entityposition.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(CentralLocationData, AbstractCentralLocationData)
IMPL_RSCLASS_GET(CentralLocationData)

IMPL_OBJECT_METHOD(CentralLocationData, getPoint1, EntityPosition)
IMPL_OBJECT_METHOD(CentralLocationData, getPoint2, EntityPosition)

} // namespace bridge
} // namespace api
