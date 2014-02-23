#ifndef API_BRIDGE_MODELOPENGL_H
#define API_BRIDGE_MODELOPENGL_H

#include "MethodHelper.h"
#include "abstractmodel.h"
using namespace java::lang;

namespace api {
namespace bridge {

class ModelOpenGL : public AbstractModel {
public:
    RS_OBJECT(ModelOpenGL)

    JACE_PROXY_API QList<JInt> getVerticiesX();
    JACE_PROXY_API QList<JInt> getVerticiesY();
    JACE_PROXY_API QList<JInt> getVerticiesZ();

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_MODELOPENGL_H
