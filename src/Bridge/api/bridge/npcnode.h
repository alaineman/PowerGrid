#ifndef NPCNODE_H
#define NPCNODE_H

#include "MethodHelper.h"
#include "node.h"
using namespace java::lang;

namespace api {
namespace bridge {

class NPC;
class NPCNode : public Node {
public:
    RS_OBJECT(NPCNode)

    JACE_PROXY_API NPC getNPC();

private:
    DECLARE_FRIENDS
};


} // namespace bridge
} // namespace api

#endif // NPCNODE_H
