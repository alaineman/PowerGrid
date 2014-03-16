#include "position.h"

using entity::Component;
using jace::JField;
using java::lang::Object;

namespace api {
namespace component {

Position::Position(Object ref, JField<JInt> _x, JField<JInt> _y, JField<JInt> _z, QObject* parent):
    Component(ref, parent), x(_x), y(_y), z(_z) {}

int Position::getX() {
    Object o = getReference();
    return x.getReadOnly(o);
}

int Position::getY(){
    Object o = getReference();
    return y.getReadOnly(o);
}

int Position::getZ(){
    Object o = getReference();
    return z.getReadOnly(o);
}


} // namespace component
} // namespace api
