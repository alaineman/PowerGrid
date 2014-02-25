#include "jace/ElementProxy.h"

namespace jace {

// ----------------------------------------------------------
// Template specializations for the jace::ElementProxy class
// ----------------------------------------------------------

ElementProxy<JBoolean>::ElementProxy( jarray array, jvalue element, int index ) :
    JBoolean( element ), mIndex( index ) {
  JNIEnv* env = helper::attach();
  parent = static_cast<jarray>( helper::newGlobalRef( env, array ) );
}

JBoolean& ElementProxy<JBoolean>::operator=( const JBoolean type ) {
  JNIEnv* env = helper::attach();
  jbooleanArray array = static_cast<jbooleanArray>( parent );
  jboolean val = type.getJavaJniValue().z;
  env->SetBooleanArrayRegion( array, mIndex, 1, &val );
  return *this;
}

ElementProxy<JByte>::ElementProxy( jarray array, jvalue element, int index ) :
    JByte( element ), mIndex( index ) {
  JNIEnv* env = helper::attach();
  parent = static_cast<jarray>( helper::newGlobalRef( env, array ) );
}

JByte& ElementProxy<JByte>::operator=( const JByte type ) {
  JNIEnv* env = helper::attach();
  jbyteArray array = static_cast<jbyteArray>( parent );
  jbyte byte = type.getJavaJniValue().b;
  env->SetByteArrayRegion( array, mIndex, 1, &byte );
  return *this;
}

ElementProxy<JChar>::ElementProxy( jarray array, jvalue element, int index ) :
  JChar( element ), mIndex( index ) {
  JNIEnv* env = helper::attach();
  parent = static_cast<jarray>( helper::newGlobalRef( env, array ) );
}

JChar& ElementProxy<JChar>::operator=( const JChar type ) {
  JNIEnv* env = helper::attach();
  jcharArray array = static_cast<jcharArray>( parent );
  jchar val = type.getJavaJniValue().c;
  env->SetCharArrayRegion( array, mIndex, 1, &val );
  return *this;
}


ElementProxy<JDouble>::ElementProxy( jarray array, jvalue element, int index ) :
  JDouble( element ), mIndex( index ) {
  JNIEnv* env = helper::attach();
  parent = static_cast<jarray>( helper::newGlobalRef( env, array ) );
}

JDouble& ElementProxy<JDouble>::operator=( const JDouble type ) {
  JNIEnv* env = helper::attach();
  jdoubleArray array = static_cast<jdoubleArray>( parent );
  jdouble val = type.getJavaJniValue().d;
  env->SetDoubleArrayRegion( array, mIndex, 1, &val );
  return *this;
}

ElementProxy<JFloat>::ElementProxy( jarray array, jvalue element, int index ) :
  JFloat( element ), mIndex( index ) {
  JNIEnv* env = helper::attach();
  parent = static_cast<jarray>( helper::newGlobalRef( env, array ) );
}

JFloat& ElementProxy<JFloat>::operator=( const JFloat type ) {
  JNIEnv* env = helper::attach();
  jfloatArray array = static_cast<jfloatArray>( parent );
  jfloat val = type.getJavaJniValue().f;
  env->SetFloatArrayRegion( array, mIndex, 1, &val );
  return *this;
}

ElementProxy<JInt>::ElementProxy( jarray array, jvalue element, int index ) :
  JInt( element ), mIndex( index ) {
  JNIEnv* env = helper::attach();
  parent = static_cast<jarray>( helper::newGlobalRef( env, array ) );
}

JInt& ElementProxy<JInt>::operator=( const JInt type ) {
  JNIEnv* env = helper::attach();
  jintArray array = static_cast<jintArray>( parent );
  jint val = type.getJavaJniValue().i;
  env->SetIntArrayRegion( array, mIndex, 1, &val );
  return *this;
}

ElementProxy<JLong>::ElementProxy( jarray array, jvalue element, int index ) :
  JLong( element ), mIndex( index ) {
  JNIEnv* env = helper::attach();
  parent = static_cast<jarray>( helper::newGlobalRef( env, array ) );
}

JLong& ElementProxy<JLong>::operator=( const JLong type ) {
  JNIEnv* env = helper::attach();
  jlongArray array = static_cast<jlongArray>( parent );
  jlong val = type.getJavaJniValue().j;
  env->SetLongArrayRegion( array, mIndex, 1, &val );
  return *this;
}

ElementProxy<JShort>::ElementProxy( jarray array, jvalue element, int index ) :
  JShort( element ), mIndex( index ) {
  JNIEnv* env = helper::attach();
  parent = static_cast<jarray>( helper::newGlobalRef( env, array ) );
}

JShort& ElementProxy<JShort>::operator=( const JShort type ) {
  JNIEnv* env = helper::attach();
  jshortArray array = static_cast<jshortArray>( parent );
  jshort val = type.getJavaJniValue().s;
  env->SetShortArrayRegion( array, mIndex, 1, &val );
  return *this;
}

}
