#include "map.h"
using jace::JNIException;

namespace java {
namespace util {

/*!
 * \class java::util::Map
 * \brief Proxy class for \c{java.util.Map}
 *
 * This class provides access to java Map objects.
 */

/*!
 * \brief Creates a new Map object representing a \c{null} value
 */
Map::Map() : Object() {}

Map::Map(const Map &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* Map::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.io.Map");
    return &cls;
}

const jace::JClass* Map::getJavaJniClass() const throw (JNIException) {
    return Map::staticGetJavaJniClass();
}

Map::Map(jobject object) :
    Object(object) {}
Map::Map(jvalue value) :
    Object(value) {}

Map& Map::operator =(const Map &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

} // namespace util
} // namespace java
