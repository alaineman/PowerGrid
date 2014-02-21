#ifndef API_BRIDGE_SPRITE_H
#define API_BRIDGE_SPRITE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Sprite: public Object {
public:
    RS_OBJECT(Sprite)
private:
    DECLARE_FRIENDS
};
} // namespace bridge
} // namespace api

#endif // API_BRIDGE_SPRITE_H
