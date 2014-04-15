#include "objectdefloader.h"
#include "cache.h"
#include "objectcomposite.h"
#include "java/lang/string.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(ObjectDefLoader)
IMPL_RSCLASS_GET(ObjectDefLoader)

IMPL_OBJECT_METHOD(ObjectDefLoader, getComposite, ObjectComposite)
IMPL_OBJECT_METHOD(ObjectDefLoader, getDefCache, Cache)
IMPL_ARRAY_METHOD(ObjectDefLoader, getGroundActions, String)
IMPL_OBJECT_METHOD(ObjectDefLoader, getModelCache, Cache)
IMPL_PRIMITIVE_METHOD(ObjectDefLoader, isShowingActions, JBoolean)

} // namespace bridge
} // namespace api
