#ifndef JAVA_UTIL_MAP_H
#define JAVA_UTIL_MAP_H

#include "jace/os_dep.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JField.h"
#include "jace/JClass.h"

#include "java/lang/object.h"
using namespace java::lang;
using jace::JNIException;

namespace java {
namespace util {

class Map : public Object {
public:
    Map();
    Map(const Map&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (JNIException);

    explicit Map(jvalue value);
    explicit Map(jobject object);
    Map& operator = (const Map& obj);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);

};

} // namespace util
} // namespace java

#endif // JAVA_UTIL_MAP_H
