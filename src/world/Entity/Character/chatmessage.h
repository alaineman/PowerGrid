#ifndef CHATMESSAGE_H
#define CHATMESSAGE_H

#include "jniobject.h"
#include "jnistring.h"

namespace world{

class ChatMessage : public jni::JNIObject{
private:
    Q_DISABLE_COPY(ChatMessage)
    jni::JNIString* text;
public:
    ChatMessage(jobject obj) : JNIObject(obj){}
    jni::JNIString* getText(bool useCache = true);
};

}

#endif // CHATMESSAGE_H
