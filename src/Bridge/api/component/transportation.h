#ifndef API_COMPONENT_TRANSPORTATION_H
#define API_COMPONENT_TRANSPORTATION_H

#include "entity/component.h"

using entity::HashableComponent;

namespace api {
namespace component {

class Position;
class Action;

class Transportation : public HashableComponent {
    Q_OBJECT
private:
    Position* from;
    Position* to;
    int cost;
    Action* action;
public:
    Transportation(Position* _from, Position* _to, int _cost, Action* _action, entity::Entity *parent = 0);

    Position* getFrom() const;
    Position* getTo() const;
    int getCost() const;
    Action* getAction() const;

    virtual uint hash(uint seed) const;
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_TRANSPORTATION_H
