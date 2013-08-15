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
#ifndef SECTOR_H
#define SECTOR_H

#include "jniobject.h"
#include <QtCore>

using namespace std;
using namespace jni;

namespace cache{

  typedef jbyte coll_flag;

  class Sector {
    private:
      QList<coll_flag*> collision_maps;
      QList<JNIObject> objects;
      uint getIndexForPlane(int z);
    public:
      ~Sector();
      JNIObject* getObject();
      jbyte getObjectCount();
      void setObject();
      void removeCollisionMap(int z);
      jbyte getCollision(jbyte x,jbyte y, int z);
      void setCollision(jbyte x,jbyte y, int z, jbyte value);
      void ensurePlane(int z);
  };
}
#endif // SECTOR_H
