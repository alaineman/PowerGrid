#include "packetstream.h"
#include "isaaccipher.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(PacketStream, Stream)
IMPL_RSCLASS_GET(PacketStream)

IMPL_OBJECT_METHOD(PacketStream, getISAACCipher, ISAACCipher)


} // namespace bridge

