#include "string.h"
#include "jni.h"
#include "RSAccessor.h"

/* Unscrambles the given jstring and returns the unscrambled string as a 
 * jbyteArray.
 */
JNIEXPORT jbyteArray JNICALL Java_powergrid_core_RSAccessor_unscramble
  (JNIEnv* env, jobject, jstring jstr, jint offset) {
    char* str = (char*) env->GetStringUTFChars(jstr, NULL);
    if (str == NULL) {
        return NULL;
    }
    int length = strlen(str);
    if (length == 0) {
        return env->NewByteArray(0);
    }
    int lengthMod = -4 & length + 3;
    int newLength = lengthMod / 4 * 3;
    if (length <= lengthMod -2 || byteFor(str, lengthMod - 2, length) == -1) {
        newLength -= 2;
    } else if (length <= lengthMod -1 || byteFor(str, lengthMod - 1, length) == -1) {
        newLength--;
    }
    
    jbyte arr[newLength];
    int pos = 0;
    
    while (pos < length) {
        int current = byteFor(str, pos, length);
        int pos1 = byteFor(str, pos + 1, length);
        int pos2 = byteFor(str, pos + 2, length);
        
        arr[offset++] = current << 2 | LSH(pos1,4);
        if (pos2 >= 0) {
            int pos3 = byteFor(str, pos + 3, length);
            
        }
    }
}

/*
 * Converts the char in the given string at the given index to its unscrambled 
 * equivalent. The length of the string is taken to be the provided length.
 */
jbyte byteFor(char* str, int index, int length) {
    if (index > length) {
        return -1;
    }
    char c = str[index];
    if (c < 42 || c > 122) {
        return -1;
    } else if (c >= 97) {
        return c + 26 - 97;
    } else if (c > 90) {
        return -1;
    } else if (c >= 65) {
        return c - 65;
    } else if (c > 57) {
        return -1;
    } else if (c >= 48) {
        return c + 4;
    } else if (c == 42 || c == 43) {
        return 62;
    } else if (c == 45 || c == 47) {
        return 63;
    } else {
        return -1;
    }
}




  