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
#ifndef ENTITY_MAPPER_H
#define ENTITY_MAPPER_H

#include <QObject>
#include <QMultiMap>
#include <QMultiHash>
#include "component.h"

namespace entity {

class World;
class Entity;

/**
 * @brief Indexes Entities based on their Components.
 *
 * This class is useful to quickly lookup Entities with specific
 * characteristics. For instance, this class allows near-constant time
 * lookup for Entities with a specific Name (opposed to linear time
 * when using Matchers only).
 *
 * The Mapper is capable of mapping a single key to multiple Entities.
 * For example, it is perfectly possible for multiple Entities to have
 * the same Position.
 *
 * The Mapper automatically optimizes its structure based on the Component
 * type. When the Component is a HashableComponent, the Mapper will use a
 * QMultiHash to store its data. Otherwise, a QMultiMap is used.
 *
 * To get a Mapper for a certain type, please use the getMapper(...) member
 * function in the World class. This allows multiple plugins and features to
 * use the same Mapper instance.
 *
 * @author Patrick Kramer
 */
class Mapper : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(Mapper)
public:
    /**
     * @brief Enum indicating the mode of a Mapper
     */
    enum Mode {
        Undefined = 0, ///< Indicates the Mode cannot be determined.
        HashMode  = 1, ///< Indicates a QMultiHash will be used.
        TreeMode  = 2  ///< Indicates a QMultiMap will be used.
    };
private:
    QString type;
    QMultiMap<Component*,Entity*> map;
    QMultiHash<HashableComponent*,Entity*> hashMap;
public:
    /**
     * \brief Returns the storage Mode that will be used for the provided type.
     *
     * This checks the Component argument for its type. If the Component is
     * a HashableComponent, then @c HashMode is returned. Otherwise,
     * @c TreeMode is used. If the Component* is NULL, @c Undefined is returned.
     *
     * \param c - the Component
     * \return the storage Mode that will be used
     */
    static Mode getMode(Component* c);

    /**
     * \brief Creates a new Mapper.
     * \param type   - the type of Component to map (as a QString)
     * \param init   - true to initialize the Mapper. Default is true
     * \param parent - the World to initialize with. Default is World::instance()
     */
    explicit Mapper(QString type, bool init = true, World* parent = NULL);

    /**
     * @brief Creates a new Mapper.
     * @param mObject - the type of Component to map (as a QMetaObject)
     * @param init    - true to initialize the Mapper. Default is true.
     * @param parent  - the World to initialize with. Default is World::instance()
     */
    explicit Mapper(QMetaObject mObject, bool init=true, World* parent = NULL);

    /**
     * \brief Returns whether this Mapper contains the provided Entity.
     *
     * This operation runs in logarithmic time. Subclasses may override this
     * to provide better implementations.
     *
     * \param e - the Entity to look up
     * \return true if @c e is mapped by this Mapper, false otherwise
     */
    virtual bool contains(Entity* e) const;

    /**
     * \brief Returns the Entity mapped to the given key
     * \param key - the key
     * \return the Entity mapped to the key, or NULL if no Entity is mapped
     */
    virtual Entity* getEntity(Component *key) const;

    /**
     * @brief Returns all Entities associated with the specified key
     * @param key - the key
     * @return a QList with all Entities associated with the key
     */
    virtual QList<Entity*> getEntities(Component *key) const;

    /**
     * \brief Returns the type of this Mapper (as a QString)
     * \return the name of the Component type mapped by this Mapper
     */
    QString getMappedType() const;
public slots:

    /**
     * \brief Removes the Entity/Component binding from this Mapper
     *
     * If the Mapper does not map the provided Component, this does nothing.
     * Else, the mapping for the provided Entity is removed from this Mapper.
     * \param e - the Entity
     * \param cmp the Component
     */
    virtual void remove(Entity* e, Component* cmp);
    /**
     * \brief Adds the Entity/Component binding to this Mapper.
     *
     * If the Mapper does not map the provided Component's type, this does nothing.
     * Else, the provided Entity/Component mapping is added to this Mapper.
     * \param e - the Entity
     * \param cmp the Component
     */
    virtual void add(Entity* e, Component* cmp);
};

} // namespace entity

#endif // ENTITY_MAPPER_H
