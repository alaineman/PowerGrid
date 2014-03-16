#ifndef API_BRIDGE_QUEUE_H
#define API_BRIDGE_QUEUE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
#include "nodesub.h"
using namespace java::lang;

namespace api {
namespace bridge {

/**
 * @brief LinkedList-like Queue
 *
 * This Queue is implemented as a LinkedList of NodeSub objects,
 * and can be treated as such.
 *
 * @see api::bridge::NodeSub
 */
class Queue : public Object {
public:
    RS_OBJECT(Queue)

    JACE_PROXY_API NodeSub getCurrent();
    JACE_PROXY_API NodeSub getSentinel();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_QUEUE_H
