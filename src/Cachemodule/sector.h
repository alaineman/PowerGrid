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
