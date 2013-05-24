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
    vector<Sector> sectors;
public:
    WorldData();
    int getCollisionFlag(Point p);
    int getCollisionFlag(byte x, byte y);
    int getCollisionFlag(byte x, byte y, int z);
    int getSectorBase(Point p);
    int getSectorBase(byte x, byte y);
    Sector getSector(byte x, byte y);
    Sector getSector(Point p);
    void setSector(Sector sector);
};

}

#endif // WORLDDATA_H
