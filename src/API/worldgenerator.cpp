/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
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
#include "worldgenerator.h"

#include "rs/client.h"
#include "rs/landscapeinfo.h"
#include "rs/landscapedetails.h"
#include "rs/boundaryobject.h"
#include "rs/floorobject.h"
#include "rs/wallobject.h"
#include "rs/groundobject.h"

#include "jace/JNIException.h"
#include "jace/MappingUnavailableException.h"
#include "jace/RSClassMapper.h"
#include "jace/RSClass.h"
#include "jace/javacast.h"

#include "entity/mapper.h"

#include "component/id.h"
#include "component/position.h"

namespace API {

using entity::World;
using jace::RSClassMapper;
using jace::RSClass;
using jace::JArray;

using component::ID;
using component::Position;

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

        Position* pos = new Position(
                    b.getLocationX(),
                    b.getLocationY(),
                    (int)b.getPlane().getByte());

        Mapper* posMapper = _world->getMapper<Position>();
        QList<Entity*> entities = posMapper->getEntities(pos);
        foreach(Entity* e, entities) {
            if (e->get<ID>()->getID() == b.getID()) {
                return e;
            }
        }

        Entity* e = _world->createEntity();
        e->addComponent(new ID(b.getID()));
        e->addComponent(pos);

        return e;
    } catch (jace::JNIException& ex) {
        Q_UNUSED(ex);
        return NULL;
    }
}

Entity* WorldGenerator::createEntity(RS::WallDecoration object) {
    if (object.isNull()) {
        return NULL;
    }
    try {
        RS::WallObject b = jace::java_cast<RS::WallObject>(object);

        Position* pos = new Position(
                    b.getLocationX(),
                    b.getLocationY(),
                    (int)b.getPlane().getByte());

        Mapper* posMapper = _world->getMapper<Position>();
        QList<Entity*> entities = posMapper->getEntities(pos);
        foreach(Entity* e, entities) {
            if (e->get<ID>()->getID() == b.getID()) {
                return e;
            }
        }
        Entity* e = _world->createEntity();
        e->addComponent(new ID(b.getID()));
        e->addComponent(pos);

        return e;
    } catch (jace::JNIException& ex) {
        Q_UNUSED(ex);
        return NULL;
    }
}

Entity* WorldGenerator::createEntity(RS::FloorDecoration object) {
    if (object.isNull()) {
        return NULL;
    }
    try {
        RS::FloorObject b = jace::java_cast<RS::FloorObject>(object);

        Position* pos = new Position(
                    b.getLocationX(),
                    b.getLocationY(),
                    (int)b.getPlane().getByte());

        Mapper* posMapper = _world->getMapper<Position>();
        QList<Entity*> entities = posMapper->getEntities(pos);
        foreach(Entity* e, entities) {
            if (e->get<ID>()->getID() == b.getID()) {
                return e;
            }
        }

        Entity* e = _world->createEntity();
        e->addComponent(new ID(b.getID()));
        e->addComponent(pos);

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
           *wall1     = createEntity(tile.getWallDecoration1()),
           *wall2     = createEntity(tile.getWallDecoration2());

    QList<Entity*> list;
    if (boundary1)  list.append(boundary1);
    if (boundary2)  list.append(boundary2);
    if (floor)      list.append(floor);
    if (wall1)      list.append(wall1);
    if (wall2)      list.append(wall2);

    return list;
}

void WorldGenerator::createEntities() {
    QList<RS::Tile> data = getFlattenedRegionData();
    foreach(RS::Tile tile, data) {
        createEntities(tile);
    }
}

void WorldGenerator::processTick() {
    createEntities();
}

}
