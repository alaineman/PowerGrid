#ifndef API_BRIDGE_FLOATSTREAM_H
#define API_BRIDGE_FLOATSTREAM_H

#include "MethodHelper.h"
#include "stream.h"

namespace api {
namespace bridge {

class FloatStream : public Stream {
public:
    RS_OBJECT(FloatStream)
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_FLOATSTREAM_H
