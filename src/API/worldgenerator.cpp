#include "worldgenerator.h"

#include "rs/client.h"
#include "rs/landscapeinfo.h"
#include "rs/landscapedetails.h"
#include "rs/boundaryobject.h"

#include "jace/JNIException.h"
#include "jace/MappingUnavailableException.h"
#include "jace/RSClassMapper.h"
#include "jace/RSClass.h"
#include "jace/javacast.h"

#include "component/id.h"
#include "component/position.h"

using entity::World;
using jace::RSClassMapper;
using jace::RSClass;
using jace::JArray;

WorldGenerator::WorldGenerator(World *world)
    : QObject(world), _world(world) {
    if (!world) throw std::invalid_argument("NULL");

    connect(world, SIGNAL(processingFinished()),
            this,  SLOT(processTick()));
}

jobjectArray WorldGenerator::getRawRegionData() throw(jace::JNIException) {
    RS::LandscapeDetails details = RS::Client::getLandscapeInfo().getLandscapeDetails();
    RSClassMapper* rscm          = RSClassMapper::DefaultInstance();
    QString tileClass            = rscm->getRealName("Tile");
    const RSClass* detailsClass  = RS::LandscapeDetails::staticGetJavaJniClass();
    std::string fieldName        = detailsClass->getFieldName("getRegionData");
    jobject object               = details.getJavaJniObject();
    if (!object) throw jace::JNIException("Failed to get valid LandscapeInfo object");
    JNIEnv* env                  = jace::helper::attach();
    jfieldID regionDataField     = env->GetFieldID(detailsClass->getClass(), fieldName.c_str(), qPrintable("[[[L" % tileClass % ";"));
    if (regionDataField == 0) throw jace::MappingUnavailableException("LandscapeDetails.getRegionData()");
    jobjectArray array = static_cast<jobjectArray>(env->GetObjectField(object, regionDataField));
    if (env->ExceptionCheck()) {
        env->ExceptionClear();
        throw jace::JNIException("Unidentified exception in JVM");
    }
    return array;
}

QList<RS::Tile> WorldGenerator::getFlattenedRegionData() throw(jace::JNIException) {

    jobjectArray data = getRawRegionData();
    if (!data) return QList<RS::Tile>();
    QList<RS::Tile> list;
    JNIEnv* env = jace::helper::attach();

    int lengthX = env->GetArrayLength(data);
    list.reserve(lengthX * lengthX * 3); // Estimated amount: square area with on average 3 layers
    for (int x=0;x<lengthX;x++) {
        jobjectArray arrayY = static_cast<jobjectArray>(env->GetObjectArrayElement(data, x));

        int lengthY = env->GetArrayLength(arrayY);
        for (int y=0;y<lengthY;y++) {
            jobjectArray arrayZ = static_cast<jobjectArray>(env->GetObjectArrayElement(arrayY, y));

            int lengthZ = env->GetArrayLength(arrayZ);
            for (int z=0;z<lengthZ;z++) {
                jobject element = env->GetObjectArrayElement(arrayZ, z);
                RS::Tile tile (element);
                list.append(tile);
                env->DeleteLocalRef(element);
            }
            env->DeleteLocalRef(arrayZ);
        }
        env->DeleteLocalRef(arrayY);
    }
    env->DeleteLocalRef(data);

    return list;
}

Entity* WorldGenerator::createEntity(RS::Boundary object) {
    if (object.isNull()) {
        return NULL;
    }
    try {
        RS::BoundaryObject b = jace::java_cast<RS::BoundaryObject>(object);

        Entity* e = _world->createEntity();
        e->addComponent(new component::ID(b.getID()));
        e->addComponent(new component::Position(b.getLocationX(), b.getLocationY(), (int)b.getPlane().getByte()));

        return e;
    } catch (jace::JNIException& ex) {
        Q_UNUSED(ex);
        return NULL;
    }
}

QList<Entity*> WorldGenerator::createEntities(RS::Tile tile) {
    Entity *boundary1 = createEntity(tile.getBoundary1()),
           *boundary2 = createEntity(tile.getBoundary2()),
           *floor     = createEntity(tile.getFloorDecoration()),
           *ground    = createEntity(tile.getGroundEntity()),
           *wall1     = createEntity(tile.getWallDecoration1()),
           *wall2     = createEntity(tile.getWallDecoration2());

    QList<Entity*> list;
    if (boundary1)  list.append(boundary1);
    if (boundary2)  list.append(boundary2);
    if (floor)      list.append(floor);
    if (ground)     list.append(ground);
    if (wall1)      list.append(wall1);
    if (wall2)      list.append(wall2);

    return list;
}

QList<Entity*> WorldGenerator::createEntities() {
    QList<RS::Tile> data = getFlattenedRegionData();
    QList<Entity*> list;
    list.reserve(data.size() * 4); // Average 4 objects for each
    foreach(RS::Tile tile, data) {
        list.append(createEntities(tile));
    }
    return list;
}
