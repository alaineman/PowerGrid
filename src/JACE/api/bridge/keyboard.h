#ifndef API_BRIDGE_KEYBOARD_H
#define API_BRIDGE_KEYBOARD_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Keyboard : public Object {
public:
    RS_OBJECT(Keyboard)
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_KEYBOARD_H
