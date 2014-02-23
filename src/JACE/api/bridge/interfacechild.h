#ifndef API_BRIDGE_INTERFACECHILD_H
#define API_BRIDGE_INTERFACECHILD_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

// Forward declarations of Java API classes
namespace java {
 namespace lang {
  class String;
 }
}

namespace api {
namespace bridge {

class Animator;
class Interface;
class InterfaceChild : public Object {
public:
    RS_OBJECT(InterfaceChild)

    JACE_PROXY_API QList<String> getActions();
    JACE_PROXY_API JInt getAnimationID();
    JACE_PROXY_API Animator getAnimator();
    JACE_PROXY_API JInt getBorderThickness();
    JACE_PROXY_API JInt getBoundsArrayIndex();
    JACE_PROXY_API QList<InterfaceChild> getChildren();
    JACE_PROXY_API JInt getComponentID();
    JACE_PROXY_API JInt getComponentIndex();
    JACE_PROXY_API String getComponentName();
    JACE_PROXY_API JInt getComponentStackSize();
    JACE_PROXY_API JInt getDisplayTime();
    JACE_PROXY_API JInt getHeight();
    JACE_PROXY_API JInt getHorizontalScrollbarPosition();
    JACE_PROXY_API JInt getHorizontalScrollbarSize();
    JACE_PROXY_API JInt getHorizontalScrollbarThumbSize();
    JACE_PROXY_API JInt getID();
    JACE_PROXY_API JInt getModelID();
    JACE_PROXY_API JInt getModelType();
    JACE_PROXY_API JInt getModelZoom();
    JACE_PROXY_API JInt getParentID();
    JACE_PROXY_API Interface getParentInterface();
    JACE_PROXY_API InterfaceChild getParentInterfaceChild();
    JACE_PROXY_API JInt getRelativeX();
    JACE_PROXY_API JInt getRelativeY();
    JACE_PROXY_API String getSelectedActionName();
    JACE_PROXY_API JInt getShadowColor();
    JACE_PROXY_API JInt getSpecialType();
    JACE_PROXY_API String getText();
    JACE_PROXY_API JInt getTextColor();
    JACE_PROXY_API JInt getTextureID();
    JACE_PROXY_API String getTooltip();
    JACE_PROXY_API JInt getType();
    JACE_PROXY_API JInt getVerticalScrollbarPosition();
    JACE_PROXY_API JInt getVerticalScrollbarSize();
    JACE_PROXY_API JInt getVerticalScrollbarThumbSize();
    JACE_PROXY_API JInt getWidth();
    JACE_PROXY_API JInt getXRotation();
    JACE_PROXY_API JInt getYRotation();
    JACE_PROXY_API JInt getZRotation();

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_INTERFACECHILD_H
