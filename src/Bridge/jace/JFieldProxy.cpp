#include "jace/JFieldProxy.h"
#include "jace/JNIHelper.h"


using namespace ::jace::proxy::types;

namespace jace {

JFieldProxy<JBoolean>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) :
  JBoolean( value ), fieldID( fieldID_ ) {

  if ( parent_ ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, parent_ );
  }
  else {
    parent = parent_;
  }

  parentClass = 0;
}

JFieldProxy<JBoolean>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) :
  JBoolean( value ), fieldID( fieldID_ ) {

  parent = 0;
  JNIEnv* env = ::jace::helper::attach();
  parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
}

JFieldProxy<JBoolean>::JFieldProxy( const JFieldProxy<JBoolean>& object ) :
  JBoolean( object.getJavaJniValue() ), fieldID( object.fieldID ) {

  if ( object.parent ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, object.parent );
  }
  else {
    parent = 0;
  }

  if ( object.parentClass ) {
    JNIEnv* env = ::jace::helper::attach();
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
  }
  else {
    parentClass = 0;
  }
}

JBoolean& JFieldProxy<JBoolean>::operator=( const JBoolean& type ) {

  JNIEnv* env = helper::attach();
  jvalue value = type.getJavaJniValue();
  setJavaJniValue( value );

  /* If we don't have a parent object, we are a static field member.
   */
  if ( ! parent ) {
    jclass fieldClass = parentClass;
    env->SetStaticBooleanField( fieldClass, fieldID, type.getBoolean() );
  }
  /* Otherwise, we are an instance member.
   */
  else {
    env->SetBooleanField( parent, fieldID, type.getBoolean() );
  }

  return *this;
}

JFieldProxy<JByte>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) :
  JByte( value ), fieldID( fieldID_ ) {

  if ( parent_ ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, parent_ );
  }
  else {
    parent = parent_;
  }

  parentClass = 0;
}

JFieldProxy<JByte>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) :
  JByte( value ), fieldID( fieldID_ ) {

  parent = 0;
  JNIEnv* env = ::jace::helper::attach();
  parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
}

JFieldProxy<JByte>::JFieldProxy( const JFieldProxy<JByte>& object ) :
  JByte( object.getJavaJniValue() ), fieldID( object.fieldID ) {

  if ( object.parent ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, object.parent );
  }
  else {
    parent = 0;
  }

  if ( object.parentClass ) {
    JNIEnv* env = ::jace::helper::attach();
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
  }
  else {
    parentClass = 0;
  }
}

JByte& JFieldProxy<JByte>::operator=( const JByte& type ) {

  JNIEnv* env = helper::attach();
  jvalue value = type.getJavaJniValue();
  setJavaJniValue( value );

  /* If we don't have a parent object, we are a static field member.
   */
  if ( ! parent ) {
    jclass fieldClass = parentClass;
    env->SetStaticByteField( fieldClass, fieldID, type.getByte() );
  }
  /* Otherwise, we are an instance member.
   */
  else {
    env->SetByteField( parent, fieldID, type.getByte() );
  }

  return *this;
}

JFieldProxy<JChar>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) :
  JChar( value ), fieldID( fieldID_ ) {

  if ( parent_ ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, parent_ );
  }
  else {
    parent = parent_;
  }

  parentClass = 0;
}

JFieldProxy<JChar>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) :
  JChar( value ), fieldID( fieldID_ ) {

  parent = 0;
  JNIEnv* env = ::jace::helper::attach();
  parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
}

JFieldProxy<JChar>::JFieldProxy( const JFieldProxy<JChar>& object ) :
  JChar( object.getJavaJniValue() ), fieldID( object.fieldID ) {

  if ( object.parent ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, object.parent );
  }
  else {
    parent = 0;
  }

  if ( object.parentClass ) {
    JNIEnv* env = ::jace::helper::attach();
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
  }
  else {
    parentClass = 0;
  }
}

JChar& JFieldProxy<JChar>::operator=( const JChar& type ) {

  JNIEnv* env = helper::attach();
  jvalue value = type.getJavaJniValue();
  setJavaJniValue( value );

  /* If we don't have a parent object, we are a static field member.
   */
  if ( ! parent ) {
    jclass fieldClass = parentClass;
    env->SetStaticCharField( fieldClass, fieldID, type.getChar() );
  }
  /* Otherwise, we are an instance member.
   */
  else {
    env->SetCharField( parent, fieldID, type.getChar() );
  }

  return *this;
}

JFieldProxy<JShort>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) :
  JShort( value ), fieldID( fieldID_ ) {

  if ( parent_ ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, parent_ );
  }
  else {
    parent = parent_;
  }

  parentClass = 0;
}

JFieldProxy<JShort>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) :
  JShort( value ), fieldID( fieldID_ ) {

  parent = 0;
  JNIEnv* env = ::jace::helper::attach();
  parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
}

JFieldProxy<JShort>::JFieldProxy( const JFieldProxy<JShort>& object ) :
  JShort( object.getJavaJniValue() ), fieldID( object.fieldID ) {

  if ( object.parent ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, object.parent );
  }
  else {
    parent = 0;
  }

  if ( object.parentClass ) {
    JNIEnv* env = ::jace::helper::attach();
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
  }
  else {
    parentClass = 0;
  }
}

JShort& JFieldProxy<JShort>::operator=( const JShort& type ) {

  JNIEnv* env = helper::attach();
  jvalue value = type.getJavaJniValue();
  setJavaJniValue( value );

  /* If we don't have a parent object, we are a static field member.
   */
  if ( ! parent ) {
    jclass fieldClass = parentClass;
    env->SetStaticShortField( fieldClass, fieldID, type.getShort() );
  }
  /* Otherwise, we are an instance member.
   */
  else {
    env->SetShortField( parent, fieldID, type.getShort() );
  }

  return *this;
}

JFieldProxy<JInt>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) :
  JInt( value ), fieldID( fieldID_ ) {

  if ( parent_ ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, parent_ );
  }
  else {
    parent = parent_;
  }

  parentClass = 0;
}

JFieldProxy<JInt>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) :
  JInt( value ), fieldID( fieldID_ ) {

  parent = 0;
  JNIEnv* env = ::jace::helper::attach();
  parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
}

JFieldProxy<JInt>::JFieldProxy( const JFieldProxy<JInt>& object ) :
  JInt( object.getJavaJniValue() ), fieldID( object.fieldID ) {

  if ( object.parent ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, object.parent );
  }
  else {
    parent = 0;
  }

  if ( object.parentClass ) {
    JNIEnv* env = ::jace::helper::attach();
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
  }
  else {
    parentClass = 0;
  }
}

JInt& JFieldProxy<JInt>::operator=( const JInt& type ) {

  JNIEnv* env = helper::attach();
  jvalue value = type.getJavaJniValue();
  setJavaJniValue( value );

  /* If we don't have a parent object, we are a static field member.
   */
  if ( ! parent ) {
    jclass fieldClass = parentClass;
    env->SetStaticIntField( fieldClass, fieldID, type.getInt() );
  }
  /* Otherwise, we are an instance member.
   */
  else {
    env->SetIntField( parent, fieldID, type.getInt() );
  }

  return *this;
}

JFieldProxy<JLong>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) :
  JLong( value ), fieldID( fieldID_ ) {

  if ( parent_ ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, parent_ );
  }
  else {
    parent = parent_;
  }

  parentClass = 0;
}

JFieldProxy<JLong>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) :
  JLong( value ), fieldID( fieldID_ ) {

  parent = 0;
  JNIEnv* env = ::jace::helper::attach();
  parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
}

JFieldProxy<JLong>::JFieldProxy( const JFieldProxy<JLong>& object ) :
  JLong( object.getJavaJniValue() ), fieldID( object.fieldID ) {

  if ( object.parent ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, object.parent );
  }
  else {
    parent = 0;
  }

  if ( object.parentClass ) {
    JNIEnv* env = ::jace::helper::attach();
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
  }
  else {
    parentClass = 0;
  }
}

JLong& JFieldProxy<JLong>::operator=( const JLong& type ) {

  JNIEnv* env = helper::attach();
  jvalue value = type.getJavaJniValue();
  setJavaJniValue( value );

  /* If we don't have a parent object, we are a static field member.
   */
  if ( ! parent ) {
    jclass fieldClass = parentClass;
    env->SetStaticLongField( fieldClass, fieldID, type.getLong() );
  }
  /* Otherwise, we are an instance member.
   */
  else {
    env->SetLongField( parent, fieldID, type.getLong() );
  }

  return *this;
}

JFieldProxy<JFloat>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) :
  JFloat( value ), fieldID( fieldID_ ) {

  if ( parent_ ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, parent_ );
  }
  else {
    parent = parent_;
  }

  parentClass = 0;
}

JFieldProxy<JFloat>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) :
  JFloat( value ), fieldID( fieldID_ ) {

  parent = 0;
  JNIEnv* env = ::jace::helper::attach();
  parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
}

JFieldProxy<JFloat>::JFieldProxy( const JFieldProxy<JFloat>& object ) :
  JFloat( object.getJavaJniValue() ), fieldID( object.fieldID ) {

  if ( object.parent ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, object.parent );
  }
  else {
    parent = 0;
  }

  if ( object.parentClass ) {
    JNIEnv* env = ::jace::helper::attach();
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
  }
  else {
    parentClass = 0;
  }
}

JFloat& JFieldProxy<JFloat>::operator=( const JFloat& type ) {

  JNIEnv* env = helper::attach();
  jvalue value = type.getJavaJniValue();
  setJavaJniValue( value );

  /* If we don't have a parent object, we are a static field member.
   */
  if ( ! parent ) {
    jclass fieldClass = parentClass;
    env->SetStaticFloatField( fieldClass, fieldID, type.getFloat() );
  }
  /* Otherwise, we are an instance member.
   */
  else {
    env->SetFloatField( parent, fieldID, type.getFloat() );
  }

  return *this;
}

JFieldProxy<JDouble>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) :
  JDouble( value ), fieldID( fieldID_ ) {

  if ( parent_ ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, parent_ );
  }
  else {
    parent = parent_;
  }

  parentClass = 0;
}

JFieldProxy<JDouble>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) :
  JDouble( value ), fieldID( fieldID_ ) {

  parent = 0;
  JNIEnv* env = ::jace::helper::attach();
  parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
}

JFieldProxy<JDouble>::JFieldProxy( const JFieldProxy<JDouble>& object ) :
  JDouble( object.getJavaJniValue() ), fieldID( object.fieldID ) {

  if ( object.parent ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = ::jace::helper::newGlobalRef( env, object.parent );
  }
  else {
    parent = 0;
  }

  if ( object.parentClass ) {
    JNIEnv* env = ::jace::helper::attach();
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
  }
  else {
    parentClass = 0;
  }
}

JDouble& JFieldProxy<JDouble>::operator=( const JDouble& type ) {

  JNIEnv* env = helper::attach();
  jvalue value = type.getJavaJniValue();
  setJavaJniValue( value );

  /* If we don't have a parent object, we are a static field member.
   */
  if ( ! parent ) {
    jclass fieldClass = parentClass;
    env->SetStaticDoubleField( fieldClass, fieldID, type.getDouble() );
  }
  /* Otherwise, we are an instance member.
   */
  else {
    env->SetDoubleField( parent, fieldID, type.getDouble() );
  }

  return *this;
}

}

