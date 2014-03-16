#ifndef JACE_JFIELD_PROXY_HELPER_H
#define JACE_JFIELD_PROXY_HELPER_H

#include "os_dep.h"
#include "jace/proxy/JObject.h"
#include "jace/JClass.h"

#include "jni.h"

namespace jace {
namespace JFieldProxyHelper {

JACE_API jobject assign( const jace::proxy::JObject& field, jobject parent, jfieldID fieldID, const jace::JClass* classType );
JACE_API jobject assign( const jace::proxy::JObject& field, jclass parentClass, jfieldID fieldID, const jace::JClass* classType );

}
}

#endif
