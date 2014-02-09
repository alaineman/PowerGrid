#ifndef OBJECT_H
#define OBJECT_H

#include "jace/os_dep.h"
#include "jace/Namespace.h"
#include "jace/javacast.h"\

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JFieldProxy.h"
#include "jace/JMethod.h"
#include "jace/JField.h"
#include "jace/JClassImpl.h"

/**
 * Forward declarations for the classes that this class uses.
 */
namespace jace {
 namespace proxy {
  namespace types {
   class JBoolean;
   class JVoid;
   class JLong;
   class JInt;
  }
 }
}
namespace java {
namespace lang {

class String;
class Class;
class InterruptedException;

class Object: public virtual jace::proxy::JObject {
public:
    class Factory  {
    public:
        static Object create();
    };
public:
    explicit Object();
    Object(const Object&);

    java::lang::Class getClass();
    jace::proxy::types::JInt hashCode();
    jace::proxy::types::JBoolean equals(java::lang::Object p0);
    java::lang::String toString();
    void notify();
    void notifyAll();
    void wait(jace::proxy::types::JLong p0);
    void wait(jace::proxy::types::JLong p0, jace::proxy::types::JInt p1);
    void wait();

    virtual const jace::JClass* getJavaJniClass() const throw (::jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (::jace::JNIException);

    explicit Object(jvalue);
    explicit Object(jobject);

    friend std::ostream& operator<<(std::ostream& out, Object& object);
private:
    template <typename T> friend T (jace::java_cast)(const ::jace::proxy::JObject&);

    template <typename T> friend class ::jace::ElementProxy;
    template <typename T> friend class ::jace::JFieldProxy;
    template <typename T> friend class ::jace::JMethod;
};

}
}

namespace jace {

template <> class ElementProxy<java::lang::Object> : public java::lang::Object {
public:
    ElementProxy(jarray array, jvalue element, int index);
    ElementProxy(const jace::ElementProxy<java::lang::Object>& proxy);
private:
    jarray parent;
    int mIndex;
};

template <> class JFieldProxy<java::lang::Object> : public java::lang::Object {
public:
    JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
    JFieldProxy( jfieldID fieldID_, jvalue value, jclass parent_ );
    JFieldProxy( const JFieldProxy<java::lang::Object>& object );
    java::lang::Object& operator=( const java::lang::Object& type );
private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;
};

}

#endif // OBJECT_H
