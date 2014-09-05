#ifndef API_BRIDGE_LANDSCAPE_H
#define API_BRIDGE_LANDSCAPE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class Landscape : public Object {
public:
    RS_OBJECT(Landscape)

    JACE_PROXY_API QList<QList<JInt>> getLocalTileHeights();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_LANDSCAPE_H
