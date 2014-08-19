#ifndef API_BRIDGE_DETAILINFONODE_H
#define API_BRIDGE_DETAILINFONODE_H

#include "MethodHelper.h"
#include "node.h"


namespace RS {

class DetailInfoNode : public Node {
public:
    RS_OBJECT(DetailInfoNode)
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_DETAILINFONODE_H
