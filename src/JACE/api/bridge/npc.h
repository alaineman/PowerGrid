#ifndef API_BRIDGE_NPC_H
#define API_BRIDGE_NPC_H

#include "MethodHelper.h"
#include "character.h"
using namespace java::lang;

// Forward declarations of Java API classes
namespace java {
namespace lang {
  class String;
}
}

namespace api {
namespace bridge {

class NPCDef;
class NPC : public Character {
public:
    RS_OBJECT(NPC)

    JACE_PROXY_API JInt getID();
    JACE_PROXY_API JInt getLevel();
    JACE_PROXY_API NPCDef getNPCDef();
    JACE_PROXY_API String getNPCName();

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_NPC_H
