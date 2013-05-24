#include "sector.h"

namespace cache {

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
  return JNIValue();
}

void Sector::setObject(){
}

byte Sector::getObjectCount(){
    return objects.size();
}

void Sector::removeCollisionMap(int z){
    uint index = getIndexForPlane(z);    
    while(collision_maps.size()>= index){
        byte* elem = collision_maps.back();
        delete elem;
        collision_maps.pop_back();
    }
}

byte Sector::getCollision(byte x,byte y, int z){    
    ensurePlane(z);
    byte* map = collision_maps.at(z);
    return map[64*x + y];
}

void Sector::setCollision(byte x,byte y, int z, byte value){
    ensurePlane(z);
    byte* map = collision_maps.at(z);
    map[64*x + y] = value;
}

void Sector::ensurePlane(int z){
    uint index = getIndexForPlane(z);
    while(collision_maps.size()<=index){
        collision_maps.push_back(new byte[64*64]);
    }
}

}
