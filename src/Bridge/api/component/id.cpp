#include "id.h"

using entity::Component;
using jace::JField;
using java::lang::Object;

namespace api {
namespace component {

ID::ID(Object ref, JField<JInt> id, entity::Entity* parent):
    HashableComponent(ref, parent), value(id){}

int ID::getID() const {
    Object o = getReference();
    return value.get(o);
}

uint ID::hash(uint seed) const {
    return uint(getID()) ^ seed;
}

} // namespace component
} // namespace api
