#ifndef JACE_JCLASS_IMPL_H
#define JACE_JCLASS_IMPL_H

#include "jace/os_dep.h"
#include "jace/JClass.h"
#include "jace/JNIException.h"

#include <string>

namespace jace {

/**
 * The implementation of the JClass interface.
 *
 * @author Toby Reyelts
 *
 */
class JClassImpl : public JClass {
public:

/**
 * Creates a new JClassImpl with the given name, and 
 * type name.
 *
 * @param name - The name of this class, suitable for use
 * in a call to JNIEnv::FindClass.
 *
 * For example, "java/lang/Object"
 *
 * @param nameAsType The name of this class as a type, 
 * suitable for use in a call to JNIEnv::GetMethodID.
 *
 * For example, "Ljava/lang/Object;"
 *
 * @param cls - the jclass reference, default @c NULL. If this is
 *      @c NULL, the jclass will be loaded as required by the JVM.
 *      Otherwise, the provided @c jclass is used.
 *
 */
JACE_API JClassImpl(const std::string name, const std::string nameAsType , jclass cls = NULL);

/**
 * Creates a new JClassImpl with the given name.
 *
 * @param name - The name of the class, suitable for use
 * in a call to JNIEnv::FindClass.
 *
 * For example, "java/lang/Object".
 *
 * ------------------------------------------------------
 *
 * The type name for the class is created by preprending
 * "L" and appending ";" to name.
 *
 * For example,
 *
 *  JClassImpl( "java/lang/String" );
 *
 * is equivalent to
 *
 *  JClassImpl( "java/lang/String", "Ljava/lang/String;" );
 *
 * @param cls - the jclass reference, default @c NULL. If this is
 *      @c NULL, the jclass will be loaded as required by the JVM.
 *      Otherwise, the provided @c jclass is used.
 *
 */
JACE_API JClassImpl(const std::string name , jclass cls = NULL);

/**
 * Destroys this JClassImpl.
 *
 */
JACE_API virtual ~JClassImpl() throw ();

/**
 * Returns the name of this class. suitable for use in a call to
 * JNIEnv::FindClass.
 *
 * For example, "java/lang/Object".
 *
 */
JACE_API virtual const std::string& getName() const;


/**
 * Returns the name of this class as a type, suitable for use
 * in a call to JNIEnv::GetMethodID.
 *
 * For example, "Ljava/lang/Object;".
 *
 */
JACE_API virtual const std::string& getNameAsType() const;


/**
 * Returns the JNI representation of this class.
 *
 */
JACE_API virtual jclass getClass() const throw ( jace::JNIException );


/**
 * Creates a duplicate instance of this JClass.
 *
 */
JACE_API virtual std::unique_ptr<JClass> clone() const;


private:

std::string mName;
std::string mNameAsType;
mutable jclass mClass;

};

}

#endif
