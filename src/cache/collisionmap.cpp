#include "collisionmap.h"


namespace cache{

CollisionMap::CollisionMap(byte plane){
    coll_flag = new byte[64*64];
    z = plane;
}

CollisionMap::~CollisionMap(){
    delete coll_flag;
}

byte CollisionMap::get(byte x,byte y){
    return coll_flag[64*x + y];
}

byte CollisionMap::getPlane(){
    return z;
}

void CollisionMap::set(byte x,byte y, byte value){
    coll_flag[64*x + y] = value;
}

}
