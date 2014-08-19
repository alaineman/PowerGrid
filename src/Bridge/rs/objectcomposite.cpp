#include "objectcomposite.h"
#include "modelld.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(ObjectComposite)
IMPL_RSCLASS_GET(ObjectComposite)

IMPL_OBJECT_METHOD(ObjectComposite, getModel, ModelLD)

} // namespace bridge
