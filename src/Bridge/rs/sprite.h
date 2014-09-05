#ifndef API_BRIDGE_SPRITE_H
#define API_BRIDGE_SPRITE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class Sprite: public Object {
public:
    RS_OBJECT(Sprite)
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_SPRITE_H
