#include "name.h"
#include "java/lang/string.h"

using entity::Component;
using jace::JField;
using java::lang::Object;

namespace api {
namespace component {

Name::Name(Object ref, JField<java::lang::String> name, entity::Entity* parent):
    HashableComponent(ref, parent), value(name){}

QString Name::getName() const {
    Object o = getReference();
    return value.get(o).toQString();
}

uint Name::hash(uint seed) const {
    return 137 * qHash(getName(), seed);
}

} // namespace component
} // namespace api
