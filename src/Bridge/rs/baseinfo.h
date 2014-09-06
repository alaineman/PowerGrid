#ifndef API_BRIDGE_BASEINFO_H
#define API_BRIDGE_BASEINFO_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

/**
 * @brief Represents a base tile
 *
 * The BaseInfo indicates the minimum (x,y) of a RS world map segment.
 * Positions in the world are normally relative to a certain BaseInfo
 * position.
 *
 * The current BaseInfo used to relativize positions can be found at
 * @c Client::getLandscapeInfo().getBaseInfo().
 *
 */
class BaseInfo : public Object {
public:
    RS_OBJECT(BaseInfo)

    /**
     * @brief the minimum X coordinate of this BaseInfo
     * @return the minimum X coordinate
     */
    JACE_PROXY_API JInt getMinX();

    /**
     * @brief the minimum Y coordinate of this BaseInfo
     * @return the minimum Y coordinate
     */
    JACE_PROXY_API JInt getMinY();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_BASEINFO_H
