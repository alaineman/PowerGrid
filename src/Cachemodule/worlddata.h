/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
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
      jbyte getCollisionFlag(Point p);
      jbyte getCollisionFlag(int x, int y);
      jbyte getCollisionFlag(int x, int y, int z);
      Sector* getSector(int x, int y);
      Sector* getSector(Point p);
      Sector* allocate(int sectorX, int sectorY);
      void remove(int sectorX, int sectorY);
  };

}

#endif // WORLDDATA_H
