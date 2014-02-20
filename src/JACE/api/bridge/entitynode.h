#ifndef API_BRIDGE_ENTITYNODE_H
#define API_BRIDGE_ENTITYNODE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class EntityNode : public Object {
public:
    RS_OBJECT(EntityNode)

    JACE_PROXY_API EntityNode getNext();
    JACE_PROXY_API EntityNode getPrevious();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ENTITYNODE_H
