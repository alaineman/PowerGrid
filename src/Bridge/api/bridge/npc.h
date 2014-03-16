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

/*!
 * \brief The NPC class represents NPC objects in the Runescape World
 *
 * Runescape is full of NPCs (non playable character). Some are combatable while others are not.
 * Common examples:
 * \li goblin (monster)
 * \li shopkeepers (non-attackable person)
 * \li nex (boss monster)
 *
 */
class NPC : public Character {
public:
    RS_OBJECT(NPC)

    /*!
     * \brief The ID belonging to that NPC.
     */
    JACE_PROXY_API JInt getID();

    /*!
     * \brief the level of the NPC.
     *
     * Obviously, this is only usefull for combatable NPCs.
     */
    JACE_PROXY_API JInt getLevel();

    /*!
     * \brief The NPC definition corresponding to the NPC.
     */
    JACE_PROXY_API NPCDef getNPCDef();

    /*!
     * \brief The internal NPC name.
     *
     */
    JACE_PROXY_API String getNPCName();

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_NPC_H
