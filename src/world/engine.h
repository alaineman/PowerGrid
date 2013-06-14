#ifndef ENGINE_H
#define ENGINE_H

#include "jniobject.h"

namespace world{

class Engine : public jni::JNIObject {
private:
    Q_DISABLE_COPY(Engine)
public:
    Engine(jobject obj) : JNIObject(obj){}
};

}
#endif // ENGINE_H
