#ifndef API_BRIDGE_MODELDIRECTX_H
#define API_BRIDGE_MODELDIRECTX_H

#include "MethodHelper.h"
#include "abstractmodel.h"
using namespace java::lang;


namespace api {
namespace bridge {

class ToolkitDirectX;

class ModelDirectX : public AbstractModel {
public:
    RS_OBJECT(ModelDirectX)

    JACE_PROXY_API ToolkitDirectX getToolkit();
    JACE_PROXY_API QList<JByte> getTriangleAlphas();
    JACE_PROXY_API QList<JShort> getTriangleColors();
    JACE_PROXY_API JInt getTriangleCount();
    JACE_PROXY_API QList<JShort> getTriangleX();
    JACE_PROXY_API QList<JShort> getTriangleY();
    JACE_PROXY_API QList<JShort> getTriangleZ();
    JACE_PROXY_API JInt getVertexCount();
    JACE_PROXY_API QList<JInt> getVerticesX();
    JACE_PROXY_API QList<JInt> getVerticesY();
    JACE_PROXY_API QList<JInt> getVerticesZ();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_MODELDIRECTX_H
