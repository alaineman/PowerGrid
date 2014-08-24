#include "speed.h"

using entity::Component;

namespace api {
namespace component {

Speed::Speed(double speed, entity::Entity* parent):
    Component(parent), value(speed){}

} // namespace component
} // namespace api
