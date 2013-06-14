#ifndef OVERHEADMESSAGE_H
#define OVERHEADMESSAGE_H

#include "jniobject.h"
#include "jnistring.h"

namespace world{

class OverheadMessage : public jni::JNIObject{
private:
    Q_DISABLE_COPY(OverheadMessage)
    jni::JNIString* text;
public:
    OverheadMessage(jobject obj) : JNIObject(obj){}
    jni::JNIString* getText(bool useCache = true);
};

}

#endif // OVERHEADMESSAGE_H
