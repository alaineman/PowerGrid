#ifndef COMPONENT_SIZE_H
#define COMPONENT_SIZE_H

#include "entity/component.h"

using entity::HashableComponent;

namespace component {

class Size : public HashableComponent {
    Q_OBJECT
    Q_DISABLE_COPY(Size)
private:
    int _x, _y;
public:
    Size(int x, int y, entity::Entity *parent = Q_NULLPTR);
    int getWidth() const { return _x; }
    int getHeight() const { return _y; }

    virtual uint hash(uint seed) const;
};

} // namespace component

#endif // COMPONENT_SIZE_H
