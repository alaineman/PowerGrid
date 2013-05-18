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

JNIValue Sector::getObject(){
    return NULL;
}

void Sector::setObject(){
}

byte Sector::getObjectCount(){
    return objects.size();
}

void Sector::removeCollisionMap(int z){
    byte* elem = collision_maps.at(z);
    collision_maps.erase(collision_maps.begin()+z);
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

}
