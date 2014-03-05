#ifndef API_COMPONENT_NAME_H
#define API_COMPONENT_NAME_H

#include "entity/component.h"
#include "jace/JField.h"

using entity::Component;
using jace::JField;

namespace api {
namespace component {

class Name: public Component {
    Q_OBJECT
private:
    JField<java::lang::String> value;
public:
    explicit Name(Object ref, JField<java::lang::String> name, QObject* parent = 0);
    QString getName();
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_NAME_H
