#ifndef SECTOR_H
#define SECTOR_H
#include "stdafx.h"
#include "JNIConnection"
#include "collisionmap.h"

using namespace std;
using namespace jni;

namespace cache{

class Sector
{
private:
    vector<CollisionMap> collisions;
    vector<JNIValue> objects;
public:
    Sector();
};

}
#endif // SECTOR_H
