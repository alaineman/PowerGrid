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
};

}

#endif // WORLDDATA_H
