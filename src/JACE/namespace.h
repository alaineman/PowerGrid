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
 */

/**
 * \namespace api
 * \brief contains all API classes
 *
 * This namespace contains all classes that provide access to the Runescape data. It is divided into
 * various namespaces that contain different representations of the Runescape client data.
 *
 */

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
