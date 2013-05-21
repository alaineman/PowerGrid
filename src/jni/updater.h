#ifndef UPDATER_H
#define UPDATER_H

#include "stdafx.h"
#include "javaenv.h"
#include "cache/stringmap.h"

using cache::StringMap;

namespace jni {
  class Updater {
    protected:
      JavaEnv* env;
      StringMap<jclass> bindings;
    public:
      Updater(JavaEnv* environment);

      JavaEnv* Env();

      jclass GetClass(cstring identifier);
      cstring Identify(jclass cls);
  };
}
#endif // UPDATER_H
