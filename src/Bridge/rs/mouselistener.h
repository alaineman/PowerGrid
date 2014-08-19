#ifndef API_BRIDGE_MOUSE_H
#define API_BRIDGE_MOUSE_H

#include "MethodHelper.h"
#include "abstractmouselistener.h"

namespace java {
 namespace awt {
  class Component;

  namespace event {
   class MouseEvent;
  }
 }
}

using java::awt::Component;
using java::awt::event::MouseEvent;


namespace RS {

/**
 * @brief Listener class for Mouse events.
 *
 * This class acts as the listener for Mouse events in the RS client.
 * It also provides information about the state of the mouse.
 */
class MouseListener : public AbstractMouseListener {
public:
    RS_OBJECT(MouseListener)

    // This class is supposed to serve as both MouseListener and
    // MouseMotionListener in the Client. We just implement the
    // proxy methods here instead of in separate classes
    // because they will only ever be used for this class anyway.

    //FIXME The mouseXXX methods take MouseData objects, right?
    JACE_PROXY_API void mouseClicked  (MouseEvent e);
    JACE_PROXY_API void mousePressed  (MouseEvent e);
    JACE_PROXY_API void mouseReleased (MouseEvent e);
    JACE_PROXY_API void mouseMoved    (MouseEvent e);
    JACE_PROXY_API void mouseEntered  (MouseEvent e);
    JACE_PROXY_API void mouseExited   (MouseEvent e);
    JACE_PROXY_API void mouseDragged  (MouseEvent e);
    JACE_PROXY_API void mouseWheel    (MouseEvent e);

    /**
     * @brief Returns the state of the mouse buttons
     * @return Returns the mouse button state.
     */
    JACE_PROXY_API JInt getClickState();

    /**
     * @brief Returns the currently focused Component.
     * @return the currently focused Component.
     */
    JACE_PROXY_API Component getTarget();

    /**
     * @brief Returns the last known X position of the Mouse.
     * @return the last known X position of the Mouse.
     */
    JACE_PROXY_API JInt getX();

    /**
     * @brief Returns the last known Y position of the Mouse.
     * @return the last known Y position of the Mouse.
     */
    JACE_PROXY_API JInt getY();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_MOUSE_H
