#ifndef API_BRIDGE_WALLDECORATION_H
#define API_BRIDGE_WALLDECORATION_H

#include "MethodHelper.h"
#include "interactable.h"
using namespace java::lang;

namespace api {
namespace bridge {

class WallDecoration : public Interactable {
public:
    RS_OBJECT(WallDecoration)

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_WALLDECORATION_H
