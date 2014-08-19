#ifndef API_BRIDGE_REFERENCE_H
#define API_BRIDGE_REFERENCE_H

#include "MethodHelper.h"
#include "nodesub.h"


namespace RS {

class Reference : public NodeSub {
public:
    RS_OBJECT(Reference)

    JACE_PROXY_API JInt getIndex();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_REFERENCE_H
