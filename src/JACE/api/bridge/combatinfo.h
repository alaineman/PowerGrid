#ifndef API_BRIDGE_COMBATINFO_H
#define API_BRIDGE_COMBATINFO_H

#include "MethodHelper.h"
#include "linkedlistnode.h"

namespace api {
namespace bridge {

class CombatInfo : public LinkedListNode {
public:
    RS_OBJECT(CombatInfo)

    JACE_PROXY_API JInt getHPRatio();
    JACE_PROXY_API JInt getLoopCycle();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_COMBATINFO_H
