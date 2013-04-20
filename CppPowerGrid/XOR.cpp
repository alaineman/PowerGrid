#include <jni.h>
#include "XOR.h"
#include <cstdlib>
 

int count = 0;
int d = 0x9e3779b9;

JNIEXPORT void JNICALL Java_powergrid_core_decoding_XOR_rotate
            (JNIEnv * env, jobject, jbyteArray b, jint offset, jint length, jbyteArray key, jint opmode){
    jbyte* k = env->GetByteArrayElements(key,NULL);
    jbyte* arr = env->GetByteArrayElements(b,NULL);
    int klength = env->GetArrayLength(k);
    
    
    for(int i = offset; i < offset + length; i++){
        ++count %= klength;
        d += k[(klength - count - 1)];
        if (opmode == 2) { // 2 = DECRYPT_MODE
            arr[i] = (arr[i] + (d & 0x7f) % 0xff ^ k[count]);
        } else {
            arr[i] = arr[i] ^ k[count] - (d & 0x7f) % 0xff;
        }
        
    } 
    env->ReleaseByteArrayElements(key, k, 0);
    env->ReleaseByteArrayElements(b, arr, 0);
    
}







