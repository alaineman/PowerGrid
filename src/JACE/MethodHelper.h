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

/*
 * This file defines generalized version of RS proxy implementations.
 * It can be used to quickly implement RS proxies, and to be able to
 * quickly repair issues within these methods should such issues arise.
 */

#ifndef METHODHELPER_H
#define METHODHELPER_H

#include "RSClassMapper.h"
#include "RSClass.h"
#include "jace/JNIException.h"
#include "jace/JArray.h"
#include "jace/JField.h"
#include <QList>

/*!
 * \brief Marks this class as an RS proxy object.
 * This macro declares all constructors and framework methods.
 *
 * This macro should appear at the beginning of a RS proxy class
 * in a public section, and should appear only once in each class.
 */
#define RS_OBJECT(name)\
    JACE_PROXY_API name();\
    JACE_PROXY_API name(const name& obj);\
    JACE_PROXY_API virtual const RSClass* getJavaJniClass() const throw(jace::JNIException);\
    JACE_PROXY_API static const RSClass* staticGetJavaJniClass() throw(jace::JNIException);\
    JACE_PROXY_API name (jvalue);\
    JACE_PROXY_API name (jobject);\
    JACE_PROXY_API name& operator =(const name& other);

/*!
 * \brief Creates the links to any friend classes the class needs.
 * This is required for smooth integration into the JACE framework.
 * This should appear once for each class in the class' private section.
 */
#define DECLARE_FRIENDS \
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);

/*!
 * \brief Implements the JACE constructors.
 * If the class has a superclass other than \c java.lang.Object,
 * use \c IMPL_JACE_CONSTRUCTORS_SUPERTYPE instead.
 */
#define IMPL_JACE_CONSTRUCTORS(name) \
    name::name() : JObject(NoOp()) {}\
    name::name(const name& obj) : JObject(NoOp()), java::lang::Object(obj) {}\
    name::name(jobject obj) {\
        setJavaJniObject(obj);\
    }\
    name::name(jvalue val) {\
        setJavaJniValue(val);\
    }\
    name& name::operator =(const name& other) {\
        setJavaJniValue(other.getJavaJniValue());\
        return *this;\
    }

/*!
 * \brief Implements the JACE constructors.
 * If the class is a direct subclass of \c java.lang.Object,
 * please use \c IMPL_JACE_CONSTRUCTORS instead.
 */
#define IMPL_JACE_CONSTRUCTORS_SUPERTYPE(name, superType) \
name::name() {}\
name::name(const name& obj) : JObject(NoOp()), superType(obj) {}\
name::name(jobject obj) {\
    setJavaJniObject(obj);\
}\
name::name(jvalue val) {\
    setJavaJniValue(val);\
}\
name& name::operator =(const name& other) {\
    setJavaJniValue(other.getJavaJniValue());\
    return *this;\
}

/*!
 * \brief Implements the getter methods for the \c RSClass*
 * (Which are \c getJavaJniClass() and \c staticGetJavaJniClass()).
 */
#define IMPL_RSCLASS_GET(name) \
JACE_PROXY_API const RSClass* name::staticGetJavaJniClass() throw(jace::JNIException) {\
    static RSClass* cls = RSClassMapper::DefaultInstance()->getRSClass(#name);\
    return cls;\
}\
JACE_PROXY_API const RSClass* name::getJavaJniClass() const throw(jace::JNIException) {\
    return name::staticGetJavaJniClass();\
}

/*!
 * \brief Implements a static proxy method.
 * The method does NOT apply any modifier to the return value.
 */
#define IMPL_STATIC_OBJECT_METHOD(className, name, returnType) \
JACE_PROXY_API returnType className::name() {\
    const RSClass* rsc = staticGetJavaJniClass();\
    returnType result = jace::JField<returnType>(rsc->getFieldName(#name)).getReadOnly(rsc);\
    return result;\
}
/*!
 * \brief Implements a proxy method.
 * The method does NOT apply any modifier to the return value.
 */
#define IMPL_OBJECT_METHOD(className, name, returnType) \
JACE_PROXY_API returnType className::name() {\
    const RSClass* rsc = getJavaJniClass();\
    returnType result = jace::JField<returnType>(rsc->getFieldName(#name)).getReadOnly(*this);\
    return result;\
}
/*!
 * \brief Implements a static proxy method.
 * The method applies a modifier (if any) to the return value.
 */
#define IMPL_STATIC_PRIMITIVE_METHOD(className, name, returnType) \
JACE_PROXY_API returnType className::name() {\
    const RSClass* rsc = staticGetJavaJniClass();\
    returnType result = jace::JField<returnType>(rsc->getFieldName(#name)).getReadOnly(rsc);\
    return result * rsc->getFieldModifier(#name);\
}
/*!
 * \brief Implements a proxy method.
 * The method applies a modifier (if any) to the return value.
 */
#define IMPL_PRIMITIVE_METHOD(className, name, returnType) \
JACE_PROXY_API returnType className::name() {\
    const RSClass* rsc = getJavaJniClass();\
    returnType result = jace::JField<returnType>(rsc->getFieldName(#name)).getReadOnly(*this);\
    return result * rsc->getFieldModifier(#name);\
}

/*!
 * \brief Implements a static proxy method. Can only be used for arrays.
 * The return type is a QList with the data in the array.
 * The method does NOT apply any modifier to the return value.
 */
#define IMPL_STATIC_ARRAY_METHOD(className, name, componentType) \
JACE_PROXY_API QList<componentType> className::name() {\
    const RSClass* rsc = staticGetJavaJniClass();\
    jace::JArray<componentType> result = jace::JField<jace::JArray<componentType>>(rsc->getFieldName(#name)).getReadOnly(rsc);\
    return result.toQList();\
}
/*!
 * \brief Implements a proxy method. Can only be used for arrays.
 * The return type is a QList with the data in the array.
 * The method does NOT apply any modifier to the return value.
 * For multidimensional arrays, use \c IMPL_ARRAY2_METHOD or
 * \c IMPL_ARRAY3_METHOD instead.
 */
#define IMPL_ARRAY_METHOD(className, name, componentType) \
JACE_PROXY_API QList<componentType> className::name() {\
    const RSClass* rsc = getJavaJniClass();\
    jace::JArray<componentType> result = jace::JField<jace::JArray<componentType>>(rsc->getFieldName(#name)).getReadOnly(*this);\
    return result.toQList();\
}

/*!
 * \brief Implements a proxy method that returns a 2-dimensional array.
 * The return type is a QList of QLists with the data in the array.
 * The method does NOT apply any modifier to the return values.
 */
#define IMPL_ARRAY2_METHOD(className, name, componentType) \
    JACE_PROXY_API QList<QList<componentType>> className::name() {\
        const RSClass* rsc = getJavaJniClass();\
        jace::JArray<jace::JArray<componentType>> jresult = jace::JField<jace::JArray<jace::JArray<componentType>>>(rsc->getFieldName(#name)).getReadOnly(*this);\
        QList<QList<componentType>> result;\
        foreach (const JArray<componentType> elem, jresult.toQList()) {\
            result << elem.toQList();\
        }\
        return result;\
    }
/*!
 * \brief Implements a static proxy method that returns a 2-dimensional array.
 * The return type is a QList of QLists with the data in the array.
 * The method does NOT apply any modifier to the return values.
 */
#define IMPL_STATIC_ARRAY2_METHOD(className, name, componentType) \
    JACE_PROXY_API QList<QList<componentType>> className::name() {\
        const RSClass* rsc = staticGetJavaJniClass();\
        jace::JArray<jace::JArray<componentType>> jresult = jace::JField<jace::JArray<jace::JArray<componentType>>>(rsc->getFieldName(#name)).getReadOnly(rsc);\
        QList<QList<componentType>> result;\
        /* TODO: Maybe rewrite this to use Iterators? Because this copies the array twice. */\
        foreach (const jace::JArray<componentType> elem, jresult.toQList()) {\
            result << elem.toQList();\
        }\
        return result;\
    }

/*!
 * \brief Implements a proxy method that returns a 3-dimensional array.
 * The return type is a QList of QLists of QLists with the data in the array.
 * The method does NOT apply any modifier to the return values.
 */
#define IMPL_ARRAY3_METHOD(className, name, componentType) \
    JACE_PROXY_API QList<QList<QList<componentType>>> className::name() {\
        const RSClass* rsc = getJavaJniClass();\
        jace::JArray<jace::Jarray<jace::JArray<componentType>>> jresult = \
                jace::JField<jace::JArray<jace::Jarray<jace::JArray<componentType>>>>(rsc->getFieldName(#name)).getReadOnly(*this);\
        QList<QList<QList<componentType>>> result;\
        /* TODO: Maybe rewrite this to use Iterators? Because this copies the array twice. */\
        foreach (jace::JArray<jace::JArray<componentType>> arr2D, jresult.toQList()) {\
            QList<QList<componentType>> result2D;\
            foreach (jace::JArray<componentType>> arr1D, arr2D.toQList()) {\
                result2D << arr1D.toQList();\
            }\
            result << result2D;\
        }\
        return result;\
    }


#endif // METHODHELPER_H
