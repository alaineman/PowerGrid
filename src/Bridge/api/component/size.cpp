#include "size.h"

using entity::Component;

namespace api {
namespace component {

Size::Size(int x, int y, entity::Entity* parent):
    HashableComponent(parent), _x(x), _y(y) {}

uint Size::hash(uint seed) const {
    return ror(_x, sizeof(int)/2) ^ _y ^ seed;
}

} // namespace component
} // namespace api
