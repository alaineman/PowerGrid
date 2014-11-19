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
#ifndef NET_PGRID_LOADER_PGLOADER_H
#define NET_PGRID_LOADER_PGLOADER_H

#include "jace/JNIException.h"
using jace::JNIException;

#include "java/lang/object.h"
using namespace java::lang;

#include "java/awt/component.h"
using java::awt::Component;

#include <initializer_list>
using std::initializer_list;

namespace net {
namespace pgrid {
namespace loader {

class PGLoader : public Object {
public:
    static Component getApplet();

    PGLoader();
    PGLoader(const PGLoader& obj);

    virtual const jace::JClass* getJavaJniClass() const throw (JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (JNIException);

    explicit PGLoader(jvalue value);
    explicit PGLoader(jobject object);
    PGLoader& operator = (const PGLoader& obj);

    /**
     * @brief Calls the main method of the Java Loader.
     *
     * This method is deliberately not called @c main, to avoid confusion with
     * the main method of the native client.
     *
     * @param args - The command-line arguments to provide to the Java loader.
     * @throws jace::JNIException - When an Exception occurs in the JVM.
     */
    static void start(const std::initializer_list<QString> args) throw (JNIException);

    /**
     * @brief Computes the hash of the Runescape Java client.
     *
     * @return the computed hash
     * @throws jace::JNIException - When an I/O error occurs, or an unexpected
     *                              Exception occurs in the JVM.
     */
    static jint computeClientHash() throw (JNIException);

    /**
     * @brief Tries to find a Class in the JVM with the given name.
     *
     * @param name - The (obfuscated) name of the desired Class.
     * @return A Class object with the given name.
     */
    static Class findClass(QString name) throw (JNIException);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace loader
} // namespace pgrid
} // namespace net

#endif // NET_PGRID_LOADER_PGLOADER_H
