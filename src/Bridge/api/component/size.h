#ifndef API_COMPONENT_SIZE_H
#define API_COMPONENT_SIZE_H

#include "entity/component.h"
#include "jace/JField.h"

using entity::HashableComponent;
using jace::JField;

namespace api {
namespace component {

class Size : public HashableComponent {
    Q_OBJECT
private:
    JField<JInt> x, y;
public:
    explicit Size(java::lang::Object ref, JField<JInt> width, JField<JInt> height,
                  entity::Entity *parent = Q_NULLPTR);
    int getWidth() const;
    int getHeight() const;

    virtual uint hash(uint seed) const;
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_SIZE_H
