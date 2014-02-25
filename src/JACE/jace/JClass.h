#ifndef JACE_JCLASS_H
#define JACE_JCLASS_H

#include "jace/os_dep.h"
#include "jace/JNIException.h"

#include <jni.h>

#include <string>
#include <memory>

namespace jace {

/**
 * An interface that represents a java class.
 *
 * @author Toby Reyelts
 */
class JClass {
public:
/**
 * Destroys this JClass.
 *
 */
JACE_API virtual ~JClass() {}

/**
 * Returns the name of this class. suitable for use in a call to
 * JNIEnv::FindClass.
 *
 * For example, "java/lang/Object".
 *
 */
JACE_API virtual const std::string& getName() const = 0;


/**
 * Returns the name of this class as a type, suitable for use
 * in a call to JNIEnv::GetMethodID.
 *
 * For example, "Ljava/lang/Object;".
 *
 */
JACE_API virtual const std::string& getNameAsType() const = 0;


/**
 * Returns the JNI representation of this class.
 *
 */
JACE_API virtual jclass getClass() const throw ( JNIException ) = 0;


/**
 * Creates a duplicate instance of this JClass.
 *
 */
JACE_API virtual std::auto_ptr<JClass> clone() const = 0;

};

}

#endif
