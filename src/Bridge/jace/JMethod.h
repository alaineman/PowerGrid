#ifndef JACE_JMETHOD_H
#define JACE_JMETHOD_H
#include "jace/os_dep.h"
#include "jace/JClass.h"
#include "jace/proxy/JObject.h"
#include "jace/proxy/JValue.h"
#include "jace/JArguments.h"
#include "jace/JNIException.h"
#include "jace/JSignature.h"

#include "jace/proxy/types/JBoolean.h"
#include "jace/proxy/types/JByte.h"
#include "jace/proxy/types/JChar.h"
#include "jace/proxy/types/JDouble.h"
#include "jace/proxy/types/JFloat.h"
#include "jace/proxy/types/JInt.h"
#include "jace/proxy/types/JLong.h"
#include "jace/proxy/types/JShort.h"
#include "jace/proxy/types/JVoid.h"

#include <jni.h>
#include <string>
#include <vector>
#include <list>

namespace jace {

/**
 * Transforms a JArguments to a vector of jvalue's.
 */
JACE_API std::vector<jvalue> toVector( const JArguments& arguments );

/**
 * Represents a java method.
 *
 * @author Toby Reyelts
 *
 */
template <class ResultType> class JMethod {


public:


/**
 * Creates a new JMethod representing the method with the
 * given name, belonging to the given class.
 *
 */
JMethod( const std::string& name ) : mName( name ), mMethodID( 0 ) {
}

/**
 * Invokes the method with the given arguments.
 * The method is invoked on the supplied object.
 *
 * @throws JNIException if an error occurs while trying to invoke the method.
 * @throws a matching C++ proxy, if a java exception is thrown by the method.
 *
 */
ResultType invoke( const ::jace::proxy::JObject& object, const JArguments& arguments ) {

  #ifdef JACE_CHECK_NULLS
    if ( object.isNull() ) {
      throw JNIException( "[JMethod.invoke] Can not invoke an instance method on a null object." );
    }
  #endif

  /* Get the methodID for the method matching the given arguments.
   */
  jmethodID methodID = getMethodID( object.getJavaJniClass(), arguments );

  /* Call the method.
   */
  JNIEnv* env = helper::attach();
  jobject resultRef;

	if ( arguments.asList().size() > 0 )
		resultRef = env->CallObjectMethodA( object.getJavaJniObject(), methodID, &toVector( arguments )[ 0 ] );
	else
		resultRef = env->CallObjectMethod( object.getJavaJniObject(), methodID );

  /* Catch any java exception that occured during the method call,
   * and throw it as a C++ exception.
   */
  helper::catchAndThrow();

  ResultType result( resultRef );
  helper::deleteLocalRef( env, resultRef );

  return result;
}


/**
 * Invokes the method with the given arguments.
 * The method is invoked statically, on the supplied class.
 *
 * @throws JNIException if an error occurs while trying to invoke the method.
 * @throws a matching C++ proxy, if a java exception is thrown by the method.
 *
 */
ResultType invoke( const JClass* jClass, const JArguments& arguments ) {

  /* Get the methodID for the method matching the given arguments.
   */
  jmethodID methodID = getMethodID( jClass, arguments, true );

  /* Call the method.
   */
  JNIEnv* env = helper::attach();
  jobject resultRef;

	if ( arguments.asList().size() > 0 )
		resultRef = env->CallStaticObjectMethodA( jClass->getClass(), methodID, &toVector( arguments )[ 0 ] );
	else
		resultRef = env->CallStaticObjectMethod( jClass->getClass(), methodID );

  /* Catch any java exception that occured during the method call,
   * and throw it as a C++ exception.
   */
  helper::catchAndThrow();

  ResultType result( resultRef );
  helper::deleteLocalRef( env, resultRef );

  return result;
}


// private:

/**
 * Returns the jmethodID matching the signature for the given arguments.
 *
 */
jmethodID getMethodID( const JClass* jClass, const JArguments& arguments, bool isStatic = false ) {

  /* We cache the jmethodID locally, so if we've already found it,
   * we don't need to go looking for it again.
   */
  if ( mMethodID ) {
    return mMethodID;
  }

  /* If we don't already have the jmethodID, we need to determine
   * the signature of this method.
   */
  JSignature signature( *ResultType::staticGetJavaJniClass() );
  typedef std::list< ::jace::proxy::JValue* > ValueList;
  ValueList args = arguments.asList();

  ValueList::iterator i = args.begin();
  ValueList::iterator end = args.end();

  for ( ; i != end; ++i ) {
    ::jace::proxy::JValue* value = *i;
    signature << *value->getJavaJniClass();
  }

  std::string methodSignature = signature.toString();

  /* Now that we have the signature for the method, we could look
   * in a global cache for the jmethodID corresponding to this method,
   * but for now, we'll always find it.
   */
  JNIEnv* env = helper::attach();

  if ( isStatic ) {
    mMethodID = env->GetStaticMethodID( jClass->getClass(), mName.c_str(), methodSignature.c_str() );
  }
  else {
    mMethodID = env->GetMethodID( jClass->getClass(), mName.c_str(), methodSignature.c_str() );
  }

  if ( mMethodID == 0 ) {
    std::string msg = "JMethod::getMethodID\n" \
                 "Unable to find method <" + mName + "> with signature <" + methodSignature + ">";
		try
		{
			helper::catchAndThrow();
		}
		catch (JNIException e)
		{
			msg.append("\ncaused by:\n");
			msg.append(e.what());
		}
    throw JNIException( msg );
  }

//  cout << "JMethod::getMethodID() - Found the method:" << endl;
//  cout << "  <" << mName << "> with signature <" << methodSignature << "> for " << jClass->getName() << endl;

  return mMethodID;
}


std::string mName;
jmethodID mMethodID;

};

}

/**
 * For those (oddball) compilers that need the template specialization
 * definitions in the header.
 */
#ifdef PUT_TSDS_IN_HEADER
  #include "jace/JMethod.tsd"
#else
  #include "jace/JMethod.tsp"
#endif

#endif // #ifndef JACE_JMETHOD_H


