#ifndef API_COMPONENT_SPEED_H
#define API_COMPONENT_SPEED_H

#include "entity/component.h"
#include "jace/JField.h"

using entity::Component;
using jace::JField;

namespace api {
namespace component {

class Speed : public Component {
    Q_OBJECT
private:
    JField<JDouble> value;
public:
    explicit Speed(Object ref, JField<JDouble> speed, QObject* parent = 0);
    double getCurrentSpeed();
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_SPEED_H
