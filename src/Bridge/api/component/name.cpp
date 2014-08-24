#include "name.h"
#include "java/lang/string.h"

using entity::Component;
using jace::JField;
using java::lang::Object;

namespace api {
namespace component {

Name::Name(QString name, entity::Entity* parent):
    HashableComponent(parent), value(name){}

uint Name::hash(uint seed) const {
    return 137 * qHash(value, seed);
}

} // namespace component
} // namespace api
