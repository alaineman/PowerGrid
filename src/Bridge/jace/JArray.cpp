#include "jace/JArray.h"
#include <string>

namespace jace {

// ------------------------------------------------
// Template Specialization definitions for JArray
// ------------------------------------------------

JBoolean JArray<JBoolean>::operator [](const int &index) const {
#ifdef JACE_CHECK_NULLS
    if (! getJavaJniObject()) {
        throw JNIException("JArray::operator[] - Null");
    }
#endif
#ifdef JACE_CHECK_ARRAYS
    if (index >= length()) {
        throw JNIException("index > array length");
    }
#endif
    jbooleanArray thisArray = static_cast<jbooleanArray> (getJavaJniArray());
    jboolean val;
    helper::attach()->GetBooleanArrayRegion(thisArray, index, 1, &val);
    return JBoolean( val );
}

JByte JArray<JByte>::operator [](const int &index) const {
#ifdef JACE_CHECK_NULLS
    if (! getJavaJniObject()) {
        throw JNIException("JArray::operator[] - Null");
    }
#endif
#ifdef JACE_CHECK_ARRAYS
    if (index >= length()) {
        throw JNIException("index > array length");
    }
#endif
    jbyteArray thisArray = static_cast<jbyteArray> (getJavaJniArray());
    jbyte val;
    helper::attach()->GetByteArrayRegion(thisArray, index, 1, &val);
    return JByte( val );
}

JChar JArray<JChar>::operator [](const int &index) const {
#ifdef JACE_CHECK_NULLS
    if (! getJavaJniObject()) {
        throw JNIException("JArray::operator[] - Null");
    }
#endif
#ifdef JACE_CHECK_ARRAYS
    if (index >= length()) {
        throw JNIException("index > array length");
    }
#endif
    jcharArray thisArray = static_cast<jcharArray> (getJavaJniArray());
    jchar val;
    helper::attach()->GetCharArrayRegion(thisArray, index, 1, &val);
    return JChar( val );
}

JDouble JArray<JDouble>::operator [](const int &index) const {
#ifdef JACE_CHECK_NULLS
    if (! getJavaJniObject()) {
        throw JNIException("JArray::operator[] - Null");
    }
#endif
#ifdef JACE_CHECK_ARRAYS
    if (index >= length()) {
        throw JNIException("index > array length");
    }
#endif
    jdoubleArray thisArray = static_cast<jdoubleArray> (getJavaJniArray());
    jdouble val;
    helper::attach()->GetDoubleArrayRegion(thisArray, index, 1, &val);
    return JDouble( val );
}

JFloat JArray<JFloat>::operator [](const int &index) const {
#ifdef JACE_CHECK_NULLS
    if (! getJavaJniObject()) {
        throw JNIException("JArray::operator[] - Null");
    }
#endif
#ifdef JACE_CHECK_ARRAYS
    if (index >= length()) {
        throw JNIException("index > array length");
    }
#endif
    jfloatArray thisArray = static_cast<jfloatArray> (getJavaJniArray());
    jfloat val;
    helper::attach()->GetFloatArrayRegion(thisArray, index, 1, &val);
    return JFloat( val );
}

JInt JArray<JInt>::operator [](const int &index) const {
#ifdef JACE_CHECK_NULLS
    if (! getJavaJniObject()) {
        throw JNIException("JArray::operator[] - Null");
    }
#endif
#ifdef JACE_CHECK_ARRAYS
    if (index >= length()) {
        throw JNIException("index > array length");
    }
#endif
    jintArray thisArray = static_cast<jintArray> (getJavaJniArray());
    jint val;
    helper::attach()->GetIntArrayRegion(thisArray, index, 1, &val);
    return JInt( val );
}

JShort JArray<JShort>::operator [](const int &index) const {
#ifdef JACE_CHECK_NULLS
    if (! getJavaJniObject()) {
        throw JNIException("JArray::operator[] - Null");
    }
#endif
#ifdef JACE_CHECK_ARRAYS
    if (index >= length()) {
        throw JNIException("index > array length");
    }
#endif
    jshortArray thisArray = static_cast<jshortArray> (getJavaJniArray());
    jshort val;
    helper::attach()->GetShortArrayRegion(thisArray, index, 1, &val);
    return JShort( val );
}

JLong JArray<JLong>::operator [](const int &index) const {
#ifdef JACE_CHECK_NULLS
    if (! getJavaJniObject()) {
        throw JNIException("JArray::operator[] - Null");
    }
#endif
#ifdef JACE_CHECK_ARRAYS
    if (index >= length()) {
        throw JNIException("index > array length");
    }
#endif
    jlongArray thisArray = static_cast<jlongArray> (getJavaJniArray());
    jlong val;
    helper::attach()->GetLongArrayRegion(thisArray, index, 1, &val);
    return JLong( val );
}

#define JArrayCommons(Type) \
    JArray<Type>::JArray(jvalue val) : JObject(val) {} \
    JArray<Type>::JArray(jobject obj) : JObject(obj) {} \
    QList<Type> JArray<Type>::toQList() const {\
        QList<Type> list; \
        for (int i=0; i<length(); i++) { \
            list << this->operator[](i); \
        } \
        return list; \
    } \
    jsize JArray<Type>::length() const { \
        return helper::attach()->GetArrayLength(getJavaJniArray());\
    } \
    const JClass* JArray<Type>::getJavaJniClass() const throw(JNIException) {\
        return JArray<Type>::staticGetJavaJniClass();\
    } \
    const JClass* JArray<Type>::staticGetJavaJniClass() throw(JNIException) { \
        static JClassImpl cls (Type::staticGetJavaJniClass()->getName(), Type::staticGetJavaJniClass()->getNameAsType()); \
        return &cls; \
    } \
    jarray JArray<Type>::getJavaJniArray() const { \
        return static_cast<jarray>(getJavaJniObject()); \
    }

JArrayCommons(JBoolean)
JArrayCommons(JByte)
JArrayCommons(JChar)
JArrayCommons(JDouble)
JArrayCommons(JFloat)
JArrayCommons(JInt)
JArrayCommons(JShort)
JArrayCommons(JLong)

#undef JArrayCommons

}
