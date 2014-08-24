#ifndef API_COMPONENT_POSITION_H
#define API_COMPONENT_POSITION_H

#include "entity/component.h"

using entity::HashableComponent;

namespace api {
namespace component {

class Position : public HashableComponent {
    Q_OBJECT
private:
    int _x, _y, _z;
public:
    Position(int x, int y, int z, entity::Entity *parent = Q_NULLPTR);

    int getX() const { return _x; }
    int getY() const { return _y; }
    int getZ() const { return _z; }

    virtual uint hash(uint seed) const;
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_POSITION_H
