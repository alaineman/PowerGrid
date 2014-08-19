#ifndef API_BRIDGE_PLAYERDEF_H
#define API_BRIDGE_PLAYERDEF_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class PlayerDef : public Object {
public:
    RS_OBJECT(PlayerDef)

    JACE_PROXY_API QList<JInt> getBodypartColors();
    JACE_PROXY_API QList<JInt> getEquipment();
    JACE_PROXY_API JBoolean isFemale();
    JACE_PROXY_API JInt getID();
    JACE_PROXY_API JLong getModelHash();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_PLAYERDEF_H
