
/* This jni_md header has been rewritten to use Qt's defined types.
 * By using Qt's defined data types that ensure the same size on
 * every platform, this header is made so that it is not
 * machine-dependant anymore.
 */
#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#include <QtGlobal>

// By using Qt's defined qintXX and quintXX types, we can easily
// typedef all Java types in a platform-independant way.
typedef quint8  jboolean;
typedef qint8   jbyte;
typedef quint16 jchar;
typedef qint16  jshort;
typedef qint32  jint;
typedef qint64  jlong;

typedef float   jfloat;
typedef double  jdouble;

typedef jint    jsize;

// We need to define this to prevent jni.h from redefining them
#define JNI_TYPES_ALREADY_DEFINED_IN_JNI_MD_H

#endif /* !_JAVASOFT_JNI_MD_H_ */
