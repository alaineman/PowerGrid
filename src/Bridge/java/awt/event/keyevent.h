#ifndef JAVA_AWT_EVENT_KEYEVENT_H
#define JAVA_AWT_EVENT_KEYEVENT_H

#include "jace/os_dep.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JField.h"
#include "jace/JClass.h"

#include "java/lang/object.h"
using namespace java::lang;

namespace java {
namespace awt {

class Component;

namespace event {

/**
 * @brief Proxy class for @c java.awt.event.KeyEvent
 *
 * This class represents AWT KeyEvent objects. They can be used for
 * generating keystrokes to send to the client.
 */
class KeyEvent : public Object {
public:
    static const jchar CHAR_UNDEFINED = 65535;
    /**
     * @brief The AWT Event ids for KeyEvents
     *
     * The values of the enum constants are set to match the Event ids in AWT.
     */
    enum Type {
        Typed    = 400, ///< Indicates a character has been typed (alphanumeric key pressed and then released).
        Pressed  = 401, ///< Indicates a key has been pressed.
        Released = 402  ///< Indicates a key has been released.
    };

    /**
     * @brief Creates a KeyEvent object.
     *
     * A few pointers for providing semantically correct parameters:
     * - For the @c Pressed and @c Released types, provide @c CHAR_UNDEFINED as keyChar.
     * - For the @c Typed event, provide @c -1 for keyCode.
     * - For the source, provide the Canvas Component contained in the RS Applet.
     * - For the @par when parameter, provide the current system time
     * - For the modifiers, provide a mask as described in the JavaDoc for the KeyEvent constructor.
     *
     * @param source the source Component where the event originates
     * @param id the AWT Event id
     * @param when the system time (in ms) when this event happened
     * @param modifiers a mask describing the modifiers active when this event happened
     * @param keyCode the key code belonging to the key (-1 in case of a @c Typed event)
     * @param keyChar the character that was typed (@c CHAR_UNDEFINED when @par id is not Typed)
     * @return the created KeyEvent object
     */
    static KeyEvent createEvent(Component source, Type id, JLong when, JInt modifiers,
                                JInt keyCode, JChar keyChar);

    KeyEvent(Type _type);
    KeyEvent(const KeyEvent&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit KeyEvent(jvalue value);
    explicit KeyEvent(jobject object);
    KeyEvent& operator = (const KeyEvent& obj);

    Type getType() const { return type; }

private:
    Type type;

    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace event
} // namespace awt
} // namespace java

#endif // JAVA_AWT_EVENT_KEYEVENT_H
