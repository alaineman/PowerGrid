#include "mouse.h"
#include "jniclass.h"

//java.awt.EventQueue
//postEvent() AWTEvent

//java.awt.event.MouseEvent

using namespace jni;

namespace injection {

Mouse* Mouse::mouse = NULL;

void Mouse::postEvent(jni::JNIObject* event){
    //JNIClass* eventQueue = JAVAENV->GetClass("java/awt/EventQueue");
    //JNIMethod* sendEvent = JAVAENV->GetStaticMethodID(eventQueue, "postEvent", "(Ljava/awt/AWTEvent;)V");
}

Point Mouse::getPosition(){
    qWarning("calling unimplemented method");
    int x = 0;
    int y = 0;
    return Point(x,y);
}

bool Mouse::isDown(MouseButton button){
    qWarning("calling unimplemented method");
    return false;
}

void Mouse::move(Point position){
    qWarning("calling unimplemented method");

}

void Mouse::click(MouseButton button){
    qWarning("calling unimplemented method");

}

void Mouse::drag(Point position, MouseButton button){
    mouseDown(button);
    move(position);
    mouseUp(button);
}

void Mouse::scroll(ScrollWheel direction){
    qWarning("calling unimplemented method");

}

void Mouse::mouseDown(MouseButton button){
    qWarning("calling unimplemented method");

}

void Mouse::mouseUp(MouseButton button){
    qWarning("calling unimplemented method");

}

}
