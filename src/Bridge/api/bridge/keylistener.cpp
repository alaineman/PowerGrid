#include "keylistener.h"
using java::awt::event::KeyEvent;

#include "jace/MappingUnavailableException.h"
using jace::MappingUnavailableException;

#include "java/awt/component.h"
using java::awt::Component;

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(KeyListener)
IMPL_RSCLASS_GET(KeyListener)

IMPL_ARRAY_METHOD(KeyListener, getKeysPressed, JBoolean)
IMPL_OBJECT_METHOD(KeyListener, getNext, Deque)
IMPL_OBJECT_METHOD(KeyListener, getRecorded, Deque)
IMPL_OBJECT_METHOD(KeyListener, getTarget, Component)

void KeyListener::dispatch(KeyEvent e) {
    switch (e.getType()) {
    case KeyEvent::Pressed:
        keyPressed(e);
        break;
    case KeyEvent::Released:
        keyReleased(e);
        break;
    case KeyEvent::Typed:
        keyTyped(e);
        break;
    default:
        Q_UNREACHABLE();
    }
}

void KeyListener::keyPressed(KeyEvent e) {
    jclass keyClass = KeyListener::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(keyClass, "keyPressed", "(Ljava/awt/event/KeyEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("KeyListener.keyPressed(KeyEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void KeyListener::keyReleased(KeyEvent e) {
    jclass keyClass = KeyListener::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(keyClass, "keyReleased", "(Ljava/awt/event/KeyEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("KeyListener.keyReleased(KeyEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void KeyListener::keyTyped(KeyEvent e) {
    jclass keyClass = KeyListener::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(keyClass, "keyTyped", "(Ljava/awt/event/KeyEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("KeyListener.keyTyped(KeyEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

} // namespace bridge
} // namespace api
