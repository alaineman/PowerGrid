#ifndef API_BRIDGE_ANIMABLE_H
#define API_BRIDGE_ANIMABLE_H

#include "MethodHelper.h"
#include "interactable.h"

namespace api {
namespace bridge {

class Animable : public Interactable {
public:
    RS_OBJECT(Animable)

    JACE_PROXY_API JShort getMaxX();
    JACE_PROXY_API JShort getMaxY();
    JACE_PROXY_API JShort getMinX();
    JACE_PROXY_API JShort getMinY();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ANIMABLE_H
