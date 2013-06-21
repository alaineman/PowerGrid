#include "sector.h"
#include "point.h"
#include "worlddata.h"
#include <stdexcept>

using namespace world;

namespace cache{

WorldData::~WorldData(){

}

jbyte WorldData::getCollisionFlag(Point p){
    return getCollisionFlag(p.GetX(),p.GetY(),p.GetPlane());
}

jbyte WorldData::getCollisionFlag(int x, int y){
    return getCollisionFlag(x,y,0);
}

jbyte WorldData::getCollisionFlag(int x, int y, int z){
    Sector* s = getSector(x,y);
    if(s == NULL){
        return 0;
    }
    jbyte localX = (jbyte) x%64;
    jbyte localY = (jbyte) y%64;
    return s->getCollision(localX,localY,z);
}

Sector* WorldData::getSector(int x, int y){
    int sectorX = x/64;
    int sectorY = y/64;
    int index = (sectorX << 16) + sectorY;
    try {        
        return sectors.take(index);
    } catch (out_of_range){
        return NULL;
    }
}

Sector* WorldData::getSector(Point p){
    return getSector(p.GetX(),p.GetY());
}

Sector* WorldData::allocate(int sectorX, int sectorY){
    int key = (sectorX << 16) + sectorY;
    Sector* s = new Sector();
    sectors.insert(key, s);
    return s;
}

void WorldData::remove(int sectorX, int sectorY){
    int key = (sectorX << 16) + sectorY;
    try {
        Sector* s = sectors.take(key);
        sectors.erase(sectors.find(key));
        delete s;
    } catch (out_of_range){
        //sector not found (key invalid)
    }
}

}
