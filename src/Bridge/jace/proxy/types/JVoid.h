#ifndef JACE_TYPES_JVOID
#define JACE_TYPES_JVOID

#include "jace/os_dep.h"
#include "jace/JClass.h"
#include "jace/proxy/JValue.h"
#include "jace/JNIException.h"

namespace jace {
namespace proxy {
namespace types {

/**
 * A class representing the java primitive type, void.
 *
 * @author Toby Reyelts
 *
 */
class JACE_API JVoid : public JValue {
public:

/**
 * Returns the JClass for the Void type.
 *
 * @throw JNIException if an error occurs while trying to retrieve the class.
 *
 */
virtual const JClass* getJavaJniClass() const throw (JNIException );


/**
 * Returns the JClass for the Void type.
 *
 * @throw JNIException if an error occurs while trying to retrieve the class.
 *
 */
static const JClass* staticGetJavaJniClass() throw (JNIException );

};

}
}
}

#endif // #ifndef JACE_TYPES_JVOID


