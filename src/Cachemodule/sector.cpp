#include "sector.h"

namespace cache {

Sector::~Sector(){
    while (! collision_maps.empty()) {
        jbyte* elem = collision_maps.back();
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

JNIObject* Sector::getObject(){
  return JNIObject::Null();
}

void Sector::setObject(){
}

jbyte Sector::getObjectCount(){
    return objects.size();
}

void Sector::removeCollisionMap(int z){
    int index = static_cast<int>(getIndexForPlane(z));
    while(collision_maps.size()>= index){
        jbyte* elem = collision_maps.back();
        delete elem;
        collision_maps.pop_back();
    }
}

jbyte Sector::getCollision(jbyte x,jbyte y, int z){
    ensurePlane(z);
    jbyte* map = collision_maps.at(z);
    return map[64*x + y];
}

void Sector::setCollision(jbyte x,jbyte y, int z, jbyte value){
    ensurePlane(z);
    jbyte* map = collision_maps.at(z);
    map[64*x + y] = value;
}

void Sector::ensurePlane(int z){
    int index = static_cast<int>(getIndexForPlane(z));
    while(collision_maps.size()<=index){
        collision_maps.push_back(new jbyte[64*64]);
    }
}

}
