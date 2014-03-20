#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include "entity/entity.h"
#include "entity/matcher.h"

#ifdef Q_COMPILER_INITIALIZER_LISTS
#include <initializer_list>
using std::initializer_list;
#endif

namespace entity {

class Component;

/**
 * @brief Management class for Entity objects.
 *
 * The World object maintains references to all Entities a
 */
class World : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(World)
private:
    friend class Entity;

    /**
     * @brief Adds a previously created Entity to this World.
     *
     * Please ensure the Entity is not already registered with another
     * World instance, as this may lead to unexpected behavior.
     * @param e
     */
    void addEntity(Entity* e);

    static World* theWorld;

    QList<Entity*> entities;
    QMap<QString, QList<Entity*>> componentMap; // maps Component className => list of Entities with that Component
    QMap<QString, QList<Matcher*>> matchers;
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
    World() {}
    ~World() Q_DECL_NOTHROW;

    /**
     * @brief Creates a new Entity in this World
     * @return the created Entity
     */
    Entity* createEntity();

    /**
     * @brief Returns the amount of entities in this World
     */
    int count();

    /**
     * \brief Adds a Matcher to this World.
     * \param m the Matcher to add
     */
    void addMatcher(Matcher* m);
    /**
     * \brief Removes a Matcher from this World.
     * \param m the Matcher to remove
     */
    void removeMatcher(Matcher* m);

#if defined(Q_COMPILER_INITIALIZER_LISTS) || defined(PG_DOC)
    /**
     * \brief Convenience function to create an Entity with Components in one go.
     *
     * Your compiler must support C++11 initializer lists to make use of this
     * feature.
     *
     * This allows creation of Entities with Components like this:
     *
     *      Entity* e = world->createEntity({new MyComponent1(), new MyComponent2()});
     *
     * This line behaves the same as:
     *
     *      Entity* e = world->createEntity();
     *      e->addComponent(new MyComponent1());
     *      e->addComponent(new MyComponent2());
     *
     * \param comps the Components to add
     * \return a pointer to the created Entity
     */
    Entity* createEntity(initializer_list<Component*> comps);
#endif

signals:
    /**
     * @brief signal emitted when a new Entity is created.
     * @param e the newly created Entity.
     */
    void entityCreated(Entity* e);

    void componentAdded(Entity* e, Component* c);

    void componentRemoved(Entity* e, Component* c);

    /**
     * \brief signal emitted when processing of Entities has started
     */
    void processingStarted();
    /**
     * \brief signal emitted when processing of Entities has finished
     */
    void processingFinished();
public slots:
    /**
     * \brief Deletes the entity at some point in the future.
     *
     * It cannot be guaranteed the Entity is removed immediately.
     * It will be removed at the end of the current cycle.
     *
     * For safety, the Entity should no longer be used after this is
     * invoked.
     * \param e the Entity to delete
     */
    void deleteEntity(Entity* e);

    /**
     * \brief Processes the Entities.
     *
     * This is usually invoked based on a schedule. Manually invoking
     * this may cause issues.
     */
    void processAll();
};

}
#endif // WORLD_H
