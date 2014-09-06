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

#ifndef OBJECT_H
#define OBJECT_H

#include "jace/os_dep.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JFieldProxy.h"
#include "jace/JField.h"
#include "jace/JClass.h"

namespace java {
namespace lang {

/*!
 * \brief Proxy for \c java.lang.Object
 *
 * This class is the base class of all java classes, and as such also
 * the base class of all proxy classes.
 */
class Object: public virtual jace::proxy::JObject {
public:
    /**
     * \brief Creates a new Object that points to \c null.
     */
    Object();
    /**
     * \brief Copy constructor.
     *
     * Creates a new Object that points to the same Java object as the provided
     * Object.
     * \param obj the original Object
     */
    Object(const Object&obj);
    /**
     * \brief Creates a new Object that points to \c null.
     *
     * This constructor only exists for compatibility with the JACE framework.
     *
     * \param noop Special object indicating this constructor should not
     *        do any initialization.
     */
    Object(const NoOp& noop);

    /*!
     * \brief Returns a JClass* describing the class of this object.
     *
     * The returned JClass* should not be deleted.
     */
    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    /**
     * \brief Returns the JClass object for java/lang/Object.
     */
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    /*!
     * \brief Creates a new Object with the specified jvalue as value.
     * \param val the value of this Object
     */
    explicit Object(jvalue val);
    /*!
     * \brief Creates a new Object with the specified jobject as java object.
     * \param obj the java object of this Object
     */
    Object(jobject obj);

    /*!
     * \brief Assigns the java object of \c obj to this Object.
     * \param obj the Object assigned to this Object
     * \return this Object after the assignment
     */
    Object& operator= (const Object& obj);

    /*!
     * \brief Returns whether this Object is equal to \c obj
     *
     * This operator behaves the same as \c equals, except that
     * this returns true if both objects are null. Simply calling
     * \c equals results in undefined behavior when invoked on a
     * null Object.
     *
     * Additionally, when the objects referenced by this Object
     * and \c obj are in fact the same Object, this returns true
     * without calling the equals method.
     *
     * \param obj the Object to compare with.
     * \return true if these Objects are equal, false otherwise
     */
    bool operator== (const Object& obj);

    /**
     * @brief Checks whether two objects are not equal
     *
     * Invoking `a != b' for Objects a and b behaves exactly the same
     * as `!(a == b)'.
     *
     * @param obj the Object to check with
     * @return true if these Objects are not equal, false if they are
     */
    bool operator!= (const Object& obj);
    /*!
     * \brief Calls this Java Object's \c equals method.
     * This invokes the equals method on the two java objects in the Java VM.
     *
     * \param other the object to call equals with
     * \return true if the two objects are equal according to this
     *         object's equals method, false otherwise
     */
    bool equals(const Object& other) const;
    /*!
     * \brief Calls this Java Object's \c toString method.
     * This invokes the \c toString method on the java object in the Java VM.
     * \return the String value of the java Object, as a JNI jstring.
     */
    jstring toString() const;

    /**
     * @brief Writes the String value of an Object to \c out.
     * @param out the ostream to write to
     * @param object the object to write
     * @return \c out after writing \c object to it.
     */
    friend std::ostream& operator<<(std::ostream& out, Object& object);
private:
    template <typename T> friend T (jace::java_cast)(const ::jace::proxy::JObject&);
};

}
}

#endif // OBJECT_H
