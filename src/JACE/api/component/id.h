#ifndef API_COMPONENT_ID_H
#define API_COMPONENT_ID_H

#include "entity/component.h"
#include "jace/JField.h"

using entity::Component;
using jace::JField;

namespace api {
namespace component {

class ID : public Component {
    Q_OBJECT
private:
    JField<JInt> value;
public:
    explicit ID(Object ref, JField<JInt> id, QObject* parent = 0);
    int getID();
};


} // namespace component
} // namespace api

#endif // API_COMPONENT_ID_H
