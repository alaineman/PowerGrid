#include "updater.h"

namespace jni {
  Updater::Updater(JavaEnv *environment) {
    if (environment == NULL) throw runtime_error("JavaEnv argument cannot be NULL");
    env = environment;
  }

  JavaEnv* Updater::Env() {
    return env;
  }

  jclass Updater::GetClass(cstring identifier) {
    if (identifier == NULL) {
      qWarning() << "Passed NULL as parameter for Updater::GetClass";
      return NULL;
    }
    try {
      return bindings.Get(identifier);
    } catch (logic_error e) {
      qWarning() << "Got request for unidentified class: " << identifier;
      return NULL;
    }
  }

  cstring Updater::Identify(jclass cls) {
    if (cls == NULL) {
      return NULL;
    }
    cstring id = NULL;
    // perform the id algorithm on the class.

    return id;
  }
}
