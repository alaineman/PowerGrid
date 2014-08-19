#ifndef API_BRIDGE_FLOORDECORATION_H
#define API_BRIDGE_FLOORDECORATION_H

#include "MethodHelper.h"
#include "interactable.h"


namespace RS {

class FloorDecoration : public Interactable {
public:
    RS_OBJECT(FloorDecoration)
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_FLOORDECORATION_H
