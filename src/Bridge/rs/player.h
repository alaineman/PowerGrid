#ifndef API_BRIDGE_PLAYER_H
#define API_BRIDGE_PLAYER_H

#include "MethodHelper.h"
#include "character.h"
using namespace java::lang;

// Forward declarations of Java API classes
namespace java {
namespace lang {
  class String;
}
}


namespace RS {

class ModelLD;
class PlayerDef;

/*!
 * \brief The Player class represents playable characters in the Runescape World.
 *
 */
class Player : public Character {
public:
    RS_OBJECT(Player)

    JACE_PROXY_API JByte getGender();
    JACE_PROXY_API JInt getLevel();
    JACE_PROXY_API ModelLD getModel();
    JACE_PROXY_API String getName();
    JACE_PROXY_API String getNameSuffix();
    JACE_PROXY_API JInt getPKHeadIconIndex();
    JACE_PROXY_API PlayerDef getPlayerDef();
    JACE_PROXY_API JInt getPrayerHeadIconIndex();
    JACE_PROXY_API String getTitle();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_PLAYER_H
