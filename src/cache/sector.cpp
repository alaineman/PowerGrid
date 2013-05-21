#include "sector.h"

namespace cache {

Sector::Sector(){
}

Sector::~Sector(){
    while (! collision_maps.empty()) {
        byte* elem = collision_maps.back();
        collision_maps.pop_back();
        delete elem;
    }
}

uint Sector::getIndexForPlane(int z){
    if (z < 0) {
        return -2 * z;
    } else if (z > 0) {
        return 2 * (z - 1);
    } else {
        return 0;
    }
}

JNIValue Sector::getObject(){
    return NULL;
}

void Sector::setObject(){
}

byte Sector::getObjectCount(){
    return objects.size();
}

void Sector::removeCollisionMap(int z){
    uint index = getIndexForPlane(z);
    byte* elem = collision_maps.at(index);
    //collision_maps.erase(index);
    delete elem;
}

byte Sector::getCollision(byte x,byte y, int z){
    byte* map = collision_maps.at(z);
    return map[64*x + y];
}

void Sector::setCollision(byte x,byte y, int z, byte value){
    byte* map = collision_maps.at(z);
    map[64*x + y] = value;
}

bool Sector::ensurePlane(int z){
    uint index = getIndexForPlane(z);
    while(collision_maps.size()<index-1){
        //TODO
    }
    return false;
}

}
