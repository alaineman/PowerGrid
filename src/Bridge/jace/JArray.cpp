#include "jace/JArray.h"
#include <string>

namespace jace {

// ------------------------------------------------
// Template Specialization definitions for JArray
// ------------------------------------------------

JArray<JBoolean>::JArray(int size) : JObject( NO_OP ) {
    JNIEnv* env = helper::attach();
    jarray array = env->NewBooleanArray(size);
    helper::catchAndThrow();
    if (array == NULL) {
        throw JNIException("Unable to construct a new array ");
    }
    setJavaJniObject(array);
    env->DeleteLocalRef(array);
    this->length_ = -1;
}

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

JArray<JByte>::JArray(int size) : JObject( NO_OP ) {
    JNIEnv* env = helper::attach();
    jarray array = env->NewByteArray(size);
    helper::catchAndThrow();
    if (array == NULL) {
        throw JNIException("Unable to construct a new array ");
    }
    setJavaJniObject(array);
    env->DeleteLocalRef(array);
    this->length_ = -1;
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

JArray<JChar>::JArray(int size) : JObject( NO_OP ) {
    JNIEnv* env = helper::attach();
    jarray array = env->NewCharArray(size);
    helper::catchAndThrow();
    if (array == NULL) {
        throw JNIException("Unable to construct a new array ");
    }
    setJavaJniObject(array);
    env->DeleteLocalRef(array);
    this->length_ = -1;
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

JArray<JDouble>::JArray(int size) : JObject( NO_OP ) {
    JNIEnv* env = helper::attach();
    jarray array = env->NewDoubleArray(size);
    helper::catchAndThrow();
    if (array == NULL) {
        throw JNIException("Unable to construct a new array ");
    }
    setJavaJniObject(array);
    env->DeleteLocalRef(array);
    this->length_ = -1;
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

JArray<JFloat>::JArray(int size) : JObject( NO_OP ) {
    JNIEnv* env = helper::attach();
    jarray array = env->NewFloatArray(size);
    helper::catchAndThrow();
    if (array == NULL) {
        throw JNIException("Unable to construct a new array ");
    }
    setJavaJniObject(array);
    env->DeleteLocalRef(array);
    this->length_ = -1;
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

JArray<JInt>::JArray(int size) : JObject( NO_OP ) {
    JNIEnv* env = helper::attach();
    jarray array = env->NewIntArray(size);
    helper::catchAndThrow();
    if (array == NULL) {
        throw JNIException("Unable to construct a new array ");
    }
    setJavaJniObject(array);
    env->DeleteLocalRef(array);
    this->length_ = -1;
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

JArray<JShort>::JArray(int size) : JObject( NO_OP ) {
    JNIEnv* env = helper::attach();
    jarray array = env->NewShortArray(size);
    helper::catchAndThrow();
    if (array == NULL) {
        throw JNIException("Unable to construct a new array ");
    }
    setJavaJniObject(array);
    env->DeleteLocalRef(array);
    this->length_ = -1;
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

JArray<JLong>::JArray(int size) : JObject( NO_OP ) {
    JNIEnv* env = helper::attach();
    jarray array = env->NewLongArray(size);
    helper::catchAndThrow();
    if (array == NULL) {
        throw JNIException("Unable to construct a new array ");
    }
    setJavaJniObject(array);
    env->DeleteLocalRef(array);
    this->length_ = -1;
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
    JArray<Type>::JArray(jvalue& val) : JObject(val), length_(-1) {} \
    JArray<Type>::JArray(jobject& obj) : JObject(obj), length_(-1) {} \
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
