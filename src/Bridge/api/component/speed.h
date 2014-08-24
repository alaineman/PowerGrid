#ifndef API_COMPONENT_SPEED_H
#define API_COMPONENT_SPEED_H

#include "entity/component.h"

using entity::Component;

namespace api {
namespace component {

class Speed : public Component {
    Q_OBJECT
private:
    double value;
public:
    explicit Speed(double speed, entity::Entity *parent = 0);
    double getCurrentSpeed() const { return value; }
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_SPEED_H
