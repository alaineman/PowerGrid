#include "name.h"

using entity::Component;

namespace component {

Name::Name(QString name, entity::Entity* parent):
    HashableComponent(parent), value(name){}

uint Name::hash(uint seed) const {
    return 137 * qHash(value, seed);
}

} // namespace component
