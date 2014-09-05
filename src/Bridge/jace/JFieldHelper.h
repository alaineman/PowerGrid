#ifndef JACE_JFIELD_HELPER_H
#define JACE_JFIELD_HELPER_H

#include "os_dep.h"
#include "jace/proxy/JObject.h"
#include "jace/JClass.h"

#include "jni.h"
#include <string>

namespace jace {

class JFieldHelper {
public:
  JACE_API JFieldHelper( const std::string& name, const jace::JClass* typeClass );

  JACE_API jvalue getField( jace::proxy::JObject& object );
  JACE_API jvalue getField( const jace::JClass* jClass );
  JACE_API jfieldID getFieldID( const jace::JClass* parentClass, bool isStatic );
  JACE_API jfieldID getFieldID();

private:
  jfieldID mFieldID;
  const std::string mName;
  const JClass* mTypeClass;
};

}

#endif
