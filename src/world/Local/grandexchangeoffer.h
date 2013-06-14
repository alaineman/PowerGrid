#ifndef GRANDEXCHANGEOFFER_H
#define GRANDEXCHANGEOFFER_H

#include "jniobject.h"

namespace world{

class GrandExchangeOffer : jni::JNIObject{
private:
    Q_DISABLE_COPY(GrandExchangeOffer)
    jbyte state;
    jint itemid;
    jint itemprice;
    jint itemamount;
    jint wealthtransferred;
public:
    GrandExchangeOffer(jobject obj) : JNIObject(obj){}
    jbyte getState(bool useCache = true);
    jint getItemId(bool useCache = true);
    jint getItemPrice(bool useCache = true);
    jint getItemAmount(bool useCache = true);
    jint getWealthTransferred(bool useCache = true);
};

}

#endif // GRANDEXCHANGEOFFER_H
