
#ifndef JACE_JCONSTRUCTOR_H
#define JACE_JCONSTRUCTOR_H

#include "jace/os_dep.h"
#include "jace/JClass.h"

namespace jace {

class JArguments;

/**
 * Represents a java constructor.
 *
 *
 * @author Toby Reyelts
 *
 */
class JConstructor {
public:
    /**
     * Creates a new JConstructor for the given JClass.
     *
     */
    JACE_API JConstructor( const JClass* javaClass );

    /**
     * Invokes the constructor with the given JArguments.
     *
     * @throws JNIException if an error occurs while trying to invoke the constructor.
     * @throws a matching C++ proxy, if a java exception is thrown by the constructor.
     *
     */
    JACE_API jobject invoke( const JArguments& arguments );
private:
    /**
     * Gets the method id matching the given arguments.
     */
    jmethodID getMethodID( const JClass* jClass, const JArguments& arguments );

    const JClass* mClass;
    jmethodID mMethodID;
};

}

#endif

