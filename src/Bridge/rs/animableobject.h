#ifndef API_BRIDGE_ANIMABLEOBJECT_H
#define API_BRIDGE_ANIMABLEOBJECT_H

#include "MethodHelper.h"
#include "animable.h"


namespace RS {

class ObjectDefLoader;
class ModelLD;

/**
 * @brief The AnimableObject class
 *
 * Represents an @c Animable Object.
 *
 */
class AnimableObject : public Animable {
public:
    RS_OBJECT(AnimableObject)

    /**
     * @brief Returns the ID of this AnimableObject
     * @return the ID of this AnimableObject
     */
    JACE_PROXY_API JInt getID();

    /**
     * @brief Returns the Model for this AnimableObject
     * @return the Model for this AnimableObject
     */
    JACE_PROXY_API ModelLD getModel();

    /**
     * @brief Returns the x coordinate of this AnimableObject
     * @return the x coordinate of this AnimableObject
     */
    JACE_PROXY_API JInt getLocationX();

    /**
     * @brief Returns the y coordinate of this AnimableObject
     * @return the y coordinate of this AnimableObject
     */
    JACE_PROXY_API JInt getLocationY();

    /**
     * @brief Returns the ObjectDefLoader used to load this AnimableObject
     *
     * The ObjectDefLoader contains the definition for this AnimableObject's type
     * (as given by @c getID()).
     * @return the ObjectDefLoader for this AnimableObject
     */
    JACE_PROXY_API ObjectDefLoader getObjectDefLoader();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_ANIMABLEOBJECT_H
