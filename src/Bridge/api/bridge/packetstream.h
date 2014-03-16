#ifndef API_BRIDGE_PACKETSTREAM_H
#define API_BRIDGE_PACKETSTREAM_H

#include "MethodHelper.h"
#include "stream.h"
using namespace java::lang;

namespace api {
namespace bridge {

class ISAACCipher;
class PacketStream : public Stream {
public:
    RS_OBJECT(PacketStream)

    JACE_PROXY_API ISAACCipher getISAACCipher();

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_PACKETSTREAM_H
