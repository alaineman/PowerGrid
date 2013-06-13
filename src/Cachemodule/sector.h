#ifndef SECTOR_H
#define SECTOR_H

#include "jniobject.h"
#include <QtCore>

using namespace std;
using namespace jni;

namespace cache{

  typedef unsigned char coll_flag;

  class Sector {
    private:
      QList<coll_flag*> collision_maps;
      QList<JNIObject> objects;
      uint getIndexForPlane(int z);
    public:
      ~Sector();
      JNIObject* getObject();
      byte getObjectCount();
      void setObject();
      void removeCollisionMap(int z);
      byte getCollision(byte x,byte y, int z);
      void setCollision(byte x,byte y, int z, byte value);
      void ensurePlane(int z);
  };
}
#endif // SECTOR_H
