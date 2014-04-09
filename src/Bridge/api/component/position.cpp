#include "position.h"

using entity::Component;
using jace::JField;
using java::lang::Object;

namespace api {
namespace component {

Position::Position(java::lang::Object ref, JField<JInt> _x, JField<JInt> _y, JField<JInt> _z, entity::Entity* parent):
    HashableComponent(ref, parent), x(_x), y(_y), z(_z) {}

int Position::getX() const {
    Object o = getReference();
    return x.get(o);
}

int Position::getY() const {
    Object o = getReference();
    return y.get(o);
}

int Position::getZ() const {
    Object o = getReference();
    return z.get(o);
}

uint Position::hash(uint seed) const {
    uint x = uint(getX()), y = uint(getY()), z = uint(getZ());
    return (seed ^ x) * (seed ^ rol(y, 4)) * (seed ^ ror(z, 8));
}


} // namespace component
} // namespace api
