#ifndef NET_PGRID_LOADER_PGLOADER_H
#define NET_PGRID_LOADER_PGLOADER_H

#include "java/lang/object.h"
using namespace java::lang;

#include "java/awt/component.h"
using java::awt::Component;

namespace net {
namespace pgrid {
namespace loader {

class PGLoader : public Object {
public:
    static Component getApplet();

    PGLoader();
    PGLoader(const PGLoader& obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit PGLoader(jvalue value);
    explicit PGLoader(jobject object);
    PGLoader& operator = (const PGLoader& obj);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace loader
} // namespace pgrid
} // namespace net

#endif // NET_PGRID_LOADER_PGLOADER_H
