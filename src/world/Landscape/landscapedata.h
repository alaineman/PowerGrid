#ifndef LANDSCAPEDATA_H
#define LANDSCAPEDATA_H

#include "jniobject.h"
#include "mapbase.h"
#include "landscapedetails.h"
#include "collisiondata.h"
#include "Cache/objectcacheloader.h"

namespace world{

class LandscapeData : public jni::JNIObject{
private:
    Q_DISABLE_COPY(LandscapeData)
    vector<jint> loadedregionids;
    MapBase* mapbase;
    LandscapeDetails* details;
    ObjectCacheLoader* objectchaceloader;
public:
    LandscapeData(jobject obj) : JNIObject(obj){}
    vector<jint> getLoadedRegionIds(bool useCache = true);
    MapBase* getMapBase(bool useCache = true);
    LandscapeDetails* getDetails(bool useCache = true);
    ObjectCacheLoader* getObjectCacheLoader(bool useCache = true);

};

}
#endif // LANDSCAPEDATA_H
