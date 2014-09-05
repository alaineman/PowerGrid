#ifndef NPCNODE_H
#define NPCNODE_H

#include "MethodHelper.h"
#include "node.h"
using namespace java::lang;

namespace RS {

class NPC;
class NPCNode : public Node {
public:
    RS_OBJECT(NPCNode)

    JACE_PROXY_API NPC getNPC();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // NPCNODE_H
