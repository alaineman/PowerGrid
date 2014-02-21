#ifndef API_BRIDGE_DEQUE_H
#define API_BRIDGE_DEQUE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Node;

class Deque : public Object {
public:
    RS_OBJECT(Deque)

    JACE_PROXY_API Node getCurrent();
    JACE_PROXY_API Node getSentinel();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_DEQUE_H
