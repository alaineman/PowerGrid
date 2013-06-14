#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "linkedlistnode.h"

namespace world {

class LinkedList : public jni::JNIObject {
private:
    Q_DISABLE_COPY(LinkedList)
    LinkedListNode* sentinel;
public:
    LinkedList(jobject obj) : JNIObject(obj){}
    LinkedListNode* getSentinel(bool useCache = true);
};

}

#endif // LINKEDLIST_H
