#ifndef API_BRIDGE_STREAM_H
#define API_BRIDGE_STREAM_H

#include "MethodHelper.h"
#include "node.h"


namespace RS {

class Stream : public Node {
public:
    RS_OBJECT(Stream)

    JACE_PROXY_API QList<JByte> getBuffer();
    JACE_PROXY_API JInt getOffset();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_STREAM_H
