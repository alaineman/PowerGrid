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
    try {
      //jclass cls = bindings.Get(identifier);
    } catch (logic_error e) {
      qDebug() << "Got request for unidentified class: " << identifier;
    }
    return NULL;
  }
}
