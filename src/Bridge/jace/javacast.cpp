#include "jace/javacast.h"

namespace jace {
    jobject java_cast(const proxy::JObject &obj) {
        return obj.getJavaJniObject();
    }
}
