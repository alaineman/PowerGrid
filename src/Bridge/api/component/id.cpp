#include "id.h"

using entity::Component;

namespace api {
namespace component {

ID::ID(int value, entity::Entity* parent):
    HashableComponent(parent), _value(value){}

uint ID::hash(uint seed) const {
    return uint(_value) ^ seed;
}

} // namespace component
} // namespace api
