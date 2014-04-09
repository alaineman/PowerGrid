#ifndef ENTITY_MAPPER_H
#define ENTITY_MAPPER_H

#include <QObject>
#include <QMap>

namespace entity {

class World;
class Component;
class Entity;

/**
 * \brief Indexes Entities based on their Components.
 *
 * This class is useful to quickly lookup Entities with specific
 * characteristics. For instance, this class allows logarithmic time
 * lookup for Entities with a specific Name (opposed to linear time
 * when using Matchers only).
 *
 * This class may be subclassed to provide better support for certain
 * types of Components. This is useful, for instance, when the Component
 * type can be hashed. In that case, a QHash can be used instead of a
 * regular QMap, which may improve performance even further (causing
 * Name lookups to execute in near-constant time).
 *
 * \author Patrick Kramer
 */
class Mapper : public QObject{
    Q_OBJECT
    Q_DISABLE_COPY(Mapper)
private:
    QString type;
    QMap<Component*,Entity*> map;
public:
    /**
     * \brief Creates a new Mapper.
     * \param type the type of Component to map (as a QString)
     * \param init true to initialize the Mapper. Default is true
     * \param parent the World to initialize with. Default is World::instance()
     */
    Mapper(QString type, bool init = true, World* parent = NULL);

    /**
     * \brief Returns whether this Mapper contains the provided Entity.
     *
     * This operation runs in logarithmic time. Subclasses may override this
     * to provide better implementations.
     *
     * \param e the Entity to look up
     * \return true if @c e is mapped by this Mapper, false otherwise
     */
    virtual bool contains(Entity* e) const;

    /**
     * \brief Returns the Entity mapped to the given key
     * \param key the key
     * \return the Entity mapped to the key, or NULL if no Entity is mapped
     */
    virtual Entity* getEntity(Component *key) const;

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
     * \param e the Entity
     * \param cmp the Component
     */
    virtual void remove(Entity* e, Component* cmp);
    /**
     * \brief Adds the Entity/Component binding to this Mapper
     *
     * If the Mapper does not map the provided Component's type, this does nothing.
     * Else, the provided Entity/Component mapping is added to this Mapper.
     * \param e the Entity
     * \param cmp the Component
     */
    virtual void add(Entity* e, Component* cmp);
};

} // namespace entity

#endif // ENTITY_MAPPER_H
