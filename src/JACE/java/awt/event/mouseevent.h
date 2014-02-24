#ifndef JAVA_AWT_EVENT_MOUSEEVENT_H
#define JAVA_AWT_EVENT_MOUSEEVENT_H

#include "jace/os_dep.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JMethod.h"
#include "jace/JField.h"
#include "jace/JClass.h"

#include "java/lang/object.h"
using namespace java::lang;

namespace java {
namespace awt {

class Component;

namespace event {

class MouseEvent : public Object {
public:
    enum Button {
        NoButton = 0,
        Left     = 1,
        Right    = 2,
        Middle   = 3
    };
    enum Type {
        Clicked  = 500,
        Pressed  = 501,
        Released = 502,
        Moved    = 503,
        Entered  = 504,
        Exited   = 505,
        Dragged  = 506,
        Wheel    = 507
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

    JACE_PROXY_API JInt getID();
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace event
} // namespace awt
} // namespace java

#endif // JAVA_AWT_EVENT_MOUSEEVENT_H
