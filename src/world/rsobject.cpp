#include "rsobject.h"
#include "stdexcept"
#include "javaenv.h"

RSObject::RSObject(jobject o, RSClass c, QObject *parent) : QObject(parent) {
  if (o == NULL) {
    throw new std::logic_error("NULL valued java object");
  }
  objectRef = o;
  type = c;
}

RSObject::~RSObject() {
  jni::JavaEnv* javaenv = jni::JavaEnv::instance();
  if (javaenv != NULL) {
    javaenv->deleteLocalReference(objectRef);
  }
}
