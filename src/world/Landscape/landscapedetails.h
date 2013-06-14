#ifndef LANDSCAPEDETAILS_H
#define LANDSCAPEDETAILS_H

#include "jniobject.h"
#include "tile.h"
#include "tileheights.h"

namespace world{

class LandscapeDetails : public jni::JNIObject{
private:
    Q_DISABLE_COPY(LandscapeDetails)
    jint width;
    jint height;
    jint topplane;
    vector<vector<vector<Tile*> > > tiles;
    vector<TileHeights*> tileheights;
public:
    LandscapeDetails(jobject obj) : JNIObject(obj){}
    jint getWidth(bool useCache = true);
    jint getHeight(bool useCache = true);
    jint getTopPlane(bool useCache = true);
    vector<vector<vector<Tile*> > > getTiles(bool useCache = true);
    vector<TileHeights*> getTileHights(bool useCache = true);
};

}
#endif // LANDSCAPEDETAILS_H
