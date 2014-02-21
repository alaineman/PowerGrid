#ifndef API_BRIDGE_BOUNDARY_H
#define API_BRIDGE_BOUNDARY_H

#include "MethodHelper.h"
#include "interactable.h"

namespace api {
namespace bridge {

class Boundary : public Interactable {
public:
    RS_OBJECT(Boundary)
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_BOUNDARY_H
