#ifndef API_COMPONENT_INTERACTION_H
#define API_COMPONENT_INTERACTION_H

#include "entity/component.h"
#include "jace/JField.h"

using entity::Component;
using jace::JField;

namespace api {
namespace component {

using java::lang::Object;
class Action;

/**
 * \brief Adds interactions to an Entity.
 *
 * This Component type can be used to assign actions to Entities in the
 * Runescape world. These actions can relate to actual actions available
 * in the Runescape client, or actions added by PowerGrid (or any of its Plugins).
 */
class Interaction : public Component {
    Q_OBJECT
private:
    QMap<QString, Action*> actions;
public:
    /**
     * @brief Creates a new Interaction Component
     * @param _actions the actions that can be performed
     * @param ref [optional] the reference Object
     * @param parent [optional] the parent of this Component
     */
    explicit Interaction(QMap<QString, Action*> _actions, Object ref = Object(),
                         entity::Entity *parent = 0);

    /**
     * @brief Returns the Action* with the given name.
     *
     * If no Action exists with that name, a NULL pointer is
     * returned.
     * @param name the name of the requested Action
     * @return the Action, or NULL if it doesn't exist.
     */
    Action* getAction(QString name) const;
    /**
     * @brief Returns a QMap with all available Actions
     *
     * The returned QMap maps the name of the Action to the
     * Action*.
     * @return a QMap with the available Actions.
     */
    QMap<QString, Action*> getActionMap() const;

};
} // namespace component
} // namespace api

#endif // API_COMPONENT_INTERACTION_H
