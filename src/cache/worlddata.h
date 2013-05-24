#ifndef WORLDDATA_H
#define WORLDDATA_H
#include "stdafx.h"
#include "sector.h"
#include "world/point.h"

using namespace world;

namespace cache{

class WorldData
{
private:
    map<int, Sector*> sectors;
    int convertToKey(int x, int y);
public:
    ~WorldData();
    byte getCollisionFlag(Point p);
    byte getCollisionFlag(int x, int y);
    byte getCollisionFlag(int x, int y, int z);
    Sector* getSector(int x, int y);
    Sector* getSector(Point p);
    Sector* allocate(int sectorX, int sectorY);
    void remove(int sectorX, int sectorY);
};

}

#endif // WORLDDATA_H
