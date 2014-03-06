#include "action.h"

namespace api {
namespace component {

Action::Action(Object ref, QObject *parent) : Component(ref, parent) {
}

bool Action::operator ==(const Action& other) {
    return getReference().equals(other.getReference());
}

} // namespace component
} // namespace api
