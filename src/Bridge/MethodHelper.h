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

/**
 * \file MethodHelper.h
 * \brief helper for RS proxies.
 *
 * This file defines generalized version of RS proxy implementations.
 * It can be used to quickly implement RS proxies, and to be able to
 * quickly repair issues within these methods should such issues arise.
 */

#ifndef METHODHELPER_H
#define METHODHELPER_H

#include "jace/os_dep.h"
#include "jace/RSClassMapper.h"
#include "jace/RSClass.h"
#include "jace/JNIException.h"
#include "jace/JArray.h"
#include "jace/JField.h"
#include "jace/MappingUnavailableException.h"
#include <QList>
#include <QString>

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
    JACE_PROXY_API virtual const jace::RSClass* getJavaJniClass() const throw(jace::JNIException);\
    JACE_PROXY_API static const jace::RSClass* staticGetJavaJniClass() throw(jace::JNIException);\
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
    name::name(jobject obj) : JObject(NoOp()) {\
        setJavaJniObject(obj);\
    }\
    name::name(jvalue val) : JObject(NoOp()) {\
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
name::name() : JObject(NoOp()) {}\
name::name(const name& obj) : JObject(NoOp()), superType(obj) {}\
name::name(jobject obj) : JObject(NoOp()) {\
    setJavaJniObject(obj);\
}\
name::name(jvalue val) : JObject(NoOp()) {\
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
JACE_PROXY_API const jace::RSClass* name::staticGetJavaJniClass() throw(jace::JNIException) {\
    static jace::RSClass* cls = jace::RSClassMapper::DefaultInstance()->getRSClass(#name);\
    return cls;\
}\
JACE_PROXY_API const jace::RSClass* name::getJavaJniClass() const throw(jace::JNIException) {\
    return name::staticGetJavaJniClass();\
}

/*!
 * \brief Implements a proxy method.
 * The method does NOT apply any modifier to the return value.
 */
#define IMPL_OBJECT_METHOD(className, name, returnType) \
JACE_PROXY_API returnType className::name() {\
    const jace::RSClass* rsc = getJavaJniClass();\
    returnType result = jace::JField<returnType>(rsc->getFieldName(#name)).get(*this);\
    return result;\
}

/*!
 * \brief Implements a proxy method.
 * The method applies a modifier (if any) to the return value.
 */
#define IMPL_PRIMITIVE_METHOD(className, name, returnType) \
JACE_PROXY_API returnType className::name() {\
    const jace::RSClass* rsc = getJavaJniClass();\
    returnType result = jace::JField<returnType>(rsc->getFieldName(#name)).get(*this);\
    return static_cast<returnType> (result * rsc->getFieldModifier(#name));\
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
    const jace::RSClass* rsc = getJavaJniClass();\
    jace::JArray<componentType> result = jace::JField<jace::JArray<componentType>>(rsc->getFieldName(#name)).get(*this);\
    return result.toQList();\
}

/*!
 * \brief Implements a proxy method that returns a 2-dimensional array.
 * The return type is a QList of QLists with the data in the array.
 * The method does NOT apply any modifier to the return values.
 */
#define IMPL_ARRAY2_METHOD(className, name, componentType) \
    JACE_PROXY_API QList<QList<componentType>> className::name() {\
        const jace::RSClass* rsc = getJavaJniClass();\
        jace::JArray<jace::JArray<componentType>> jresult = jace::JField<jace::JArray<jace::JArray<componentType>>>(rsc->getFieldName(#name)).get(*this);\
        QList<QList<componentType>> result;\
        for (int i=0;i<jresult.length(); i++) {\
            result << jresult[i].toQList();\
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
        const jace::RSClass* rsc = getJavaJniClass();\
        jace::JArray<jace::JArray<jace::JArray<componentType>>> jresult = \
                jace::JField<jace::JArray<jace::JArray<jace::JArray<componentType>>>>(rsc->getFieldName(#name)).get(*this);\
        QList<QList<QList<componentType>>> result;\
        for(int i=0; i<jresult.length(); i++) { \
            jace::JArray<jace::JArray<componentType>> arr2D = jresult[i];\
            QList<QList<componentType>> result2D;\
            for(int j=0;j<arr2D.length(); j++) {\
                result2D << arr2D[i].toQList();\
            }\
            result << result2D;\
        }\
        return result;\
    }

#define IMPL_STATIC_ARRAY_FIELD(className, name, componentType) \
    JACE_PROXY_API QList<componentType> className::name() {\
        JNIEnv* env = jace::helper::attach(); \
        jace::RSClassMapper* rscm = RSClassMapper::DefaultInstance(); \
        QString clsName = rscm->getStaticFieldClass(#name); \
        QString retName = rscm->getRealName(#componentType); \
        std::string fldName = rscm->getStaticFieldName(#name); \
        jclass cls = rscm->getClass(clsName); \
        if (cls == NULL) throw jace::MappingUnavailableException(QStringLiteral("Class of Static Field ").append(#name)); \
        jfieldID field = env->GetStaticFieldID(cls, fldName.c_str(), retName.toUtf8().constData()); \
        if (field == 0) throw jace::MappingUnavailableException(QStringLiteral("Static Field ").append(#name)); \
        jarray arr = static_cast<jarray>(env->GetStaticObjectField(cls, field)); \
        return jace::JArray<componentType>(arr).toQList(); \
    }

#define IMPL_STATIC_OBJECT_FIELD(className, name, returnType) \
    JACE_PROXY_API returnType className::name() { \
        JNIEnv* env = jace::helper::attach(); \
        jace::RSClassMapper* rscm = RSClassMapper::DefaultInstance(); \
        QString clsName = rscm->getStaticFieldClass(#name); \
        QString retName = "L" + rscm->getRealName(#returnType) + ";"; \
        std::string fldName = rscm->getStaticFieldName(#name).toStdString(); \
        jclass cls = rscm->getClass(clsName); \
        if (cls == NULL) throw jace::MappingUnavailableException(QStringLiteral("Class of Static Field ").append(#name)); \
        jfieldID field = env->GetStaticFieldID(cls, fldName.c_str(), retName.toUtf8().constData()); \
        if (field == 0) throw jace::MappingUnavailableException(QStringLiteral("Static Field ").append(#name)); \
        jobject obj = env->GetStaticObjectField(cls, field); \
        returnType result (obj); \
        return result; \
    }

#define IMPL_STATIC_BYTE_FIELD(className, name) \
    JACE_PROXY_API JByte className::name() { \
        JNIEnv* env = jace::helper::attach(); \
        jace::RSClassMapper* rscm = RSClassMapper::DefaultInstance(); \
        QString clsName = rscm->getStaticFieldClass(#name); \
        std::string fldName = rscm->getStaticFieldName(#name).toStdString(); \
        jclass cls = rscm->getClass(clsName); \
        if (cls == NULL) throw jace::MappingUnavailableException(QStringLiteral("Class of Static Field ").append(#name)); \
        jfieldID field = env->GetStaticFieldID(cls, fldName.c_str(), "B"); \
        if (field == 0) throw jace::MappingUnavailableException(QStringLiteral("Static Field ").append(#name)); \
        return JByte(static_cast<jbyte>(env->GetStaticIntField(cls, field))); \
    }

#define IMPL_STATIC_INT_FIELD(className, name) \
    JACE_PROXY_API JInt className::name() { \
        JNIEnv* env = jace::helper::attach(); \
        jace::RSClassMapper* rscm = RSClassMapper::DefaultInstance(); \
        QString clsName = rscm->getStaticFieldClass(#name); \
        std::string fldName = rscm->getStaticFieldName(#name).toStdString(); \
        jlong multiplier = rscm->getStaticFieldModifier(#name); \
        jclass cls = rscm->getClass(clsName); \
        if (cls == NULL) throw jace::MappingUnavailableException(QStringLiteral("Class of Static Field ").append(#name)); \
        jfieldID field = env->GetStaticFieldID(cls, fldName.c_str(), "I"); \
        if (field == 0) throw jace::MappingUnavailableException(QStringLiteral("Static Field ").append(#name)); \
        return JInt(static_cast<jint>(env->GetStaticIntField(cls, field) * multiplier)); \
    }

#define IMPL_STATIC_SHORT_FIELD(className, name) \
    JACE_PROXY_API JShort className::name() { \
        JNIEnv* env = jace::helper::attach(); \
        jace::RSClassMapper* rscm = RSClassMapper::DefaultInstance(); \
        QString clsName = rscm->getStaticFieldClass(#name); \
        std::string fldName = rscm->getStaticFieldName(#name).toStdString(); \
        jlong multiplier = rscm->getStaticFieldModifier(#name); \
        jclass cls = rscm->getClass(clsName); \
        if (cls == NULL) throw jace::MappingUnavailableException(QStringLiteral("Class of Static Field ").append(#name)); \
        jfieldID field = env->GetStaticFieldID(cls, fldName.c_str(), "S"); \
        if (field == 0) throw jace::MappingUnavailableException(QStringLiteral("Static Field ").append(#name)); \
        return JShort(static_cast<jshort>(env->GetStaticShortField(cls, field) * multiplier)); \
    }

#define IMPL_STATIC_LONG_FIELD(className, name) \
    JACE_PROXY_API JLong className::name() { \
        JNIEnv* env = jace::helper::attach(); \
        jace::RSClassMapper* rscm = RSClassMapper::DefaultInstance(); \
        QString clsName = rscm->getStaticFieldClass(#name); \
        std::string fldName = rscm->getStaticFieldName(#name).toStdString(); \
        jlong multiplier = rscm->getStaticFieldModifier(#name); \
        jclass cls = rscm->getClass(clsName); \
        if (cls == NULL) throw jace::MappingUnavailableException(QStringLiteral("Class of Static Field ").append(#name)); \
        jfieldID field = env->GetStaticFieldID(cls, fldName.c_str(), "J"); \
        if (field == 0) throw jace::MappingUnavailableException(QStringLiteral("Static Field ").append(#name)); \
        return JLong(static_cast<jlong>(env->GetStaticLongField(cls, field) * multiplier)); \
    }

#define IMPL_STATIC_DOUBLE_FIELD(className, name) \
    JACE_PROXY_API JDouble className::name() { \
        JNIEnv* env = jace::helper::attach(); \
        jace::RSClassMapper* rscm = RSClassMapper::DefaultInstance(); \
        QString clsName = rscm->getStaticFieldClass(#name); \
        std::string fldName = rscm->getStaticFieldName(#name).toStdString(); \
        jclass cls = rscm->getClass(clsName); \
        if (cls == NULL) throw jace::MappingUnavailableException(QStringLiteral("Class of Static Field ").append(#name)); \
        jfieldID field = env->GetStaticFieldID(cls, fldName.c_str(), "D"); \
        if (field == 0) throw jace::MappingUnavailableException(QStringLiteral("Static Field ").append(#name)); \
        return JDouble(static_cast<jdouble>(env->GetStaticDoubleField(cls, field))); \
    }

#define IMPL_STATIC_FLOAT_FIELD(className, name) \
    JACE_PROXY_API JFloat className::name() { \
        JNIEnv* env = jace::helper::attach(); \
        jace::RSClassMapper* rscm = RSClassMapper::DefaultInstance(); \
        QString clsName = rscm->getStaticFieldClass(#name); \
        std::string fldName = rscm->getStaticFieldName(#name).toStdString(); \
        jclass cls = rscm->getClass(clsName); \
        if (cls == NULL) throw jace::MappingUnavailableException(QStringLiteral("Class of Static Field ").append(#name)); \
        jfieldID field = env->GetStaticFieldID(cls, fldName.c_str(), "F"); \
        if (field == 0) throw jace::MappingUnavailableException(QStringLiteral("Static Field ").append(#name)); \
        return JFloat(static_cast<jfloat>(env->GetStaticIntField(cls, field))); \
    }

#define IMPL_STATIC_BOOLEAN_FIELD(className, name) \
    JACE_PROXY_API JBoolean className::name() { \
        JNIEnv* env = jace::helper::attach(); \
        jace::RSClassMapper* rscm = RSClassMapper::DefaultInstance(); \
        QString clsName = rscm->getStaticFieldClass(#name); \
        std::string fldName = rscm->getStaticFieldName(#name).toStdString(); \
        jclass cls = rscm->getClass(clsName); \
        if (cls == NULL) throw jace::MappingUnavailableException(QStringLiteral("Class of Static Field ").append(#name)); \
        jfieldID field = env->GetStaticFieldID(cls, fldName.c_str(), "Z"); \
        if (field == 0) throw jace::MappingUnavailableException(QStringLiteral("Static Field ").append(#name)); \
        return JBoolean(static_cast<jboolean>(env->GetStaticIntField(cls, field))); \
    }

#define IMPL_STATIC_CHAR_FIELD(className, name) \
    JACE_PROXY_API JChar className::name() { \
        JNIEnv* env = jace::helper::attach(); \
        jace::RSClassMapper* rscm = RSClassMapper::DefaultInstance(); \
        QString clsName = rscm->getStaticFieldClass(#name); \
        std::string fldName = rscm->getStaticFieldName(#name).toStdString(); \
        jclass cls = rscm->getClass(clsName); \
        if (cls == NULL) throw jace::MappingUnavailableException(QStringLiteral("Class of Static Field ").append(#name)); \
        jfieldID field = env->GetStaticFieldID(cls, fldName.c_str(), "C"); \
        if (field == 0) throw jace::MappingUnavailableException(QStringLiteral("Static Field ").append(#name)); \
        return JChar(static_cast<jchar>(env->GetStaticCharField(cls, field))); \
    }

#endif // METHODHELPER_H
