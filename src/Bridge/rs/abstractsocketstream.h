#ifndef ABSTRACTSOCKETSTREAM_H
#define ABSTRACTSOCKETSTREAM_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace RS {

/*!
 * \brief Abstract version of the SocketStream class.
 */
class AbstractSocketStream : public Object {
public:
    RS_OBJECT(AbstractSocketStream)
private:
    DECLARE_FRIENDS
};

}

#endif // ABSTRACTSOCKETSTREAM_H
