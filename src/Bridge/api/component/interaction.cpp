#include "interaction.h"

using entity::Component;

namespace api {
namespace component {

Interaction::Interaction(QMap<QString, Action *> _actions, entity::Entity *parent) :
        Component(parent), actions(_actions) {
}

Action* Interaction::getAction(QString name) const {
    return actions.value(name, Q_NULLPTR);
}

QMap<QString, Action*> Interaction::getActionMap() const {
    return actions;
}

} // namespace component
} // namespace api
