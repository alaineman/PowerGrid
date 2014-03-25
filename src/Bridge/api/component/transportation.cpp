#include "transportation.h"
#include "position.h"
#include "action.h"

namespace api {
namespace component {

Transportation::Transportation(Position* _from, Position* _to, int _cost, Action* _action, QObject* parent):
    Component(Object(), parent), from(_from), to(_to), cost(_cost), action(_action){}

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

} // namespace component
} // namespace api
