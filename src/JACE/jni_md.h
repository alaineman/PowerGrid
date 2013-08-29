/*
 * Modified version of the platform-dependant header file
 * based on #defines. This allows every platform to include the
 * same header file, reducing the complexity.
 */

#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#ifdef JNI_WIN32
# define JNIEXPORT __declspec(dllexport)
# define JNIIMPORT __declspec(dllimport)
# define JNICALL __stdcall

typedef long jint;
typedef __int64 jlong;
typedef signed char jbyte;

#else
# define JNIEXPORT
# define JNIIMPORT
# define JNICALL

typedef int jint;
# ifdef _LP64 /* 64-bit Solaris */
typedef long jlong;
# else
typedef long long jlong;
# endif

typedef signed char jbyte;

#endif

#endif /* !_JAVASOFT_JNI_MD_H_ */
