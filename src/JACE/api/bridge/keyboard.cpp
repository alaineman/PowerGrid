#include "keyboard.h"
using java::awt::event::KeyEvent;

#include "jace/MappingUnavailableException.h"
using jace::MappingUnavailableException;

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(Keyboard)
IMPL_RSCLASS_GET(Keyboard)

void Keyboard::dispatch(KeyEvent e) {
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
        // Should not be possible, but still...
        throw std::runtime_error("Invalid KeyEvent ID");
    }
}

void Keyboard::keyPressed(KeyEvent e) {
    jclass keyClass = Keyboard::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(keyClass, "keyPressed", "(Ljava/awt/event/KeyEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Keyboard.keyPressed(KeyEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void Keyboard::keyReleased(KeyEvent e) {
    jclass keyClass = Keyboard::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(keyClass, "keyReleased", "(Ljava/awt/event/KeyEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Keyboard.keyReleased(KeyEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void Keyboard::keyTyped(KeyEvent e) {
    jclass keyClass = Keyboard::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(keyClass, "keyTyped", "(Ljava/awt/event/KeyEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Keyboard.keyTyped(KeyEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

} // namespace bridge
} // namespace api
