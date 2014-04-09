#include "interaction.h"

using entity::Component;
using jace::JField;
using java::lang::Object;

namespace api {
namespace component {

Interaction::Interaction(QMap<QString, Action *> _actions, java::lang::Object ref, entity::Entity *parent) :
        Component(ref, parent), actions(_actions) {
}

Action* Interaction::getAction(QString name) const {
    return actions.value(name, Q_NULLPTR);
}

QMap<QString, Action*> Interaction::getActionMap() const {
    return actions;
}

} // namespace component
} // namespace api
