#ifndef METHODHELPER_H
#define METHODHELPER_H

#include "RSClassMapper.h"
#include "RSClass.h"
#include "jace/JArray.h"
#include "jace/JField.h"
#include <QList>

#define IMPL_RSCLASS_GET(name) \
JACE_PROXY_API const RSClass* name::staticGetJavaJniClass() throw(jace::JNIException) {\
    static RSClass* cls = RSClassMapper::DefaultInstance()->getRSClass(#name);\
    return cls;\
}\
JACE_PROXY_API const RSClass* name::getJavaJniClass() const throw(jace::JNIException) {\
    return name::staticGetJavaJniClass();\
}

#define IMPL_STATIC_OBJECT_METHOD(className, name, returnType) \
JACE_PROXY_API returnType className::name() {\
    const RSClass* rsc = staticGetJavaJniClass();\
    returnType result = jace::JField<returnType>(rsc->getFieldName(#name)).getReadOnly(rsc);\
    return result;\
}
#define IMPL_OBJECT_METHOD(className, name, returnType) \
JACE_PROXY_API returnType className::name() {\
    const RSClass* rsc = getJavaJniClass();\
    returnType result = jace::JField<returnType>(rsc->getFieldName(#name)).getReadOnly(*this);\
    return result;\
}

#define IMPL_STATIC_PRIMITIVE_METHOD(className, name, returnType) \
JACE_PROXY_API returnType className::name() {\
    const RSClass* rsc = staticGetJavaJniClass();\
    returnType result = jace::JField<returnType>(rsc->getFieldName(#name)).getReadOnly(rsc);\
    return result * rsc->getFieldModifier(#name);\
}

#define IMPL_PRIMITIVE_METHOD(className, name, returnType) \
JACE_PROXY_API returnType className::name() {\
    const RSClass* rsc = getJavaJniClass();\
    returnType result = jace::JField<returnType>(rsc->getFieldName(#name)).getReadOnly(*this);\
    return result * rsc->getFieldModifier(#name);\
}

#define IMPL_STATIC_ARRAY_METHOD(className, name, componentType) \
JACE_PROXY_API QList<componentType> className::name() {\
    const RSClass* rsc = staticGetJavaJniClass();\
    jace::JArray<componentType> result = jace::JField<jace::JArray<componentType>>(rsc->getFieldName(#name)).getReadOnly(rsc);\
    return result.toQList();\
}
#define IMPL_ARRAY_METHOD(className, name, componentType) \
JACE_PROXY_API QList<componentType> className::name() {\
    const RSClass* rsc = getJavaJniClass();\
    jace::JArray<componentType> result = jace::JField<jace::JArray<componentType>>(rsc->getFieldName(#name)).getReadOnly(*this);\
    return result.toQList();\
}

#endif // METHODHELPER_H
