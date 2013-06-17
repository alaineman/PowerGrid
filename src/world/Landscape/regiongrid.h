#ifndef REGIONGRID_H
#define REGIONGRID_H

#include "jniobject.h"
#include "tile.h"
#include "tileheights.h"

namespace world {

class RegionGrid : public jni::JNIObject{
private:
    Q_DISABLE_COPY(RegionGrid)
    jint width;
    jint height;
    jint topplane;
    vector<vector<vector<Tile*> > > tiles;
    vector<TileHeights*> tileheights;
public:
    RegionGrid(jobject obj) : JNIObject(obj){}
    jint getWidth(bool useCache = true);
    jint getHeight(bool useCache = true);
    jint getTopPlane(bool useCache = true);
    vector<vector<vector<Tile*> > > getTiles(bool useCache = true);
    vector<TileHeights*> getTileHights(bool useCache = true);
};

}
#endif // REGIONGRID_H
