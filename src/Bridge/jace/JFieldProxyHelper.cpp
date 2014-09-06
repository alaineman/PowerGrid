
#include "jace/JFieldProxyHelper.h"
#include "jace/JNIHelper.h"

using jace::proxy::JObject;
using jace::JClass;

namespace jace {
namespace JFieldProxyHelper {

jobject assign( const JObject& field, jobject parent, jfieldID fieldID, const JClass*) {

  JNIEnv* env = helper::attach();
  jobject object = field.getJavaJniObject();
  env->SetObjectField( parent, fieldID, object );

  return object;
}


jobject assign( const JObject& field, jclass parentClass, jfieldID fieldID, const JClass*) {

  JNIEnv* env = helper::attach();
  jobject object = field.getJavaJniObject();

  env->SetStaticObjectField( parentClass, fieldID, object );

  return object;
}

}
}
