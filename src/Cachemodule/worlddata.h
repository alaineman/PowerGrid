#ifndef WORLDDATA_H
#define WORLDDATA_H

#include "sector.h"
#include "point.h"
#include <QHash>

using namespace world;

namespace cache {

  class WorldData {
    private:
      QHash<int, Sector*> sectors;
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
