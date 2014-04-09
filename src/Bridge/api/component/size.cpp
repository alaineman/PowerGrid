#include "size.h"

using entity::Component;
using jace::JField;

namespace api {
namespace component {

Size::Size(java::lang::Object ref, JField<JInt> width, JField<JInt> height, entity::Entity* parent):
    HashableComponent(ref, parent), x(width), y(height) {}

int Size::getWidth() const {
    Object o = getReference();
    return x.get(o);
}

int Size::getHeight() const {
    Object o = getReference();
    return y.get(o);
}

uint Size::hash(uint seed) const {
    return ror(getWidth(), sizeof(int)/2) ^ getHeight() ^ seed;
}

} // namespace component
} // namespace api
