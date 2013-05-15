#ifndef JNIELEMENT_H
#define JNIELEMENT_H

#include "stdafx.h"
#include "jni.h"

namespace jni {
  using namespace std;

  // This class represents all JNI element types, ranging from classes and objects to method IDs.
  // JNIElement objects have a name that allows for easy identification of the element.
  class JNIElement {
    private:
      string name;
    protected:
      JNIElement(string nm);
    public:
      string GetName();
  };
}
#endif // JNIELEMENT_H
