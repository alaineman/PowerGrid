#ifndef API_BRIDGE_VARPBITS_H
#define API_BRIDGE_VARPBITS_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

/*!
 * \brief Varpbits class retrieves the settings of the player in Runescape
 *
 * The Varpbits class, an abbreviation for Variable Player Bits (aka player settings), contains a long list
 * of integers representing certain settings in the Runescape World. These values change with actions played
 * out in the World itself. Mainly progression and completion is tracked.
 *
 * Examples:
 * \li A player has finished a quest
 * \li A player has an summoning familiar
 * \li A player has choppped the tree for a waka
 *
 * Hence integer at index 10294 might switch from 1000 to 0384 indicating the change.
 *
 *
 */
class Varpbits : public Object {
public:
    RS_OBJECT(Varpbits)

    /*!
     * \brief The list of integers
     *
     * The list of data being the settings to the player.
     *
     */
    JACE_PROXY_API QList<JInt> getVars();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_VARPBITS_H
