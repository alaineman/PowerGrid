#ifndef API_BRIDGE_MOUSE_H
#define API_BRIDGE_MOUSE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace java {
 namespace awt {
  namespace event {
   class MouseEvent;
  }
 }
}

using java::awt::event::MouseEvent;

namespace api {
namespace bridge {

class Mouse : public Object {
public:
    RS_OBJECT(Mouse)

    // This class is supposed to serve as both MouseListener and
    // MouseMotionListener in the Client. We just implement the
    // proxy methods here instead of in separate classes
    // because they will only ever be used for this class anyway.

    JACE_PROXY_API void mouseClicked  (MouseEvent e);
    JACE_PROXY_API void mousePressed  (MouseEvent e);
    JACE_PROXY_API void mouseReleased (MouseEvent e);
    JACE_PROXY_API void mouseMoved    (MouseEvent e);
    JACE_PROXY_API void mouseEntered  (MouseEvent e);
    JACE_PROXY_API void mouseExited   (MouseEvent e);
    JACE_PROXY_API void mouseDragged  (MouseEvent e);
    JACE_PROXY_API void mouseWheel    (MouseEvent e);

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_MOUSE_H
