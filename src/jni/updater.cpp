#include "updater.h"

namespace jni {
  Updater::Updater(JavaEnv *environment) {
    if (ISNULL(environment)) {
      throw invalid_argument("JavaEnv argument cannot be NULL");
    }
    env = environment;
  }

  JavaEnv* Updater::Env() {
    return env;
  }

  JNIClass* Updater::GetClass(QString identifier) {
    try {
      return bindings.Get(identifier);
    } catch (logic_error e) {
      qWarning() << "Got request for unidentified class: " << identifier;
      return NULL;
    }
  }

  QString Updater::Identify(jclass cls) {
    if (ISNULL(cls)) {
      throw invalid_argument("class reference cannot be NULL");
    }
    cstring id = NULL;
    // perform the id algorithm on the class.

    return id;
  }
}
