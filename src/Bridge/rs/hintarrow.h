#ifndef API_BRIDGE_HINTARROW_H
#define API_BRIDGE_HINTARROW_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class HintArrow : public Object {
public:
    RS_OBJECT(HintArrow)

    JACE_PROXY_API JInt getHeadIconIndex();
    JACE_PROXY_API JInt getLocalX();
    JACE_PROXY_API JInt getLocalY();
    JACE_PROXY_API JInt getPlane();
    JACE_PROXY_API JInt getTargetIndex();
    JACE_PROXY_API JInt getType();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_HINTARROW_H
