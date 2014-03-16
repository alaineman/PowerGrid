#include "keyevent.h"
#include "java/awt/component.h"
#include "jace/JNIException.h"
using jace::JNIException;

namespace java {
namespace awt {
namespace event {

/*!
 * \class java::awt::event::KeyEvent
 * \brief Proxy class for \c java.awt.event.KeyEvent
 *
 * This class provides access to java AWT KeyEvent objects.
 */

KeyEvent KeyEvent::createEvent(Component source, Type id, JLong when, JInt modifiers,
                               JInt keyCode, JChar keyChar) {
    jclass KeyEventClass = KeyEvent::staticGetJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID constructor = env->GetMethodID(KeyEventClass, "<init>", "(Ljava/awt/Component;ILIIC)V");
    jobject mEvent = env->NewObject(KeyEventClass, constructor, source.getJavaJniObject(), (jint)id,
                                    when.getLong(), modifiers.getInt(), keyCode.getInt(), keyChar.getChar());
    if (env->ExceptionCheck()) {
        env->ExceptionClear();
        throw JNIException("Exception in KeyEvent constructor");
    }
    return KeyEvent(mEvent);
}

KeyEvent::KeyEvent(Type _type) : Object(), type(_type) {
}
KeyEvent::KeyEvent(const KeyEvent &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* KeyEvent::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.awt.event.KeyEvent");
    return &cls;
}

const jace::JClass* KeyEvent::getJavaJniClass() const throw (JNIException) {
    return KeyEvent::staticGetJavaJniClass();
}

KeyEvent::KeyEvent(jobject object) :
    Object(object) {}
KeyEvent::KeyEvent(jvalue value) :
    Object(value) {}

KeyEvent& KeyEvent::operator =(const KeyEvent &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}
} // namespace event
} // namespace awt
} // namespace java
