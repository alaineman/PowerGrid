#ifndef JACE_JFACTORY_H
#define JACE_JFACTORY_H

#include "jace/os_dep.h"

#include <jni.h>

#include <memory>

namespace jace {
 namespace proxy {
  class JValue;
 }
 class JClass;

/**
 * An interface for a factory that creates new instances
 * of a specific JValue subclass.
 *
 * @author Toby Reyelts
 *
 */
class JFactory {

public:

/**
 * Creates a new instance of the value type
 * for this JFactory.
 *
 */
JACE_API virtual ::jace::proxy::JValue* create( jvalue val ) = 0;


/**
 * Creates a new instance of the value type for this JFactory
 * and throws that instance.
 *
 * This method is equivalent to 
 *
 *   throw * ( JFactory::create( aValue ) ).get();
 *
 * except that the return value's real type is preserved and 
 * not sliced to a JValue upon being thrown.
 *
 */
JACE_API virtual void throwInstance( jvalue val ) = 0;

/**
 * Returns the class of which this factory
 * creates instances.
 *
 */
JACE_API virtual const ::jace::JClass* getClass() = 0;

/**
 * Destroys this JFactory.
 *
 */
JACE_API virtual ~JFactory();

};

}

#endif // #ifndef JACE_JFACTORY_H


