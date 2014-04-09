#ifndef API_COMPONENT_SPEED_H
#define API_COMPONENT_SPEED_H

#include "entity/component.h"
#include "jace/JField.h"

using entity::Component;
using jace::JField;

namespace api {
namespace component {

// Note: Speed is not Hashable, because an object's
// speed usually changes, making any hash lookups fail
class Speed : public Component {
    Q_OBJECT
private:
    JField<JDouble> value;
public:
    explicit Speed(java::lang::Object ref, JField<JDouble> speed, entity::Entity *parent = 0);
    double getCurrentSpeed() const;
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_SPEED_H
