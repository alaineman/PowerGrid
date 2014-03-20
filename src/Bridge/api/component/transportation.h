#ifndef API_COMPONENT_TRANSPORTATION_H
#define API_COMPONENT_TRANSPORTATION_H

#include "entity/component.h"


using entity::Component;

namespace api {
namespace component {

class Position;
class Action;

class Transportation : public Component {
    Q_OBJECT
private:
    Position* from;
    Position* to;
    int cost;
    Action* action;
public:
    Transportation(Position* _from, Position* _to, int _cost, Action* _action, QObject* parent = 0);

    Position* getFrom() const;
    Position* getTo() const;
    int getCost() const;
    Action* getAction() const;

};

} // namespace component
} // namespace api

#endif // API_COMPONENT_TRANSPORTATION_H
