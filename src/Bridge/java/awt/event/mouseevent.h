/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
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
#ifndef JAVA_AWT_EVENT_MOUSEEVENT_H
#define JAVA_AWT_EVENT_MOUSEEVENT_H

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
 * @brief Proxy class for @c java.awt.event.MouseEvent
 *
 * This class represents AWT MouseEvent objects. They can be used for
 * generating mouse movement and clicks to send to the client.
 */
class MouseEvent : public Object {
public:
    /**
     * @brief The Mouse button constants for MouseEvents
     *
     * The values of the enum match the constants used by MouseEvent
     */
    enum Button {
        NoButton = 0, ///< Indicates no button was pressed
        Left     = 1, ///< Indicates the left mouse button
        Right    = 2, ///< Indicates the right mouse button
        Middle   = 3  ///< Indicates the middle mouse button
    };
    /**
     * @brief The AWT Event ids for MouseEvents
     *
     * The values of the enum constants are set to match the Event ids in AWT.
     * The documentation of the individual enum values gives more info on when the event
     * fires and/or if buttons are involved.
     */
    enum Type {
        Clicked  = 500, ///< Indicates a button on the mouse was clicked (pressed and then released)
        Pressed  = 501, ///< Indicates a button on the mouse was pressed
        Released = 502, ///< Indicates a button on the mouse was released
        Moved    = 503, ///< Indicates the mouse was moved (use NoButton as Button value)
        Entered  = 504, ///< Indicates the mouse entered the window (use NoButton as Button value)
        Exited   = 505, ///< Indicates the mouse exited the window (use NoButton as Button value)
        Dragged  = 506, ///< Indicates the mouse was dragged (pressed and then moved)
        Wheel    = 507  ///< Indicates the mouse wheel was scrolled (use NoButton as Button value)
    };

    static MouseEvent createEvent(Component source, Type id, JLong when, JInt modifiers, JInt x, JInt y,
                                  JInt clickCount, JBoolean popupTrigger, Button button);

    MouseEvent();
    MouseEvent(const MouseEvent&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit MouseEvent(jvalue value);
    explicit MouseEvent(jobject object);
    MouseEvent& operator = (const MouseEvent& obj);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace event
} // namespace awt
} // namespace java

#endif // JAVA_AWT_EVENT_MOUSEEVENT_H
