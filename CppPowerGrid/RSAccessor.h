#include <jni.h>

/* This header defines the functions that are used in unscrambling Java strings.
 * 
 */
#ifndef UNSCRAMBLE_H
#define UNSCRAMBLE_H
#ifdef __cplusplus
extern "C" {
#endif
    
#define LSH(x,n) ((int)((unsigned int)x >> n));
    
    /*
     * Java handle for unscramble method in powergrid.core.RSAccessor
     * signature: (Ljava.lang.String;)[B
     */
    JNIEXPORT jbyteArray JNICALL Java_powergrid_core_RSAccessor_unscramble
            (JNIEnv *, jobject, jstring, jint);

    /*
     * Returns the unscrambled byte for the given char
     */
    jbyte byteFor(char*, int, int);

#ifdef __cplusplus
}
#endif
#endif
