#ifndef API_BRIDGE_KEYLISTENER_H
#define API_BRIDGE_KEYLISTENER_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

#include "java/awt/event/keyevent.h"
using java::awt::event::KeyEvent;

namespace api {
namespace bridge {

/**
 * \brief Keyboard representative
 *
 * This class acts as the AWT KeyListener for the Runescape client.
 * It provides functionality to push AWT KeyEvents to the Runescape client.
 *
 * The client's Keyboard object is accessible through the following invocation:
 *      Keyboard kb = Client::getKeyboard();
 *
 * \see api::bridge::Client::getKeyboard()
 */
class KeyListener : public Object {
public:
    RS_OBJECT(KeyListener)

    /**
     * \brief Dispatches the given KeyEvent according to its Type
     * \param e the Event to dispatch
     */
    JACE_PROXY_API void dispatch(KeyEvent e);

    /**
     * \brief Dispatches the given \c KeyEvent as a \c Typed event.
     * \param the \c KeyEvent to send
     */
    JACE_PROXY_API void keyTyped(KeyEvent e);
    /**
     * \brief Dispatches the given \c KeyEvent as a \c Pressed event.
     * \param the \c KeyEvent to send
     */
    JACE_PROXY_API void keyPressed(KeyEvent e);
    /**
     * \brief Dispatches the given \c KeyEvent as a \c Released event.
     * \param the \c KeyEvent to send
     */
    JACE_PROXY_API void keyReleased(KeyEvent e);

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_KEYLISTENER_H
