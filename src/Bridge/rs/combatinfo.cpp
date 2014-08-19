#include "combatinfo.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(CombatInfo, LinkedListNode)
IMPL_RSCLASS_GET(CombatInfo)

IMPL_PRIMITIVE_METHOD(CombatInfo, getHPRatio, JInt)
IMPL_PRIMITIVE_METHOD(CombatInfo, getLoopCycle, JInt)

} // namespace bridge
