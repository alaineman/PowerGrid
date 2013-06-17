#ifndef REGION_H
#define REGION_H

#include "jniobject.h"
#include "regionbase.h"
#include "regiongrid.h"
#include "collisiondata.h"
#include "Cache/objectcacheloader.h"

namespace world{

class Region : public jni::JNIObject{
private:
    Q_DISABLE_COPY(Region)
    vector<jint> fragmentids;
    RegionBase* mapbase;
    RegionGrid* grid;
    ObjectCacheLoader* objectchaceloader;
public:
    Region(jobject obj) : JNIObject(obj){}
    vector<jint> getFragmentIds(bool useCache = true);
    RegionBase* getMapBase(bool useCache = true);
    RegionGrid* getGrid(bool useCache = true);
    ObjectCacheLoader* getObjectCacheLoader(bool useCache = true);

};

}
#endif // REGION_H
