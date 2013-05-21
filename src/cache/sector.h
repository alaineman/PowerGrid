#ifndef SECTOR_H
#define SECTOR_H
#include "stdafx.h"
#include "JNIConnection"

using namespace std;
using namespace jni;

namespace cache{

class Sector
{
private:
    vector<byte*> collision_maps;
    vector<JNIValue> objects;
    uint getIndexForPlane(int z);
public:    
    Sector();
    ~Sector();
    JNIValue getObject();
    byte getObjectCount();
    void setObject();
    void removeCollisionMap(int z);
    byte getCollision(byte x,byte y, int z);
    void setCollision(byte x,byte y, int z, byte value);

    bool ensurePlane(int z);
};

}
#endif // SECTOR_H
