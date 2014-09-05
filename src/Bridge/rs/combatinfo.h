#ifndef API_BRIDGE_COMBATINFO_H
#define API_BRIDGE_COMBATINFO_H

#include "MethodHelper.h"
#include "linkedlistnode.h"


namespace RS {

class CombatInfo : public LinkedListNode {
public:
    RS_OBJECT(CombatInfo)

    JACE_PROXY_API JInt getHPRatio();
    JACE_PROXY_API JInt getLoopCycle();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_COMBATINFO_H
