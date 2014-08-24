#include "position.h"

using entity::Component;

namespace api {
namespace component {

Position::Position(int x, int y, int z, entity::Entity* parent):
    HashableComponent(parent), _x(x), _y(y), _z(z) {}

uint Position::hash(uint seed) const {
    return (seed ^ uint(_x)) * (seed ^ rol(uint(_y), 4)) * (seed ^ ror(uint(_z), 8));
}


} // namespace component
} // namespace api
