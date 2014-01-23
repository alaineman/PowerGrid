
/* This jni_md header has been rewritten to use Qt's defined types.
 * By using Qt's defined data types that ensure the same size on
 * every platform, this header is made so that it is not
 * machine-dependant anymore.
 *
 * For clarity, all types are defined here, and these have been removed
 * from jni.h
 */
#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#include <QtGlobal>

#ifdef Q_OS_WIN32
  #define JNICALL __stdcall
#else
  #define JNICALL
#endif
#define JNIIMPORT Q_DECL_IMPORT
#define JNIEXPORT Q_DECL_EXPORT

// By using Qt's defined qintXX and quintXX types, we can easily
// typedef all Java types in a platform-independant way.
typedef quint8  jboolean;
typedef qint8   jbyte;
typedef quint16 jchar;
typedef qint16  jshort;
typedef qint32  jint;
typedef qint64  jlong;

// floats and doubles in Java are compatible with those in C++.
typedef float   jfloat;
typedef double  jdouble;

typedef jint jsize;

// Object reference types.
class _jobject {};
class _jclass     : public _jobject {};
class _jthrowable : public _jobject {};
class _jstring    : public _jobject {};
class _jarray     : public _jobject {};

// Array reference types.
class _jbooleanArray : public _jarray {};
class _jbyteArray    : public _jarray {};
class _jcharArray    : public _jarray {};
class _jshortArray   : public _jarray {};
class _jintArray     : public _jarray {};
class _jlongArray    : public _jarray {};
class _jfloatArray   : public _jarray {};
class _jdoubleArray  : public _jarray {};
class _jobjectArray  : public _jarray {};

// typedefs for pointer types
typedef _jobject    *jobject;
typedef _jclass     *jclass;
typedef _jthrowable *jthrowable;
typedef _jstring    *jstring;
typedef _jarray     *jarray;

typedef _jbooleanArray *jbooleanArray;
typedef _jbyteArray    *jbyteArray;
typedef _jcharArray    *jcharArray;
typedef _jshortArray   *jshortArray;
typedef _jintArray     *jintArray;
typedef _jlongArray    *jlongArray;
typedef _jfloatArray   *jfloatArray;
typedef _jdoubleArray  *jdoubleArray;
typedef _jobjectArray  *jobjectArray;

// A jobject pointer can also be a weak reference in Java terms
typedef jobject jweak;

typedef union jvalue {
    jboolean z;
    jbyte    b;
    jchar    c;
    jshort   s;
    jint     i;
    jlong    j;
    jfloat   f;
    jdouble  d;
    jobject  l;
} jvalue;

// structs and typedefs for methods and fields
struct _jfieldID;
struct _jmethodID;

typedef struct _jfieldID  *jfieldID;
typedef struct _jmethodID *jmethodID;

// Indicates the type of reference a jobject refers to
typedef enum _jobjectType {
    JNIInvalidRefType    = 0,
    JNILocalRefType      = 1,
    JNIGlobalRefType     = 2,
    JNIWeakGlobalRefType = 3
} jobjectRefType;

#endif /* !_JAVASOFT_JNI_MD_H_ */
