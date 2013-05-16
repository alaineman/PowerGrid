#include "jnielement.h"

namespace jni {
  JNIElement::JNIElement(string nm) {
    VERIFY_THAT(nm.length() != 0)
#ifdef PG_STRING_CHECK
    char first = nm.at(0);
    VERIFY_THAT((first >= 'A' && first <= 'Z') || (first >= 'a' && first <= 'z') || first == '$' || first == '_')
#endif
    name = nm;
  }

  string JNIElement::GetName() {
    return name;
  }
}
