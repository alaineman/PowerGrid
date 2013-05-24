#include "sector.h"
#include "world/point.h"
#include "worlddata.h"

using namespace world;

namespace cache{

WorldData::WorldData(){

}

int WorldData::getCollisionFlag(Point p){
    return -1;
}

int WorldData::getCollisionFlag(byte x, byte y){
    return -1;
}

int WorldData::getCollisionFlag(byte x, byte y, int z){
    return -1;
}

int WorldData::getSectorBase(Point p){
    return -1;
}

int WorldData::getSectorBase(byte x, byte y){
    return -1;
}

Sector WorldData::getSector(byte x, byte y){
    return Sector();
}

Sector WorldData::getSector(Point p){
    return Sector();
}

void WorldData::setSector(Sector sector){

}

}
