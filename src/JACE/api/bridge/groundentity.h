#ifndef API_BRIDGE_GROUNDENTITY_H
#define API_BRIDGE_GROUNDENTITY_H

#include "MethodHelper.h"
#include "interactable.h"

namespace api {
namespace bridge {

class GroundEntity : public Interactable {
public:
    RS_OBJECT(GroundEntity)
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_GROUNDENTITY_H
