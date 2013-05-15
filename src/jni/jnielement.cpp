#include "jnielement.h"

namespace jni {
  JNIElement::JNIElement(string nm) {
#ifdef PG_STRING_CHECK
    if (nm.length() == 0) {
      throw runtime_error("empty string for JNIElement name");
    }
    char first = nm.at(0);
    if ((first < 'A' || first > 'Z') &&
        (first < 'a' || first > 'z') &&
        first != '$' && first != '_') {
      throw runtime_error("Illegal Java identifier for JNIElement name");
    }
#endif
    name = nm;
  }

  string JNIElement::GetName() {
    return name;
  }
}
