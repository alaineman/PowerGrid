#include "entitydata.h"

#include "entityposition.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(EntityData)
IMPL_RSCLASS_GET(EntityData)

IMPL_OBJECT_METHOD(EntityData, getPosition, EntityPosition)

}
