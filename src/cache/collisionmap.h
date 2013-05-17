#ifndef COLLISIONMAP_H
#define COLLISIONMAP_H
#include "stdafx.h"

namespace cache{

class CollisionMap
{
private:
    byte* coll_flag;
    byte z;
public:
    CollisionMap(byte plane);
    ~CollisionMap();
    byte get(byte x,byte y);
    byte getPlane();
    void set(byte x,byte y, byte value);
};

}

#endif // COLLISIONMAP_H
