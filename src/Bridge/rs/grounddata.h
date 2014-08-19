#ifndef API_BRIDGE_GROUNDDATA_H
#define API_BRIDGE_GROUNDDATA_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class GroundData : public Object {
public:
    RS_OBJECT(GroundData)

    JACE_PROXY_API QList<QList<JInt>> getBlocks();
    JACE_PROXY_API JInt getX();
    JACE_PROXY_API JInt getY();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_GROUNDDATA_H
