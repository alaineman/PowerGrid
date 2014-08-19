#ifndef API_BRIDGE_KEYLISTENER_H
#define API_BRIDGE_KEYLISTENER_H

#include "MethodHelper.h"

#include "java/lang/object.h"
using namespace java::lang;

#include "java/awt/event/keyevent.h"
using java::awt::event::KeyEvent;
using java::awt::Component;

#include "rs/deque.h"


namespace RS {

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
     * \brief Returns the keys that are currently pressed.
     * \return the keys that are currently pressed
     */
    JACE_PROXY_API QList<JBoolean> getKeysPressed();

    JACE_PROXY_API Deque getNext();

    JACE_PROXY_API Deque getRecorded();

    /**
     * \brief Returns the currently focused target.
     * \return the currently focused target
     */
    JACE_PROXY_API Component getTarget();


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

#endif // API_BRIDGE_KEYLISTENER_H
