#ifndef API_COMPONENT_POSITION_H
#define API_COMPONENT_POSITION_H

#include "entity/component.h"
#include "jace/JField.h"

using entity::Component;
using jace::JField;

namespace api {
namespace component {

class Position : public Component {
    Q_OBJECT
private:
    JField<JInt> x, y, z;
public:
    explicit Position(Object ref, JField<JInt> _x, JField<JInt> _y, JField<JInt> _z, QObject* parent = 0);
    int getX();
    int getY();
    int getZ();
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_POSITION_H
