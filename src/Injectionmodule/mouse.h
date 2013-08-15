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
#ifndef MOUSE_H
#define MOUSE_H
#include <QObject>
#include "point.h"
#include "jniobject.h"

using namespace world;

namespace injection{

enum MouseButton{
    LeftButton, RightButton, MiddleButton
};

enum ScrollWheel{
    Up, Down
};

class Mouse : public QObject {
private:
    Q_DISABLE_COPY(Mouse)
    void postEvent(jni::JNIObject* event);
    static Mouse* mouse;
    Mouse(){ setObjectName("Mouse");}
public:    
    static Mouse* instance() { return (mouse == NULL ? mouse = new Mouse() : mouse); }
    Point getPosition();
    bool isDown(MouseButton button = LeftButton);
    void move(Point position);
    void click(MouseButton button = LeftButton);
    void drag(Point position, MouseButton button = LeftButton);
    void scroll(ScrollWheel direction = Down);
    void mouseDown(MouseButton button = LeftButton);
    void mouseUp(MouseButton button = LeftButton);
};

}
#endif // MOUSE_H
