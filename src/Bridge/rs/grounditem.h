#ifndef API_BRIDGE_GROUNDITEM_H
#define API_BRIDGE_GROUNDITEM_H

#include "MethodHelper.h"
#include "groundentity.h"
using namespace java::lang;


namespace RS {

/*!
 * \brief The GroundItem class
 *
 * As the name suggest these are Items located on the ground, often referred to as "drops" in Runescape.
 * They are bound to a specific tile and they the number of grounditems can stack, yet only the top
 * three items models are shown.
 *
 * Upon picking-up (looting) the ground items they will be placed in the inventory interface.
 * Coins will go directly into the money pouch unless the player picked it up in a PVP (player vs player) area.
 * An interface child will then show the icon of the item and the ItemID will correspond with the ID of the Item itself.
 *
 * Not only monsters drop items, players can drop items themself using the "drop" option on items as well.
 * Also, if a player dies in the Wilderness his inventory and equipment items will be converted to grounditems.
 *
 * GroundItems also appear on tables or desks even though it is technically not the groundsurface.
 * Since this is the actual Item and behaves exactly like an item on the base of an Tile there is no difference,
 * except the player cannot walk on top of the stack of GroundItems.
 *
 * Besides picking up from the Tile you are standing on a player can also pick-up GroundItems from adjacent Tiles.
 * Tables and desks are looted from in such a way.
 *
 * For telekinetic grab related questions please view:
 * <a href="http://runescape.wikia.com/wiki/Telekinetic_Grab">Telekinetic Grab (Runescape Wikia)</a>
 *
 *
 */
class GroundItem : public GroundEntity {
public:
    RS_OBJECT(GroundItem)

    /*!
     * \brief The ID of the GroundItem
     *
     * This ID matches with the ID in the ItemDef (item definition).
     *
     */
    JACE_PROXY_API JInt getID();
    /*!
     * \brief The stacksize of the GroundItem
     *
     * This value represents the amount of items per slot.
     * \li For unnoted items this is always 1. Exceptions are unnotable stackable Items like coins, runes and arrows.
     * \li For noted items this can be from 1 to 2,147,483,647 (2^31 - 1).
     *
     * Note: The amount of the StackSize for unnotedable stackable items can change the Model.
     *
     */
    JACE_PROXY_API JInt getStackSize();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_GROUNDITEM_H
