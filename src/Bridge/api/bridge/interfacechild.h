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
/*!
 * \brief The InterfaceChild class
 *
 * The InterfaceChild class contains the actual information being an interface component.
 * Also an InterfaceChild can have one or more children itself. This is set up recursively,
 * making it common for first generation Childs to have grandchildren.
 */
class InterfaceChild : public Object {
public:
    RS_OBJECT(InterfaceChild)

    /*!
     * \brief The actions corresponding to this InterfaceChild
     *
     * \return A QList of Strings with names of the actions.
     */
    JACE_PROXY_API QList<String> getActions();

    /*!
     * \brief The animation corresponding to this InterfaceChild
     *
     * Some InterFaceChilds have animations (example: you level up).
     *
     * \return Animation ID, the integer corresponding to that particular animation.
     */
    JACE_PROXY_API JInt getAnimationID();
    JACE_PROXY_API Animator getAnimator();
    JACE_PROXY_API JInt getBorderThickness();
    JACE_PROXY_API JInt getBoundsArrayIndex();

    /*!
     * \brief The Children belong to this InterFaceChild.
     *
     * This methods allows for tree based structure of the InterfaceChild objects.
     *
     * \return A QList of InterfaceChild.
     */
    JACE_PROXY_API QList<InterfaceChild> getChildren();

    /*!
     * \brief The ID corresponding to this InterfaceChild's component.
     *
     * An InterfaceChild can contain an component. This often is an Item.
     * Some examples:
     * \li Bank slot
     * \li Intenventory slot
     * \li Store slot
     * \li Equipment slot
     * \li Abilitybar slot
     *
     * For items this ID corresponds with the ID from the ItemDef.
     *
     * \return The ID (integer) of the component.
     */
    JACE_PROXY_API JInt getComponentID();
    JACE_PROXY_API JInt getComponentIndex();

    /*!
     * \brief The name corresponding to this InterfaceChild's component.
     *
     * \return The name of the component.
     */
    JACE_PROXY_API String getComponentName();

    /*!
     * \brief The stacksize of the InterfaceChild component.
     *
     * An InterfaceChild can contain an component. This often is an Item.
     * This mainly relevant for Items obviously.
     *
     * \return The stacksize of the component.
     */
    JACE_PROXY_API JInt getComponentStackSize();
    JACE_PROXY_API JInt getDisplayTime();

    /*!
     * \brief Returns the height corresponding to this InterfaceChild.
     */
    JACE_PROXY_API JInt getHeight();
    JACE_PROXY_API JBoolean isHorizontallyFlipped();
    JACE_PROXY_API JInt getHorizontalScrollbarPosition();
    JACE_PROXY_API JInt getHorizontalScrollbarSize();
    JACE_PROXY_API JInt getHorizontalScrollbarThumbSize();
    JACE_PROXY_API JBoolean isHovering();

    /*!
     * \brief The ID corresponding to this InterfaceChild itself.
     *
     * \return The integer (ID) of this InterFaceChild object.
     */
    JACE_PROXY_API JInt getID();
    JACE_PROXY_API JBoolean isInventoryInterface();
    JACE_PROXY_API JInt getModelID();
    JACE_PROXY_API JInt getModelType();
    JACE_PROXY_API JInt getModelZoom();

    /*!
     * \brief The ID corresponding to the parent InterfaceChild.
     *
     * \return The ID of the parent InterFaceChild.
     */
    JACE_PROXY_API JInt getParentID();

    /*!
     * \brief Returns the Interface Object corresponding to this InterfaceChild root of the InterFaceChild tree.
     *
     * The parent InterFace is the root of the InterFaceChild tree.
     * In other words, the parent of the first generation Childs.
     *
     * \return The InterFace.
     */
    JACE_PROXY_API Interface getParentInterface();

    /*!
     * \brief Returns the parent InterFaceChild.
     *
     * If the InterFaceChild itself is a first generation Child than no parent InterFaceChild can be retrieved.
     * Hence NULL is returned.
     *
     * \return The parent InterFaceChild object.
     */
    JACE_PROXY_API InterfaceChild getParentInterfaceChild();
    JACE_PROXY_API JInt getRelativeX();
    JACE_PROXY_API JInt getRelativeY();
    JACE_PROXY_API String getSelectedActionName();
    JACE_PROXY_API JInt getShadowColor();
    JACE_PROXY_API JInt getSpecialType();

    /*!
     * \brief The text inside the InterfaceChild itself.
     */
    JACE_PROXY_API String getText();

    /*!
     * \brief Returns the colorvalue of the text.
     *
     * Note: there is not always text, hence not always a textcolor.
     *
     * \return The color value of the text.
     */
    JACE_PROXY_API JInt getTextColor();
    JACE_PROXY_API JInt getTextureID();
    JACE_PROXY_API String getTooltip();
    JACE_PROXY_API JInt getType();
    JACE_PROXY_API JBoolean isVerticallyFlipped();
    JACE_PROXY_API JInt getVerticalScrollbarPosition();
    JACE_PROXY_API JInt getVerticalScrollbarSize();
    JACE_PROXY_API JInt getVerticalScrollbarThumbSize();
    JACE_PROXY_API JBoolean isVisible();

    /*!
     * \brief Returns the width corresponding to this InterfaceChild.
     */
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
