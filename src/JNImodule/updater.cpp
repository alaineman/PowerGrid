#include "updater.h"

namespace jni {
  Updater::Updater(JavaEnv *environment) {
    if (environment == NULL) {
      throw invalid_argument("JavaEnv argument cannot be NULL");
    }
    env = environment;
  }

  JNIClass* Updater::GetClass(QString identifier) {
    try {
      return bindings.take(identifier);
    } catch (logic_error e) {
      qWarning() << "Got request for unidentified class: " << identifier;
      return NULL;
    }
  }

  QString Updater::Identify(jclass cls) {
    if (cls == NULL) {
      throw invalid_argument("class reference cannot be NULL");
    }
    const char* id = NULL;
    // perform the id algorithm on the class.

    return id;
  }
}
