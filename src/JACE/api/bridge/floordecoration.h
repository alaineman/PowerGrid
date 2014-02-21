#ifndef API_BRIDGE_FLOORDECORATION_H
#define API_BRIDGE_FLOORDECORATION_H

#include "MethodHelper.h"
#include "interactable.h"

namespace api {
namespace bridge {

class FloorDecoration : public Interactable {
public:
    RS_OBJECT(FloorDecoration)
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_FLOORDECORATION_H
