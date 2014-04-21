#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include "entity/entity.h"
#include "entity/matcher.h"
#include "entity/mapper.h"

#ifdef Q_COMPILER_INITIALIZER_LISTS
#include <initializer_list>
using std::initializer_list;
#endif

namespace entity {

class Component;
class Classifier;

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
     * @param e the Entity to add
     */
    void addEntity(Entity* e);

    static World* theWorld;

    QList<Entity*> entities;
    QHash<QString, QList<Entity*>> componentMap; // maps Component className => list of Entities with that Component
    QHash<QString, QList<Matcher*>> matchers;    // maps Component className => list of Matcher for that Component type
    QHash<QString, Mapper*> mappers;             // maps Component className => Mapper for that Component type
    QList<Classifier*> classifiers;              // lists all registered Classifiers.
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
     * \brief Returns the Mapper instance for the Type
     *
     * Any two Mapper* with the same Type returned by this member
     * function are guaranteed to point to the same Mapper instance.
     *
     * This is a convenience function for @c getMapper(QString).
     * It allows Mapper to be acquired like this:
     *     Mapper* nameMapper = world->getMapper<Name>();
     *
     * \param Type the Type
     * \return the Mapper instance that maps the provided Type
     */
    template<class Type> Mapper* getMapper();

    /**
     * \brief Returns the Mapper instance for the Type with the given name
     *
     * Any two Mapper* with the same Type returned by this member
     * function are guaranteed to point to the same Mapper instance.
     *
     * \param Type the Type
     * \return the Mapper instance that maps the provided Type
     */
    Mapper* getMapper(QString type);

#if defined(Q_COMPILER_INITIALIZER_LISTS) || defined(PG_DOC)
    /**
     * \brief Convenience function to create an Entity with Components in one go.
     *
     * Your compiler must support C++11 initializer lists to make use of this
     * member function.
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

    /**
     * @brief Signal emitted when a Component is added to an Entity
     * @param e the Entity
     * @param c the Component that was added
     */
    void componentAdded(Entity* e, Component* c);

    /**
     * @brief Signal emitted when a Component is removed from an Entity
     * @param e the Entity
     * @param c the Component that was removed
     */
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
     * this may cause a variety of issues.
     */
    void processAll();

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

    /**
     * \brief Adds a Classifier to this World
     * \param classifier the Classifier to add
     */
    void addClassifier(Classifier* classifier);

    /**
     * \brief Removes a Classifier from this World
     * \param classifier the Classifier to remove
     */
    void removeClassifier(Classifier* classifier);

    /**
     * \brief Initializes the provided Mapper for this World
     *
     * The Mapper is updated with the current state, and registered with this World.
     * This function should be invoked exactly once for each Mapper instance, invoking
     * it more than once for a single Mapper may lead to undesired effects.
     *
     * Also, the default Mapper implementation already invokes this when it's created,
     * so this should only be invoked for Mapper created with the \c init parameter set
     * to false.
     *
     * \param mapper the Mapper to initialize.
     */
    void initMapper(Mapper* mapper);
};

}
#endif // WORLD_H
