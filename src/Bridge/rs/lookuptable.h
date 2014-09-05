#ifndef API_BRIDGE_LOOKUPTABLE_H
#define API_BRIDGE_LOOKUPTABLE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class LookupTable : public Object {
public:
    RS_OBJECT(LookupTable)

    JACE_PROXY_API QList<JInt> getIdentityTable();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_LOOKUPTABLE_H
