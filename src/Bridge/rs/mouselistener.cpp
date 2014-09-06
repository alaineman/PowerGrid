#include "mouselistener.h"

#include "java/awt/event/mouseevent.h"
#include "jace/MappingUnavailableException.h"
#include "java/awt/component.h"

using java::awt::Component;
using java::awt::event::MouseEvent;
using jace::MappingUnavailableException;


namespace RS {

IMPL_JACE_CONSTRUCTORS_SUPERTYPE(MouseListener, AbstractMouseListener)
IMPL_RSCLASS_GET(MouseListener)

IMPL_PRIMITIVE_METHOD(MouseListener, getClickState, JInt)
IMPL_OBJECT_METHOD(MouseListener, getTarget, Component)
IMPL_PRIMITIVE_METHOD(MouseListener, getX, JInt)
IMPL_PRIMITIVE_METHOD(MouseListener, getY, JInt)

// Remember: these are methods, not fields
void MouseListener::mouseClicked(MouseEvent e) {
    jclass mouseClass = MouseListener::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseClicked", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseClicked(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void MouseListener::mousePressed(MouseEvent e) {
    jclass mouseClass = MouseListener::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mousePressed", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mousePressed(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void MouseListener::mouseReleased(MouseEvent e) {
    jclass mouseClass = MouseListener::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseReleased", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseReleased(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void MouseListener::mouseMoved(MouseEvent e) {
    jclass mouseClass = MouseListener::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseMoved", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseMoved(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void MouseListener::mouseEntered(MouseEvent e) {
    jclass mouseClass = MouseListener::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseEntered", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseEntered(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void MouseListener::mouseExited(MouseEvent e) {
    jclass mouseClass = MouseListener::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseExited", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseExited(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void MouseListener::mouseDragged(MouseEvent e) {
    jclass mouseClass = MouseListener::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseDragged", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseDragged(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}

void MouseListener::mouseWheel(MouseEvent e) {
    jclass mouseClass = MouseListener::getJavaJniClass()->getClass();
    JNIEnv* env = jace::helper::attach();
    jmethodID mID = env->GetMethodID(mouseClass, "mouseWheel", "(Ljava/awt/event/MouseEvent;)V");
    if (mID == NULL) throw MappingUnavailableException("Mouse.mouseWheel(MouseEvent)");
    env->CallVoidMethod(getJavaJniObject(), mID, e.getJavaJniObject());
}


} // namespace bridge
