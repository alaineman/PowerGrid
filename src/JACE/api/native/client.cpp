#include "client.h"
#include "RSClassMapper.h"
#include "jace/JField.h"
#include "MappingUnavailableException.h"

namespace api {
namespace native {

JACE_PROXY_API Client::Client(const Client& obj) :
    JObject(NoOp()), Object(obj) {
}

JACE_PROXY_API Client::Client(jobject obj) {
    setJavaJniObject(obj);
}

JACE_PROXY_API Client::Client(jvalue val) {
    setJavaJniValue(val);
}

JACE_PROXY_API const RSClass* Client::staticGetJavaJniClass() throw(jace::JNIException) {
    static RSClass* cls = RSClassMapper::DefaultInstance()->getRSClass("Client");
    return cls;
}

JACE_PROXY_API const RSClass* Client::getJavaJniClass() const throw(jace::JNIException) {
    return Client::staticGetJavaJniClass();
}

JACE_PROXY_API Client& Client::operator =(Client& other) {
    setJavaJniObject(other.getJavaJniObject());
    return *this;
}

// Example 1: static object-type field.
// static fields map to static member functions in a proxy class.
// We collect the value for the field (using the class reference)
// and return it directly, since RS does not mess with object references.

// Furthermore, we get the contents of the field using JField::getReadOnly,
// since this returns the field contents directly instead of a JFieldProxy.
// By doing this, we effectively prevent external code from writing to the
// Runescape client directly.
JACE_PROXY_API Client Client::getClient() {
    // FIXME: This seems to cause an ACCESS_VIOLATION on Win7. Not sure yet why, though...
    // It seems that the RSClass* is non-null, yet it causes an
    // ACCESS_VIOLATION when referenced...
    // Is it accidentally deleted at some point in the process?
    const RSClass* rsc = Client::staticGetJavaJniClass();
    qDebug() << "Requesting Client";
    std::string fName = rsc->getFieldName("getClient");
    qDebug() << "RSClass properties received";
    Client c (NULL); // = jace::JField<Client>(fName).getReadOnly(rsc);
    return c;
}

// Example 2: virtual primitive-type method..
// virtual fields are practically collected the same way, only here the object
// reference is used for the actual collection.
// Additionally, since it's a primitive type, we may need to apply a modifier
// value to the result as well.

// A possible improvement on this technique involves moving the field getter
// and the modifier application to RSClass, since this makes the proxy classes even
// smaller and easier to understand. The content of any getter method would then
// just be "return getJavaJniClass().getField<Type>(name);".
JACE_PROXY_API JInt Client::getFPS() {
    const RSClass* rsc = getJavaJniClass();
    JInt result = jace::JField<JInt>(rsc->getFieldName("getFPS")).getReadOnly(*this);
    return result * rsc->getFieldModifier("getFPS");
}


} // end namespace native
} // end namespace api


