#ifndef API_BRIDGE_FRIEND_H
#define API_BRIDGE_FRIEND_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Friend : public Object {
public:
    RS_OBJECT(Friend)
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_FRIEND_H
