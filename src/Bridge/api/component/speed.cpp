#include "speed.h"

using entity::Component;
using jace::JField;
using java::lang::Object;

namespace api {
namespace component {

Speed::Speed(Object ref, JField<JDouble> speed, entity::Entity* parent):
    Component(ref, parent), value(speed){}

double Speed::getCurrentSpeed() const {
    Object o = getReference();
    return value.get(o);
}

} // namespace component
} // namespace api
