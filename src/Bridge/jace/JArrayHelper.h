#ifndef JACE_JARRAY_HELPER
#define JACE_JARRAY_HELPER

#include "os_dep.h"
#include "jace/proxy/JObject.h"
#include "jace/JClass.h"
#include "jace/proxy/types/JInt.h"

#include "jni.h"

namespace jace {
namespace JArrayHelper {

JACE_API jobjectArray newArray( int size, const jace::JClass* elementClass );
JACE_API jace::proxy::types::JInt getLength( jobject obj );
JACE_API jvalue getElement( jobject obj, int index );

}
}
#endif

