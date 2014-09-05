#include "isaaccipher.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(ISAACCipher)
IMPL_RSCLASS_GET(ISAACCipher)

IMPL_PRIMITIVE_METHOD(ISAACCipher, getAccumulator, JInt)
IMPL_PRIMITIVE_METHOD(ISAACCipher, getCount, JInt)
IMPL_PRIMITIVE_METHOD(ISAACCipher, getCounter, JInt)
IMPL_PRIMITIVE_METHOD(ISAACCipher, getLast, JInt)
IMPL_ARRAY_METHOD(ISAACCipher, getMemory, JInt)
IMPL_ARRAY_METHOD(ISAACCipher, getResults, JInt)

} // namespace bridge
