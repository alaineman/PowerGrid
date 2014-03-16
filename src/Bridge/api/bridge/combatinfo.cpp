#include "combatinfo.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(CombatInfo, LinkedListNode)
IMPL_RSCLASS_GET(CombatInfo)

IMPL_PRIMITIVE_METHOD(CombatInfo, getHPRatio, JInt)
IMPL_PRIMITIVE_METHOD(CombatInfo, getLoopCycle, JInt)

} // namespace bridge
} // namespace api
