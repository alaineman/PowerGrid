#include "speed.h"

using entity::Component;

namespace component {

Speed::Speed(double speed, entity::Entity* parent):
    Component(parent), value(speed){}

} // namespace component
