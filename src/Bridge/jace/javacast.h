#ifndef JACE_JAVACAST_H
#define JACE_JAVACAST_H

#include "jace/proxy/JObject.h"
#include "jace/JClass.h"
#include "jace/JNIHelper.h"

#include <string>

namespace jace {

/**
 * Equal to Java's instanceof keyword.
 * Returns true if obj is non-null and can be cast to type T.
 *
 * For example,
 *
 *  Object stringAsObject = String( "Hello" );
 *
 *  if ( instanceof<String>( stringAsObject ) ) {
 *    String str = java_cast<String>( stringAsObject );
 *  }
 *
 */
template <typename T> bool instanceof(jobject object ) {
    if ( object == NULL ) {
        return false;
    }
    const jace::JClass* resultClass = T::staticGetJavaJniClass();
    bool isValid = jace::helper::attach()->IsInstanceOf(object, resultClass->getClass());
    JNI_CHECK_AND_THROW("Failed to invoke instanceof operator");
    return isValid;
}

/**
 * Performs a safe cast from one JObject subclass to another.
 *
 * For example,
 *
 *  Object stringAsObject = String( "Hello" );
 *  String string = java_cast<String>( stringAsObject );
 *
 * @throws JNIException if obj is not convertible to type T.
 *
 */
template <typename T> T java_cast( const ::jace::proxy::JObject& obj ) {
    return java_cast<T>( obj.getJavaJniObject() );
}


/**
 * @brief Performs a safe cast from a jobject to a JObject subclass.
 *
 * For example,
 *
 *  foo( jobject jStringRef ) {
 *    String str = java_cast<String>( jStringRef );
 *  }
 *
 * @param obj - The jobject to cast.
 * @throws JNIException if obj is not convertible to type T.
 */
template <typename T> T java_cast( jobject obj ) {
    if (obj == NULL || instanceof<T>(obj)) {
        return T( obj );
    } else {
        const jace::JClass* resultType = T::staticGetJavaJniClass();
        throw JNIException("Cannot cast to " + resultType->getName());
    }
}

/**
 * Performs a safe cast from a JObject to a jobject.
 *
 * For example,
 *
 *  Object obj;
 *  jobject jObj = java_cast<jobject>( obj );
 *
 */
template<> jobject java_cast(const jace::proxy::JObject& obj);

}

#endif // #ifndef JACE_JAVACAST_H
