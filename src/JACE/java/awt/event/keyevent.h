#ifndef JAVA_AWT_EVENT_KEYEVENT_H
#define JAVA_AWT_EVENT_KEYEVENT_H

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

class KeyEvent : public Object {
public:
    enum Type {
        Typed    = 400,
        Pressed  = 401,
        Released = 402
    };

    static KeyEvent createEvent(Component source, Type id, JLong when, JInt modifiers,
                                JInt keyCode, JChar keyChar);

    KeyEvent();
    KeyEvent(const KeyEvent&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit KeyEvent(jvalue value);
    explicit KeyEvent(jobject object);
    KeyEvent& operator = (const KeyEvent& obj);

    JACE_PROXY_API JInt getID();
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace event
} // namespace awt
} // namespace java

#endif // JAVA_AWT_EVENT_KEYEVENT_H
