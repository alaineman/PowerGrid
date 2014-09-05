
#ifndef JACE_JFIELD_PROXY_H
#define JACE_JFIELD_PROXY_H

#include "jace/os_dep.h"
#include "jace/JNIHelper.h"
#include "jace/proxy/JObject.h"
#include "JFieldProxyHelper.h"

#include "jace/proxy/types/JBoolean.h"
#include "jace/proxy/types/JByte.h"
#include "jace/proxy/types/JChar.h"
#include "jace/proxy/types/JDouble.h"
#include "jace/proxy/types/JFloat.h"
#include "jace/proxy/types/JInt.h"
#include "jace/proxy/types/JLong.h"
#include "jace/proxy/types/JShort.h"

using namespace ::jace::proxy::types;

namespace jace {

/**
 * A JFieldProxy is a wrapper around a JField.
 *
 * A JFieldProxy makes sure that assignments can happen to class 
 * and instance fields. For example,
 *
 *
 * // Java class
 * public class Foo {
 *   public String bar;
 * }
 *
 * // C++ proxy class
 * class Foo : public Object {
 *   public:
 *   JFieldProxy<String> bar();
 * }
 *
 * // C++ code.
 * Foo.bar() = String( "Hello!" );
 *
 * @author Toby Reyelts
 *
 */
template <class FieldType> class JFieldProxy : public FieldType {

public:

/**
 * Creates a new JFieldProxy that belongs to the given object,
 * and represents the given value.
 *
 * This constructor should always be specialized away by subclasses.
 *
 */
JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) :
  FieldType( value ), FieldType::JObject( FieldType::JObject::NO_OP ), fieldID( fieldID_ ) {

  JNIEnv* env = ::jace::helper::attach();

  if ( parent_ ) {
    parent = ::jace::helper::newGlobalRef( env, parent_ ); 
  }
  else {
    parent = parent_;
  }

  parentClass = 0;
}


/**
 * Creates a new JFieldProxy that belongs to the given class,
 * and represents the given value. (The field is a static one).
 *
 * This constructor should always be specialized away by subclasses.
 *
 */
JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) :
  FieldType( value ), FieldType::JObject( FieldType::JObject::NO_OP ), fieldID( fieldID_ ) {

  parent = 0;
  JNIEnv* env = ::jace::helper::attach();
  parentClass = ::jace::helper::newGlobalRef( env, parentClass_ ); 
}


/**
 * Creates a new JFieldProxy that belongs to the given object,
 * and represents the given value.
 *
 * This copy constructor should always be specialized away by subclasses.
 *
 */
JFieldProxy( const JFieldProxy& object ) : 
  FieldType( object.getJavaJniValue() ), FieldType::JObject( FieldType::JObject::NO_OP ) {
  JNIEnv* env = ::jace::helper::attach();
  if ( object.parent ) {
    parent = ::jace::helper::newGlobalRef( env, object.parent ); 
  }
  else {
    parent = 0;
  }

  if ( object.parentClass ) {
    parentClass = ::jace::helper::newGlobalRef( env, object.parentClass ); 
  }
  else {
    parentClass = 0;
  }
}


virtual ~JFieldProxy() throw() {

  if ( parent ) {
    try {
      JNIEnv* env = ::jace::helper::attach();
      ::jace::helper::deleteGlobalRef( env, parent );
    }
    catch ( std::exception& e ) {
      #ifdef JACE_UNUSED_LOCAL_VAR
        e; // shut up the compiler
      #endif
    }
  }

  if ( parentClass ) {
    try {
      JNIEnv* env = ::jace::helper::attach();
      ::jace::helper::deleteGlobalRef( env, parentClass );
    }
    catch ( std::exception& e ) {
      #ifdef JACE_UNUSED_LOCAL_VAR
        e; // shut up the compiler
      #endif
    }
  }
}

/**
 * If someone assigns to this proxy, they're really assigning
 * to the field.
 *
 */
FieldType& operator=( const FieldType& field ) {

  if ( parent ) {
    setJavaJniObject( JFieldProxyHelper::assign( field, parent, fieldID, FieldType::staticGetJavaJniClass() ) );
  }
  else {
    setJavaJniObject( JFieldProxyHelper::assign( field, parentClass, fieldID, FieldType::staticGetJavaJniClass() ) );
  }

  return *this;
}

    private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;

};

// ---------------------------------------------------------
// Template specializations for the JFieldProxy class.
// ---------------------------------------------------------

template <> class JFieldProxy<JBoolean> : public JBoolean {
public:
    JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
    JFieldProxy( jfieldID fieldID_, jvalue value, jclass parent_ );
    JFieldProxy( const JFieldProxy<JBoolean>& object );
    JBoolean& operator=( const JBoolean& type );
private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;
};

template <> class JFieldProxy<JByte> : public JByte {
public:
    JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
    JFieldProxy( jfieldID fieldID_, jvalue value, jclass parent_ );
    JFieldProxy( const JFieldProxy<JByte>& object );
    JByte& operator=( const JByte& type );
private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;
};

template <> class JFieldProxy<JChar> : public JChar {
public:
    JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
    JFieldProxy( jfieldID fieldID_, jvalue value, jclass parent_ );
    JFieldProxy( const JFieldProxy<JChar>& object );
    JChar& operator=( const JChar& type );
private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;
};

template <> class JFieldProxy<JShort> : public JShort {
public:
    JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
    JFieldProxy( jfieldID fieldID_, jvalue value, jclass parent_ );
    JFieldProxy( const JFieldProxy<JShort>& object );
    JShort& operator=( const JShort& type );
private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;
};

template <> class JFieldProxy<JInt> : public JInt {
public:
    JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
    JFieldProxy( jfieldID fieldID_, jvalue value, jclass parent_ );
    JFieldProxy( const JFieldProxy<JInt>& object );
    JInt& operator=( const JInt& type );
private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;
};

template <> class JFieldProxy<JLong> : public JLong {
public:
    JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
    JFieldProxy( jfieldID fieldID_, jvalue value, jclass parent_ );
    JFieldProxy( const JFieldProxy<JLong>& object );
    JLong& operator=( const JLong& type );
private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;
};

template <> class JFieldProxy<JFloat> : public JFloat {
public:
    JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
    JFieldProxy( jfieldID fieldID_, jvalue value, jclass parent_ );
    JFieldProxy( const JFieldProxy<JFloat>& object );
    JFloat& operator=( const JFloat& type );
private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;
};

template <> class JFieldProxy<JDouble> : JDouble {
public:
    JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
    JFieldProxy( jfieldID fieldID_, jvalue value, jclass parent_ );
    JFieldProxy( const JFieldProxy<JDouble>& object );
    JDouble& operator=( const JDouble& type );
private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;
};

}
#endif // #ifndef JACE_JFIELD_PROXY_H

