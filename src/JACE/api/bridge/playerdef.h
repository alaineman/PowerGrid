#ifndef API_BRIDGE_PLAYERDEF_H
#define API_BRIDGE_PLAYERDEF_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class PlayerDef : public Object {
public:
    RS_OBJECT(PlayerDef)

    JACE_PROXY_API QList<JInt> getBodypartColors();
    JACE_PROXY_API QList<JInt> getEquipment();
    JACE_PROXY_API JInt getID();
    JACE_PROXY_API JLong getModelHash();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_PLAYERDEF_H
