#ifndef API_BRIDGE_MLSTRING_H
#define API_BRIDGE_MLSTRING_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class MLString : public Object {
public:
    RS_OBJECT(MLString)
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_MLSTRING_H
