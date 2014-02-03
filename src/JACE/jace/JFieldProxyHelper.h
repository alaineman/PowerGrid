#ifndef JACE_JFIELD_PROXY_HELPER_H
#define JACE_JFIELD_PROXY_HELPER_H

#include "os_dep.h"
#include "namespace.h"
#include "jace/proxy/JObject.h"
#include "jace/JClass.h"

#include "jni.h"

BEGIN_NAMESPACE_2( jace, JFieldProxyHelper )

JACE_API jobject assign( const jace::proxy::JObject& field, jobject parent, jfieldID fieldID, const jace::JClass* classType );
JACE_API jobject assign( const jace::proxy::JObject& field, jclass parentClass, jfieldID fieldID, const jace::JClass* classType );

END_NAMESPACE_2( jace, JFieldProxyHelper )

#endif
