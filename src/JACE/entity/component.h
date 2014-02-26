#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>

namespace entity {

/**
 * \brief base class for all components.
 *
 * Components are assigned to Entities to give them properties.
 * The Component class by itself does not define any properties.
 * As such, directly creating a Component instance is usually
 * pointless.
 *
 * \author Patrick Kramer
 */
class Component : public QObject {
    Q_OBJECT
public:
    /**
     * \brief Creates a new Component with the given parent
     *
     * \param parent the parent of this Component
     */
    explicit Component(QObject *parent = 0);
};

}

#endif // COMPONENT_H
