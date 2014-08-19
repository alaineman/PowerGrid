#ifndef API_BRIDGE_MODELLD_H
#define API_BRIDGE_MODELLD_H

#include "MethodHelper.h"
#include "abstractmodel.h"
using namespace java::lang;


namespace RS {

class ToolkitLD;
class ModelLD : public AbstractModel {
public:
    RS_OBJECT(ModelLD)

    JACE_PROXY_API ToolkitLD getToolkit();
    JACE_PROXY_API QList<JByte> getTriangleAlphas();
    JACE_PROXY_API QList<JShort> getTriangleColors();
    JACE_PROXY_API JInt getTriangleCount();
    JACE_PROXY_API QList<JShort> getTriangleX();
    JACE_PROXY_API QList<JShort> getTriangleY();
    JACE_PROXY_API QList<JShort> getTriangleZ();
    JACE_PROXY_API JInt getVertexCount();
    JACE_PROXY_API QList<JInt> getVerticiesX();
    JACE_PROXY_API QList<JInt> getVerticiesY();
    JACE_PROXY_API QList<JInt> getVerticiesZ();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_MODELLD_H
