#include "jnielement.h"

namespace jni {
  JNIElement::JNIElement(string nm) {

    name = nm;
  }

  string JNIElement::GetName() {
    return name;
  }
}
