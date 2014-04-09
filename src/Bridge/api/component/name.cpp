#include "name.h"
#include "java/lang/string.h"

using entity::Component;
using jace::JField;
using java::lang::Object;

namespace api {
namespace component {

Name::Name(Object ref, JField<java::lang::String> name, QObject* parent):
    Component(ref, parent), value(name){}

QString Name::getName() {
    Object o = getReference();
    return value.get(o).toQString();
}

} // namespace component
} // namespace api
