#include "grandexchangeoffer.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(GrandExchangeOffer)
IMPL_RSCLASS_GET(GrandExchangeOffer)

IMPL_PRIMITIVE_METHOD(GrandExchangeOffer, getID, JLong)
IMPL_PRIMITIVE_METHOD(GrandExchangeOffer, getPrice, JInt)
IMPL_PRIMITIVE_METHOD(GrandExchangeOffer, getSpent, JInt)
IMPL_PRIMITIVE_METHOD(GrandExchangeOffer, getState, JByte)
IMPL_PRIMITIVE_METHOD(GrandExchangeOffer, getTotal, JInt)
IMPL_PRIMITIVE_METHOD(GrandExchangeOffer, getTransferred, JInt)

} // namespace bridge
} // namespace api
