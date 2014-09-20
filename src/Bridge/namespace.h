/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This file contains Doxygen comments for all namespaces in this subproject.
 * As such, it serves no purpose to include this header anywhere.
 */

/**
 * \namespace rs
 * \brief contains the standard RS classes
 *
 * This namespace contains all classes that are directly mapped to classes in the Runescape client.
 * These classes are the same as the classes usually found in the api of any injection/reflection
 * bot client. Please note that many of these classes may not be very useful, and other namespaces
 * (like the \c api namespace) may be able to provide more suitable classes.
 *
 * Any of the functions defined in this namespace may throw a jace::MappingUnavailableException upon
 * being invoked. This indicates the required field mapping is not available. This way, plugins can recover
 * from encountering missing bindings, and it allows PowerGrid to remain functional even if not all
 * field hooks can be found by the remote updater.
 */

/**
 * \namespace component
 * \brief contains the Components for the Entity framework
 *
 * This namespace contains all Component types for Entities. These types act as properties for the
 * entities in the Runescape world. Since operations on Entities actually operate on the properties
 * of those Entities, this namespace plays a key role in using the Entity framework.
 */

/**
 * \namespace jace
 * \brief contains the JNI bridge framework
 *
 * This namespace contains functionality to enable smooth interaction with the Java VM. Most of the
 * classes in this namespace are only used by the lower api and core PowerGrid classes. This namespace
 * also contains the classes \c RSClass and \c RSClassMapper, which play a key role in successfully
 * mapping the classes in the Runescape client to C++ classes.
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
 * This namespace contains the proxies for all primitive Java types, including void, but not
 * including \c java.lang.Object (which is contained in the java::lang namespace for analogy with packages
 * in Java).
 */

/**
 * \namespace java
 * \brief replica of the \c java package in Java
 *
 * Most of the classes and methods in this namespace (and namespaces inside the ::java namespace) deliberately
 * have no documentation. This is done to avoid any confusion, the behavior of each of the member functions
 * (apart from the standard JACE functions) is equal to their Java counterparts, unless otherwise mentioned.
 *
 * In particular, due to the nature of JACE proxy classes, if a Java method were to return null,
 * the proxy member function returns a proxy instance for which @c isNull() returns true. Also,
 * in some cases where exceptions are thrown by Java methods, null is returned instead, or different
 * exceptions may be thrown (this is mentioned in the documentation of the method for which it applies).
 *
 * Additionally, almost all proxy methods may throw a @c jace::JNIException when an error occurs in the JNI layer.
 * This could mean that required classes, methods or fields do not exist in the JVM.
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
