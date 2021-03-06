#ifndef JACE_JARRAY_H
#define JACE_JARRAY_H

#include "jace/os_dep.h"

#include "jace/JNIHelper.h"
#include "jace/JClassImpl.h"
#include "jace/ElementProxy.h"
#include "jace/JNIException.h"

#include "jace/proxy/types/JBoolean.h"
#include "jace/proxy/types/JByte.h"
#include "jace/proxy/types/JChar.h"
#include "jace/proxy/types/JDouble.h"
#include "jace/proxy/types/JFloat.h"
#include "jace/proxy/types/JInt.h"
#include "jace/proxy/types/JLong.h"
#include "jace/proxy/types/JShort.h"

#include <string>
#include <vector>

namespace jace {


/**
 * Represents an array of JValues.
 *
 * A JArray may be constructed with any type that matches
 * the JValue interface. JArrays act like any other array.
 * For example:
 *
 *   // Creates an empty array of type String of size 10.
 *   JArray<String> myArray( 10 );
 *
 *   // Sets the 3rd element to the String, "Hello World".
 *   myArray[ 3 ] = String( "Hello World" );
 *
 *   // Retrieves the String, "Hello World" from the array.
 *   String hw = myArray[ 3 ];
 *
 * @author Toby Reyelts
 *
 */
template <class ElementType> class JArray : public ::jace::proxy::JObject {

public:

/**
 * Constructs a new JArray from the given JNI array.
 *
 */
JArray( jvalue array ) : JObject( 0 ) {
  this->setJavaJniValue( array );
  this->length_ = -1;
}


/**
 * Constructs a new JArray from the given JNI array.
 *
 */
JArray( jobject array ) : JObject( 0 ) {
  this->setJavaJniObject( array );
  this->length_ = -1;
}


/**
 * Constructs a new JArray from the given JNI array.
 *
 */
JArray( jarray array ) : JObject( 0 ) {
  this->setJavaJniObject( array );
  this->length_ = -1;
}


/**
 * Constructs a new JArray of the given size.
 *
 */
JArray( int size ) : JObject( 0 ) {
  JNIEnv* env = ::jace::helper::attach();
  jarray localRef = env->NewObjectArray(size, ElementType::staticGetJavaJniClass()->GetClass(), NULL);
  this->setJavaJniObject( localRef );
  env->DeleteLocalRef( localRef );
  length_ = size;
}


/**
 * Creates a new JArray from a vector of a convertible type, T.
 *
 */
template <class T> JArray( const std::vector<T>& values ) : JObject( 0 ) {
  JNIEnv* env = ::jace::helper::attach();
  jobjectArray localArray = env->NewObjectArray( values.size(), ElementType::staticGetJavaJniClass()->getClass(), NULL);
  this->setJavaJniObject( localArray );

  int i = 0;
  for ( typename std::vector<T>::const_iterator it = values.begin(); it != values.end(); ++it, ++i ) {
    env->SetObjectArrayElement( localArray, i, ElementType( *it ).getJavaJniObject() );
    helper::catchAndThrow();
  }

  length_ = values.size();

  env->DeleteLocalRef( localArray );
}

JArray( const JArray& array ) : JObject( 0 ) {
  this->setJavaJniObject( array.getJavaJniObject() );
  this->length_ = array.length_;
}

/**
 * Destroys this JArray.
 *
 */
~JArray() throw () {}

/**
 * Retrieves the length of the array.
 *
 */
::jace::proxy::types::JInt length() const {

  #ifdef JACE_CHECK_NULLS
    if ( ! this->getJavaJniObject() ) {
      throw JNIException( "[JArray::length] Can not retrieve the length of a null array." );
    }
  #endif

  if ( length_ == -1 ) {
    length_ = helper::attach()->GetArrayLength( this->getJavaJniArray() );
  }

  return length_;
}


/**
 * Retrieves the element at the given index of the array.
 *
 * @throw JNIException if the index
 * is outside of the range of the array.
 */
ElementType operator[]( const int& index ) const {

  #ifdef JACE_CHECK_NULLS
    if ( ! this->getJavaJniObject() ) {
      throw ::jace::JNIException( "[JArray::operator[]] Can not dereference a null array." );
    }
  #endif

  #ifdef JACE_CHECK_ARRAYS
    if ( index >= length() ) {
      throw ::jace::JNIException( "[JArray::operator[]] invalid array index." );
    }
  #endif
  JNIEnv* env = helper::attach();
  jvalue localElementRef;
  localElementRef.l = env->GetObjectArrayElement(static_cast<jobjectArray>(getJavaJniObject()), index);
  ElementType element( localElementRef );
  env->DeleteLocalRef( localElementRef.l );
  return element;
}

/**
 * Returns the JClass for this instance.
 *
 * @throw JNIException if an error occurs while trying to retrieve the class.
 *
 */
virtual const ::jace::JClass* getJavaJniClass() const throw ( ::jace::JNIException ) {
  return JArray<ElementType>::staticGetJavaJniClass();
}


/**
 * Returns the JClass for this class.
 *
 * @throw JNIException if an error occurs while trying to retrieve the class.
 *
 */
static const ::jace::JClass* staticGetJavaJniClass() throw ( JNIException ) {

  static const std::string nameAsType = "[" + ElementType::staticGetJavaJniClass()->getNameAsType();
	// Aparently there is a bug in the JNI docs and arrays require the L...; around objects
  static const std::string name = nameAsType;
  static ::jace::JClassImpl javaClass( name, nameAsType );

  return &javaClass;
}


/**
 * Returns the JNI jarray handle for this array.
 *
 */
jarray getJavaJniArray() const {
  return static_cast<jarray>( this->getJavaJniObject() );
}

/**
 * Part of the integration between JACE and Qt.
 * Copies the references / values in this JArray to a QList.
 */
QList<ElementType> toQList() const {
    QList<ElementType> list;
    for (int i=0; i<length(); i++) {
        list << this->operator [](i);
    }
    return list;
}

/**
 * An Iterator class for use with the standard C++ library. For
 * example you can use stl::copy() to copy the contents of a JArray:
 *
 * <code>
 * JArray<JBoolean> javaArray = ...;
 * jboolean* nativeArray = new jboolean[ javaArray.size() ];
 * 
 * std::copy( myArray.begin(), myArray.end(), nativeArray );
 * </code>
 *
 * Iterator should be preferred to operator[] for non-random
 * access of arrays, as it allows Jace to perform smart caching
 * against the array accesses.
 *
 * Note that an Iterator is only good for as long as it's parent
 * is alive. Accessing an Iterator after the destruction of the
 * parent array causes undefined behavior.
 *
 */
class Iterator : public std::iterator<std::random_access_iterator_tag, ElementType> {

  private:

  JArray<ElementType>* parent;
  int current;
  int end;

  public:

  Iterator( JArray<ElementType>* parent_, int begin_, int end_ ) :
    parent( parent_ ),
    current( begin_ ),
    end( end_ ) {

    #ifdef JACE_CHECK_ARRAYS
      if ( begin_ < 0 || begin_ > parent->length() ) {
        throw ::jace::JNIException( "[JArray::Iterator::Iterator] begin is out of bounds." );
      }
      if ( ( end_ < begin_ && end_ != -1 ) || end > parent->length() ) {
        throw ::jace::JNIException( "[JArray::Iterator::Iterator] end is out of bounds." );
      }
    #endif

    parent->cache( current, end );
  }

  Iterator( const Iterator& it ) :
    parent( it.parent ),
    current( it.current ),
    end( it.end ) {
  }

  ~Iterator() {
    parent->release( current, end );
  }

  Iterator operator=( const Iterator& it ) {
    parent = it.parent;
    current = it.current;
    end = it.end;
    return *this;
  }

  bool operator==( const Iterator& it ) {
    return ( parent == it.parent && current == it.current );
  }

  bool operator!=( const Iterator& it ) {
    return ! ( *this == it );
  }

  bool operator<( const Iterator& it ) {
    return ( parent == it.parent && current < it.current );
  }

  bool operator<=( const Iterator& it ) {
    return ( parent == it.parent && current <= it.current );
  }

  bool operator>( const Iterator& it ) {
    return ( parent == it.parent && current > it.current );
  }

  bool operator>=( const Iterator& it ) {
    return ( parent == it.parent && current >= it.current );
  }

  // pre
  Iterator operator++() {

    #ifdef JACE_CHECK_ARRAYS
      if ( current >= parent->length() ) {
        throw ::jace::JNIException( "[JArray::Iterator::operator++] can not advance iterator out of bounds." );
      }
    #endif

    ++current;
    return *this;
  }

  // post
  Iterator operator++( int ) {

    #ifdef JACE_CHECK_ARRAYS
      if ( current >= parent->length() ) {
        throw ::jace::JNIException( "[JArray::Iterator::operator++] can not advance iterator out of bounds." );
      }
    #endif

    Iterator it( *this );
    ++current;

    return it;
  }

  Iterator operator+=( int i ) {

    #ifdef JACE_CHECK_ARRAYS
      if ( current + i > parent->length() ) {
        throw ::jace::JNIException( "[JArray::Iterator::operator+=] can not advance iterator out of bounds." );
      }
    #endif

    current += i;
    return *this;
  }

  // pre
  Iterator operator--() {

    #ifdef JACE_CHECK_ARRAYS
      if ( current == 0 ) {
        throw ::jace::JNIException( "[JArray::Iterator::operator--] can not rewind iterator out of bounds." );
      }
    #endif

    --current;
    return *this;
  }

  // post
  Iterator operator--( int ) {

    #ifdef JACE_CHECK_ARRAYS
      if ( current == 0 ) {
        throw ::jace::JNIException( "[JArray::Iterator::operator--] can not rewind iterator out of bounds." );
      }
    #endif

    Iterator it( *this );
    --current;

    return it;
  }

  Iterator operator-=( int i ) {

    #ifdef JACE_CHECK_ARRAYS
      if ( current - i < 0 ) {
        throw ::jace::JNIException( "[JArray::Iterator::operator-=] can not rewind iterator out of bounds." );
      }
    #endif

    current -= i;
    return *this;
  }

  Iterator operator+( int i ) {

    #ifdef JACE_CHECK_ARRAYS
      if ( current + i > parent->length() ) {
        throw ::jace::JNIException( "[JArray::Iterator::operator+] can not advance iterator out of bounds." );
      }
    #endif

    Iterator it( *this );
    it.current += i;
    return it;
  }

  Iterator operator-( int i ) {

    #ifdef JACE_CHECK_ARRAYS
      if ( current - i < 0 ) {
        throw ::jace::JNIException( "[JArray::Iterator::operator-] can not rewind iterator out of bounds." );
      }
    #endif

    Iterator it( *this );
    it.current -= i;
    return it;
  }

	operator int()
	{
		return current;
	}

	/**
   * Returns the element to which the Iterator points.
   *
   */
  ElementType operator*() {

    #ifdef JACE_CHECK_ARRAYS
      if ( current < 0 || current >= parent->length() ) {
        throw ::jace::JNIException( "[JArray::Iterator::operator*] can not dereference an out of bounds iterator." );
      }
    #endif

    // Change to use caching in the future
    return parent->operator[]( current );
  }
};

/**
 * Returns an Iterator to the array at position, <code>start</code>
 *
 * @param start The position at which to place the iterator.
 * @param end The position to which you are likely to iterate to.
 * This should be equal to or larger than start, or may be set to -1
 * to indicate the end of the array.
 *
 */
Iterator begin( int start = 0, int end = -1 ) {
  return Iterator( this, start, end );
}

/**
 * Returns an Iterator at one past the end of the array.
 * This Iterator should not be dereferenced.
 *
 */
Iterator end() {
  return Iterator( this, length(), length() );
}

private:

/**
 * Disallow operator= for now.
 *
 */
bool operator=( const JArray& array );

/**
 * Disallow operator== for now.
 *
 */
bool operator==( const JArray& array );

// The cached length of the array.
// Mutable, because it's calculation can be deferred.
mutable int length_;

// Methods for future implementation of caching
void cache( int, int ) {
}

void release( int, int ) {
}

void setElement( ElementType&, int ) {
}

friend class Iterator;

}; // class JArray

#define JArrayTemplate(Type) \
template <> class JArray<Type> : public jace::proxy::JObject { \
private: \
    bool operator=(const JArray& array) { Q_UNUSED(array); return false; }\
    bool operator==(const JArray& array) { Q_UNUSED(array); return false; }\
public: \
    explicit JArray(jvalue val); \
    explicit JArray(jobject obj); \
    Type operator[] (const int &index) const; \
    QList<Type> toQList() const;\
    jarray getJavaJniArray() const;\
    jsize length() const; \
    virtual const JClass* getJavaJniClass() const throw (JNIException); \
    static const JClass* staticGetJavaJniClass() throw (JNIException); \
}; \

JArrayTemplate(JBoolean)
JArrayTemplate(JByte)
JArrayTemplate(JChar)
JArrayTemplate(JDouble)
JArrayTemplate(JFloat)
JArrayTemplate(JInt)
JArrayTemplate(JShort)
JArrayTemplate(JLong)

#undef JArrayTemplate

}

#endif // #ifndef JACE_JARRAY_H

