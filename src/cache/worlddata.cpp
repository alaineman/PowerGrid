#include "sector.h"
#include "world/point.h"
#include "worlddata.h"

using namespace world;

namespace cache{

WorldData::~WorldData(){

}

int WorldData::convertToKey(int x, int y){
    //convert x and y to shorts
    //right shift x and concat y
    //return the key
    return -1;
}

byte WorldData::getCollisionFlag(Point p){
    return getCollisionFlag(p.GetX(),p.GetY(),p.GetPlane());
}

byte WorldData::getCollisionFlag(int x, int y){
    return getCollisionFlag(x,y,0);
}

byte WorldData::getCollisionFlag(int x, int y, int z){
    Sector* s = getSector(x,y);
    if(s == NULL){
        return 0;
    }
    byte localX = (byte) x%64;
    byte localY = (byte) y%64;
    return s->getCollision(localX,localY,z);
}

Sector* WorldData::getSector(int x, int y){
    int sectorX = x/64;
    int sectorY = y/64;
    int index = convertToKey(sectorX, sectorY);
    try {        
        return sectors.at(index);
    } catch (out_of_range){
        return NULL;
    }
}

Sector* WorldData::getSector(Point p){
    return getSector(p.GetX(),p.GetY());
}

Sector* WorldData::allocate(int sectorX, int sectorY){
    int key = convertToKey(sectorX, sectorY);
    Sector* s; // assignment needed?
    sectors.insert(std::pair<int,Sector*>(key,s));
    return s;
}

void WorldData::remove(int sectorX, int sectorY){
    int key = convertToKey(sectorX, sectorY);
    try {
        Sector* s = sectors.at(key);
        delete s;
        sectors.erase(key);
    } catch (out_of_range){
        //sector not found (key invalid)
    }

}

}
