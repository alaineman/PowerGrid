#include "speed.h"

using entity::Component;
using jace::JField;
using java::lang::Object;

namespace api {
namespace component {

Speed::Speed(Object ref, JField<JDouble> speed, QObject* parent):
    Component(ref, parent), value(speed){}

double Speed::getCurrentSpeed() {
    Object o = getReference();
    return value.get(o);
}

} // namespace component
} // namespace api
