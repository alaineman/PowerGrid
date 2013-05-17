#ifndef WORLDDATA_H
#define WORLDDATA_H
#include "stdafx.h"
#include "sector.h"


namespace cache{

class WorldData
{
private:
    vector<Sector> sectors;
public:
    WorldData();
    int getCollisionFlag(byte x, byte y);
    int getCollisionFlag(byte x, byte y, byte z);
    int getSectorBase(byte x, byte y);
    Sector getSector(byte x, byte y);
    void setSector(Sector sector);
};

}

#endif // WORLDDATA_H
