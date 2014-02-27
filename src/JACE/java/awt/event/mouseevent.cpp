#include "mouseevent.h"
#include "java/awt/component.h"
using jace::JNIException;

namespace java {
namespace awt {
namespace event {

/*!
 * \class java::awt::event::MouseEvent
 * \brief Proxy class for \c java.awt.event.MouseEvent
 *
 * This class provides access to java AWT MouseEvent objects.
 */

MouseEvent MouseEvent::createEvent(Component source, Type id, JLong when, JInt modifiers, JInt x, JInt y,
                        JInt clickCount, JBoolean popupTrigger, Button button) {
    jclass mouseEventClass = MouseEvent::staticGetJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID constructor = env->GetMethodID(mouseEventClass, "<init>", "(Ljava/awt/Component;ILIIIIZI)V");
    jobject mEvent = env->NewObject(mouseEventClass, constructor, source.getJavaJniObject(), (jint)id,
                                    when.getLong(), modifiers.getInt(), x.getInt(), y.getInt(), clickCount.getInt(),
                                    popupTrigger.getBoolean(), (jint)button);
    if (env->ExceptionCheck()) {
        env->ExceptionClear();
        throw JNIException("Exception in MouseEvent constructor");
    }
    return MouseEvent(mEvent);
}

MouseEvent::MouseEvent() : Object() {
}
MouseEvent::MouseEvent(const MouseEvent &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* MouseEvent::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.awt.event.MouseEvent");
    return &cls;
}

const jace::JClass* MouseEvent::getJavaJniClass() const throw (JNIException) {
    return MouseEvent::staticGetJavaJniClass();
}

MouseEvent::MouseEvent(jobject object) :
    Object(object) {}
MouseEvent::MouseEvent(jvalue value) :
    Object(value) {}

MouseEvent& MouseEvent::operator =(const MouseEvent &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}
} // namespace event
} // namespace awt
} // namespace java
