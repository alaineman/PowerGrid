#include "transportation.h"
#include "position.h"
#include "action.h"

namespace api {
namespace component {

using java::lang::Object;

Transportation::Transportation(Position* _from, Position* _to, int _cost,
                               Action* _action, entity::Entity* parent):
    HashableComponent(Object(), parent), from(_from), to(_to), cost(_cost), action(_action){}

Position* Transportation::getFrom() const {
    return from;
}
Position* Transportation::getTo() const {
    return to;
}
int Transportation::getCost() const {
    return cost;
}
Action* Transportation::getAction() const {
    return action;
}

uint Transportation::hash(uint seed) const {
    return qHash(from, seed) ^ qHash(to, seed) ^ rol(cost, 4);
}

} // namespace component
} // namespace api
