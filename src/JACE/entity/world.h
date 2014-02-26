#ifndef WORLD_H
#define WORLD_H

#include <QObject>

#ifdef Q_COMPILER_INITIALIZER_LISTS
#include <initializer_list>
using std::initializer_list;
#endif

namespace entity {

class Entity;
class Component;

/**
 * @brief Management class for Entity objects.
 *
 */
class World : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(World)
private:
    friend class Entity;

    void addEntity(Entity* e);

    static World* theWorld = new World();

    QMap<QString, QList<Entity*>> componentMap; // maps Component className => list of Entities with that Component
public:
    /**
     * \brief Returns the global World instance
     * \return the global World instance
     */
    static World* instance() { return theWorld; }

    /**
     * \brief Creates a new World instance.
     *
     * A global instance can be retrieved by calling \c instance(), so calling
     * this constructor is not really required unless you want to set up
     * a separate World of Entities.
     */
    explicit World() {}

    /**
     * @brief Creates a new Entity in this World
     * @return the created Entity
     */
    Entity* createEntity();

    /**
     * \brief Deletes the entity at some point in the future.
     *
     * It cannot be guaranteed the Entity is removed immediately.
     * It will be removed at the end of the current cycle.
     * \param e
     */
    void deleteEntity(Entity* e);

#ifdef Q_COMPILER_INITIALIZER_LISTS
    /**
     * \brief Convenience function to create an Entity with Components in one go.
     *
     * Your compiler must support C++11 initializer lists to make use of this
     * function.
     *
     * \param comps the Components to add
     * \return a pointer to the created Entity
     */
    Entity* createEntity(initializer_list<Component*> comps);
#endif
signals:

public slots:

};

}

#endif // WORLD_H
