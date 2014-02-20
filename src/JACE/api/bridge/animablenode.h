#ifndef ANIMABLENODE_H
#define ANIMABLENODE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Animable;

class AnimableNode : public Object {
public:
    RS_OBJECT(AnimableNode)

    //JACE_PROXY_API Animable getAnimable();
    JACE_PROXY_API AnimableNode getNext();
private:
    DECLARE_FRIENDS
};

}
}
#endif // ANIMABLENODE_H
