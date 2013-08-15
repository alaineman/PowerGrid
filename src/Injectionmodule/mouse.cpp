/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
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
