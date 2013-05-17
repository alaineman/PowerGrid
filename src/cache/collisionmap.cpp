#include "collisionmap.h"


namespace cache{

CollisionMap::CollisionMap(byte plane){
    coll_flag = new byte[64][64];
    z = plane;
}

CollisionMap::~CollisionMap(){
    delete coll_flag;
}

byte get(byte x,byte y){
    return *coll_flag[x][y];
}

byte getPlane(){
    return z;
}

void set(byte x,byte y, byte value){
    *coll_flag[x][y] = value;
}

}
