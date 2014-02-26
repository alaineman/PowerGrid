#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>

/**
 * Contains classes related to the Entity framework.
 */
namespace entity {

class Component;

/**
 * \brief The Entity class
 *
 * This class represents an Entity in the runescape world.
 * Properties can be added to Entities in the form of Components.
 *
 * \see entity::Component
 * \author Patrick Kramer
 */
class Entity : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(Entity)
private:
    QMap<QString, Component*> components; // maps className => Component
public:

    /**
     * \brief Creates a new Entity
     * \param parent the parent of this Entity
     */
    explicit Entity(QObject *parent = 0);

    /**
     * \brief Finds the Component of the given type.
     *
     * Suppose there is an Entity named e and a Component
     * type named \c MyComponent.
     * Then the following invocation would return the
     * component of the \c MyComponent type:
     * > MyComponent* myComp = e->get<MyComponent>();
     * \return a pointer to the requested Component
     *         type, or NULL if this Entity has no
     *         Component of that Type.
     */
    template<typename Type> Type* get() Q_REQUIRED_RESULT;

    /**
     * \brief Finds the Component of the given type
     *
     * \param name the name of the component type, as given by a
     *        component's \c getMetaObject()->className().
     */
    Component* get(QString name) Q_REQUIRED_RESULT;

    /**
     * \brief Returns whether a Component of the given Type exists.
     *
     * \return true if an Entity with the given type exists, false otherwise.
     */
    template<typename Type> bool has() Q_REQUIRED_RESULT;

signals:

    /**
     * @brief Emitted when a Component has been added
     * @param the added Component
     */
    void componentAdded(Component* cmp);

    /**
     * @brief Emitted when a Component has been removed
     * @param the removed Component
     */
    void componentRemoved(Component* cmp);

public slots:

    /**
     * @brief Adds the given Component to this Entity.
     * @param cmp the Component to add.
     * @param overwrite (optional) true to allow overwriting any existing Component
     *        of the same type, false to prevent this. The default is false.
     */
    void addComponent(Component* cmp, bool overwrite=false);

    /**
     * @brief Removes the given Componenty from this Entity
     * @param cmp the Component to remove
     */
    void removeComponent(Component* cmp);
};

}

#endif // ENTITY_H
