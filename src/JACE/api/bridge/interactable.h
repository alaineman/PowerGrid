#ifndef API_BRIDGE_INTERACTABLE_H
#define API_BRIDGE_INTERACTABLE_H

#include "MethodHelper.h"
#include "entitynode.h"

namespace api {
namespace bridge {

class Interactable : public EntityNode {
public:
    RS_OBJECT(Interactable)

    JACE_PROXY_API JByte getPlane();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_INTERACTABLE_H
