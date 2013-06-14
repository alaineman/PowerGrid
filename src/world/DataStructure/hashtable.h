#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "jniobject.h"
#include "Node/node.h"

using namespace jni;

namespace world {

  class HashTable : public jni::JNIObject {
    private:
      Q_DISABLE_COPY(HashTable)
      vector<Node*> buckets;
    public:
      HashTable(jobject obj) : JNIObject(obj) {}
      vector<Node*> getBuckets(bool useCache = true);

      class iterator {
        // STL-style iterator delegating to std::vector::iterator of buckets field
      };
      iterator getIterator(bool useCache = true);
  };
}

#endif // HASHTABLE_H
