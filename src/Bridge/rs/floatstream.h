#ifndef API_BRIDGE_FLOATSTREAM_H
#define API_BRIDGE_FLOATSTREAM_H

#include "MethodHelper.h"
#include "stream.h"


namespace RS {

class FloatStream : public Stream {
public:
    RS_OBJECT(FloatStream)
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_FLOATSTREAM_H
