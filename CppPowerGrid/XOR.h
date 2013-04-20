#include <jni.h>

/* 
 * File:   XOR.h
 * Author: Alaineman
 *
 * Created on April 20, 2013, 9:14 PM
 */

#ifndef XOR_H
#define	XOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ENCRYPT_MODE 1;
#define DECRYPT_MODE 2;
    
    /*
     * Java handle for unscramble method in powergrid.core.decoding.XOR
     * signature: (Ljava.lang.String;)[B
     */
    JNIEXPORT void JNICALL Java_powergrid_core_decoding_XOR_rotate
            (JNIEnv *, jobject, jbyteArray, jint, jint, jbyteArray, jint);


#ifdef	__cplusplus
}
#endif

#endif	/* XOR_H */

