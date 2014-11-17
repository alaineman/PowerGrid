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

#include "java/lang/object.h"
using namespace java::lang;

#include "java/awt/component.h"
using java::awt::Component;

namespace net {
namespace pgrid {
namespace loader {

class PGLoader : public Object {
public:
    static Component getApplet();

    PGLoader();
    PGLoader(const PGLoader& obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit PGLoader(jvalue value);
    explicit PGLoader(jobject object);
    PGLoader& operator = (const PGLoader& obj);

    /**
     * @brief Calls the main method of the Java Loader.
     *
     * This method is deliberately not called @c main, to avoid confusion with
     * the main method of the native client.
     *
     * @throws jace::JNIException - When an Exception occurs in the JVM.
     */
    static void start() throw (jace::JNIException);

private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace loader
} // namespace pgrid
} // namespace net

#endif // NET_PGRID_LOADER_PGLOADER_H
