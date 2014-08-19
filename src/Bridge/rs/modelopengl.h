#ifndef API_BRIDGE_MODELOPENGL_H
#define API_BRIDGE_MODELOPENGL_H

#include "MethodHelper.h"
#include "abstractmodel.h"
using namespace java::lang;


namespace RS {

class ModelOpenGL : public AbstractModel {
public:
    RS_OBJECT(ModelOpenGL)

    JACE_PROXY_API QList<JInt> getVerticesX();
    JACE_PROXY_API QList<JInt> getVerticesY();
    JACE_PROXY_API QList<JInt> getVerticesZ();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_MODELOPENGL_H
