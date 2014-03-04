#ifndef API_BRIDGE_FRIEND_H
#define API_BRIDGE_FRIEND_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

/*!
 * \brief Represents Friends from the Runescape friendlist interface.
 *
 * Friends on the Friends List can contain a number of details
 * about the friend.
 *
 * Friend objects are displayed as a list on the interface child Friends List
 *
 */

class Friend : public Object {
public:
    RS_OBJECT(Friend)

    //Missing methods...
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_FRIEND_H
