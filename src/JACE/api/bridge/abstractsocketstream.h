#ifndef ABSTRACTSOCKETSTREAM_H
#define ABSTRACTSOCKETSTREAM_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class AbstractSocketStream : public Object {
public:
    RS_OBJECT(AbstractSocketStream)
private:
    DECLARE_FRIENDS
};

}
}
#endif // ABSTRACTSOCKETSTREAM_H
