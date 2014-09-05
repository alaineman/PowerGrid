#include "interfacechild.h"
#include "interface.h"
#include "animator.h"
#include "java/lang/string.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(InterfaceChild)
IMPL_RSCLASS_GET(InterfaceChild)

IMPL_ARRAY_METHOD(InterfaceChild, getActions, String)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getAnimationID, JInt)
IMPL_OBJECT_METHOD(InterfaceChild, getAnimator, Animator)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getBorderThickness, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getBoundsArrayIndex, JInt)
IMPL_ARRAY_METHOD(InterfaceChild, getChildren, InterfaceChild)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getComponentID, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getComponentIndex, JInt)
IMPL_OBJECT_METHOD(InterfaceChild, getComponentName, String)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getComponentStackSize, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getDisplayTime, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getHeight, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, isHorizontallyFlipped, JBoolean)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getHorizontalScrollbarPosition, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getHorizontalScrollbarSize, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getHorizontalScrollbarThumbSize, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, isHovering, JBoolean)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getID, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, isInventoryInterface, JBoolean)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getModelID, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getModelType, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getModelZoom, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getParentID, JInt)
IMPL_OBJECT_METHOD(InterfaceChild, getParentInterface, Interface)
IMPL_OBJECT_METHOD(InterfaceChild, getParentInterfaceChild, InterfaceChild)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getRelativeX, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getRelativeY, JInt)
IMPL_OBJECT_METHOD(InterfaceChild, getSelectedActionName, String)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getShadowColor, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getSpecialType, JInt)
IMPL_OBJECT_METHOD(InterfaceChild, getText, String)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getTextColor, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getTextureID, JInt)
IMPL_OBJECT_METHOD(InterfaceChild, getTooltip, String)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getType, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, isVerticallyFlipped, JBoolean)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getVerticalScrollbarPosition, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getVerticalScrollbarSize, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getVerticalScrollbarThumbSize, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, isVisible, JBoolean)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getWidth, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getXRotation, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getYRotation, JInt)
IMPL_PRIMITIVE_METHOD(InterfaceChild, getZRotation, JInt)

} // namespace bridge
