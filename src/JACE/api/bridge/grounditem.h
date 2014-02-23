#ifndef API_BRIDGE_GROUNDITEM_H
#define API_BRIDGE_GROUNDITEM_H

#include "MethodHelper.h"
#include "groundentity.h"
using namespace java::lang;

namespace api {
namespace bridge {

class GroundItem : public GroundEntity {
public:
    RS_OBJECT(GroundItem)

    JACE_PROXY_API JInt getID();
    JACE_PROXY_API JInt getStackSize();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_GROUNDITEM_H
