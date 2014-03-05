#include "id.h"

using entity::Component;
using jace::JField;
using java::lang::Object;

namespace api {
namespace component {

ID::ID(Object ref, JField<JInt> id, QObject* parent):
    Component(ref, parent), value(id){}

int ID::getID() {
    Object o = getReference();
    return value.getReadOnly(o);
}

} // namespace component
} // namespace api
