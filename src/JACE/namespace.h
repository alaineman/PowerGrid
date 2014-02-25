/**
 * \namespace api::bridge
 * \brief contains the standard RS classes
 *
 * This namespace contains all classes that are directly mapped to classes in the Runescape client.
 * These classes are the same as the classes usually found in the api of any injection/reflection
 * bot client. Please note that many of these classes may not be very useful, and other namespaces
 * in the \c api namespace may be able to provide more suitable classes.
 */

/**
 * \namespace jace
 * \brief contains JNI bridge framework
 *
 * This namespace contains functionality to enable smooth interaction with the Java VM. Most of the
 * classes in this namespace are only used by the lower api and core PowerGrid classes.
 */

/**
 * \namespace jace::proxy
 * \brief contains basic JACE proxy classes
 *
 * This namespace contains proxies for all basic Java types, like \c JInt and \c JByte, but also the
 * base class of all object types, \c JObject, and even the proxy for any Java value, \c JValue. These
 * classes are automatically included by all proxy classes, so including them seperately is almost never required.
 */

/**
 * \namespace jace::proxy::types
 * \brief contains proxies for primitive Java types
 *
 * This namespace contains the proxies for all primitive Java types, including void.
 */

/**
 * \namespace java
 * \brief replica of the \c java package in Java
 */

/**
 * \namespace java::awt
 * \brief replica of the \c java.awt package in Java
 */

/**
 * \namespace java::awt::event
 * \brief replica of the \c java.awt.event package in Java
 */

/**
 * \namespace java::io
 * \brief replica of the \c java.io package in Java
 */

/**
 * \namespace java::lang
 * \brief replica of the \c java.lang package in Java
 */

/**
 * \namespace java::lang::ref
 * \brief replica of the \c java.lang.ref package in Java
 */

/**
 * \namespace java::net
 * \brief replica of the \c java.net package in Java
 */

/**
 * \namespace java::util
 * \brief replica of the \c java.util package in Java
 */

/**
 * \namespace java::util::zip
 * \brief replica of the \c java.util.zip package in Java
 */
