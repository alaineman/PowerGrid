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
#ifndef WORLDGENERATOR_H
#define WORLDGENERATOR_H

#include <QObject>
#include "entity/world.h"
#include "entity/entity.h"

#include "rs/boundary.h"
#include "rs/walldecoration.h"
#include "rs/floordecoration.h"
#include "rs/groundentity.h"

#include "rs/tile.h"

using namespace entity;

/**
 * @brief Generator class for the internal World representation.
 *
 * This class is responsible for converting data from the Runescape client
 * into Entities for using them in the Entity framework.
 */
class WorldGenerator : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(WorldGenerator)
private:
    World* _world;
public:
    /**
     * @brief Creates a WorldGenerator to operate on the given World
     * @param world - the World to operate on
     */
    explicit WorldGenerator(World* world);

    /**
     * @brief Returns the World this WorldGenerator operates on.
     */
    World* world() const { return _world; }

    /**
     * @brief Returns a JNI array with the region data
     *
     * This function is optimized for speed, and runs in constant time.
     *
     * The actual Java type of the @c jobjectArray is @c Tile[][][].
     *
     * @return a jobjectArray referring to the region data
     * @throws jace::JNIException - when fetching the region data failed for some reason.
     */
    jobjectArray getRawRegionData() throw(jace::JNIException);

    /**
     * @brief Returns a flattened QList of Tiles from the region data.
     *
     * The region data is wrapped in RS::Tile objects and stored in a QList.
     * All operations are performed on pure JNI code for performance reasons.
     * Even so, this operation may be time-consuming, because the total amount
     * of loaded objects may be very large.
     *
     * @return the list of tiles in the region data
     */
    QList<RS::Tile> getFlattenedRegionData() throw(jace::JNIException);

    /**
     * @brief Creates an Entity from the given Boundary.
     * @param object - the object to create an Entity from
     * @return the created Entity
     */
    Entity* createEntity(RS::Boundary object);
    /**
     * @brief Creates an Entity from the given WallDecoration.
     * @param object - the object to create an Entity from
     * @return the created Entity
     */
    Entity* createEntity(RS::WallDecoration object);
    /**
     * @brief Creates an Entity from the given FloorDecoration.
     * @param object - the object to create an Entity from
     * @return the created Entity
     */
    Entity* createEntity(RS::FloorDecoration object);

    /**
     * @brief Creates Entities for all objects on the provided Tile
     * @param tile - the Tile to create Entities from.
     * @return the created Entities.
     */
    QList<Entity*> createEntities(RS::Tile tile);

    /**
     * @brief Creates all Entities accessible at this moment.
     *
     * This is a potentially time-consuming operation, as it tries to
     * create Entity objects for all accessible entities.
     */
    void createEntities();

public slots:
    /**
     * @brief Updates the World representation with the current state.
     *
     */
    void processTick();
};

#endif // WORLDGENERATOR_H
