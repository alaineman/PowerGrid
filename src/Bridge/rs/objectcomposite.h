#ifndef API_BRIDGE_OBJECTCOMPOSITE_H
#define API_BRIDGE_OBJECTCOMPOSITE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class ModelLD;
class ObjectComposite : public Object {
public:
    RS_OBJECT(ObjectComposite)

    JACE_PROXY_API ModelLD getModel();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_OBJECTCOMPOSITE_H
