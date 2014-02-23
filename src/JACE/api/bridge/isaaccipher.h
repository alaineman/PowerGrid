#ifndef API_BRIDGE_ISAACCIPHER_H
#define API_BRIDGE_ISAACCIPHER_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class ISAACCipher : public Object {
public:
    RS_OBJECT(ISAACCipher)

    JACE_PROXY_API JInt getAccumulator();
    JACE_PROXY_API JInt getCount();
    JACE_PROXY_API JInt getCounter();
    JACE_PROXY_API JInt getLast();
    JACE_PROXY_API QList<JInt> getMemory();
    JACE_PROXY_API QList<JInt> getResults();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ISAACCIPHER_H
