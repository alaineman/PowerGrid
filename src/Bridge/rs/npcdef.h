#ifndef API_BRIDGE_NPCDEF_H
#define API_BRIDGE_NPCDEF_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

// Forward declarations of Java API classes
namespace java {
namespace lang {
  class String;
}
}


namespace RS {

class NPCDefLoader;
class HashTable;
class NPCDef : public Object {
public:
    RS_OBJECT(NPCDef)

    JACE_PROXY_API QList<String> getActions();
    JACE_PROXY_API Object getChildrenIDs(); //TODO find type
    JACE_PROXY_API JBoolean isClickable();
    JACE_PROXY_API Object getDialogModels(); //TODO find type
    /*!
     * \brief The ID of the NPCDef.
     *
     * \internal need confirmation on this!
     */
    JACE_PROXY_API JInt getID();
    JACE_PROXY_API JInt getLevel();
    JACE_PROXY_API JInt getModelBoundRadius();
    JACE_PROXY_API QList<JShort> getModifiedColors();

    /*!
     * \brief The displayed name of an NPC.
     */
    JACE_PROXY_API String getName();
    JACE_PROXY_API NPCDefLoader getNPCDefLoader();
    JACE_PROXY_API HashTable getNodeTable();
    JACE_PROXY_API QList<JShort> getOriginalColors();
    JACE_PROXY_API JInt getPrayerHeadIconIndex();
    JACE_PROXY_API JInt getRenderEmote();
    JACE_PROXY_API JBoolean isVisibleOnMinimap();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_NPCDEF_H
