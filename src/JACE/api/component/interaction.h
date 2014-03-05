#ifndef API_COMPONENT_INTERACTION_H
#define API_COMPONENT_INTERACTION_H

#include "entity/component.h"
#include "jace/JField.h"

using entity::Component;
using jace::JField;

namespace api {
namespace component {

//class Action; //need to make action structure

class Interaction : public Component {
    Q_OBJECT
private:
public:
//    explicit ID(Object ref, QList<JField<Action>> id, QObject* parent = 0); //List of Action ??
};
} // namespace component
} // namespace api

#endif // API_COMPONENT_INTERACTION_H
