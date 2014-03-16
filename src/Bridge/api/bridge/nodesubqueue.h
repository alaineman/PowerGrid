#ifndef API_BRIDGE_NODESUBQUEUE_H
#define API_BRIDGE_NODESUBQUEUE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class NodeSub;
/**
 * @brief Represents a list of NodeSubs only accessible by the tail of the list.
 *
 * The tail of the list is accessible through @c getTail().
 *
 * @internal Isn't it actually a stack when you can only access the tail?
 */
class NodeSubQueue : public Object {
public:
    RS_OBJECT(NodeSubQueue)

    /**
     * @brief Returns the tail of this list
     * @return the tail of this list.
     */
    JACE_PROXY_API NodeSub getTail();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_NODESUBQUEUE_H
