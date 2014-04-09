#ifndef API_COMPONENT_POSITION_H
#define API_COMPONENT_POSITION_H

#include "entity/component.h"
#include "jace/JField.h"

using entity::HashableComponent;
using jace::JField;

namespace api {
namespace component {

class Position : public HashableComponent {
    Q_OBJECT
private:
    JField<JInt> x, y, z;
public:
    explicit Position(java::lang::Object ref, JField<JInt> _x, JField<JInt> _y,
                      JField<JInt> _z, entity::Entity *parent = Q_NULLPTR);

    int getX() const;
    int getY() const;
    int getZ() const;

    virtual uint hash(uint seed) const;
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_POSITION_H
