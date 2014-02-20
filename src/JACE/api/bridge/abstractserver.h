#ifndef ABSTRACTSERVER_H
#define ABSTRACTSERVER_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class AbstractServer : public Object {
public:
    RS_OBJECT(AbstractServer)

    JACE_PROXY_API JInt getFlag();
private:
    DECLARE_FRIENDS
};

}
}
#endif // ABSTRACTSERVER_H
