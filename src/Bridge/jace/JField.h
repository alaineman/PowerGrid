#ifndef JACE_JFIELD_H
#define JACE_JFIELD_H

#include "jace/os_dep.h"
#include "jace/JClass.h"
#include "jace/proxy/JObject.h"
#include "jace/JNIException.h"
#include "jace/JFieldProxy.h"
#include "jace/JFieldHelper.h"

#include "jace/proxy/types/JBoolean.h"
#include "jace/proxy/types/JByte.h"
#include "jace/proxy/types/JChar.h"
#include "jace/proxy/types/JDouble.h"
#include "jace/proxy/types/JFloat.h"
#include "jace/proxy/types/JInt.h"
#include "jace/proxy/types/JLong.h"
#include "jace/proxy/types/JShort.h"

#include <jni.h>
#include <string>

namespace jace {

/**
 * \brief Base class for JFields.
 *
 * This class provides functionality shared between all
 * JField template specializations.
 *
 * \author Patrick Kramer
 */
template <class Type> class JFieldBase {
protected:
    std::string fieldName;   ///< The name of the field.
    const JClass* type;      ///< The JClass representing the field type.
    mutable jfieldID id;     ///< The field ID.

    /**
     * \brief Returns the field ID for the provided class
     * \param parentClass the class that contains this field
     * \param isStatic [optional] true if the field is static, false otherwise (default is false)
     * \return the field ID for this field.
     */
    jfieldID getFieldID(const JClass* parentClass, bool isStatic = false) const {
        if (id) {
            return id;
        }
        JNIEnv* env = helper::attach();
        if (isStatic) {
            id = env->GetStaticFieldID(parentClass->getClass(),
                                       fieldName.c_str(), type->getNameAsType().c_str());
        } else {
            id = env->GetFieldID(parentClass->getClass(),
                                 fieldName.c_str(), type->getNameAsType().c_str());
        }
        if ( !id ) {
            std::string msg ("Could not get jfieldID");
            try {
                jace::helper::catchAndThrow();
            } catch (JNIException& e) {
                msg.append(": ").append(e.what());
            }
            throw JNIException(msg);
        }
        return id;
    }
    JFieldBase(const std::string& name) :
        fieldName(name), type(Type::staticGetJavaJniClass()), id(0) {
    }
public:
    /**
     * \brief Creates a new JFieldBase object
     * \param name the name of the field
     */
    virtual ~JFieldBase() throw() {}

    /**
     * \brief Returns the (virtual) field's value
     * \param obj the object to retrieve the field value for
     * \return the value of the field
     */
    virtual Type get(const proxy::JObject& obj) const = 0;
    /**
     * \brief Returns the (static) field's value
     * \param cls the class that defines the field
     * \return the value of the field
     */
    virtual Type get(const JClass* cls) const = 0;
};

/**
 * \brief Represents a java field.
 *
 * \author Toby Reyelts
 */
template <class Type> class JField : public JFieldBase<Type> {
public:
    /**
     * \brief Creates a new JField
     * \param name the name of the field
     */
    JField( const std::string& name ) : JFieldBase<Type>(name) {}
    virtual Type get(const jace::proxy::JObject& obj) const {
        jfieldID fieldID = this->getFieldID( obj.getJavaJniClass() );
        JNIEnv* env = helper::attach();
        jobject res = env->GetObjectField(obj.getJavaJniObject(), fieldID);
        helper::catchAndThrow();
        return Type(res);
    }
    virtual Type get(const JClass *cls) const {
        jfieldID fieldID = this->getFieldID( cls, true );
        JNIEnv* env = helper::attach();
        jobject res = env->GetStaticObjectField(cls->getClass(), fieldID);
        helper::catchAndThrow();
        return Type(res);
    }
};

// Template Specializations
template <> class JField<JBoolean> : public JFieldBase<JBoolean> {
public:
    JField(const std::string& name);
    virtual JBoolean get(const proxy::JObject& obj) const;
    virtual JBoolean get(const JClass *cls) const;
};

template <> class JField<JByte> : public JFieldBase<JByte> {
public:
    JField(const std::string& name);
    virtual JByte get(const proxy::JObject& obj) const;
    virtual JByte get(const JClass *cls) const;
};

template <> class JField<JChar> : public JFieldBase<JChar> {
public:
    JField(const std::string& name);
    virtual JChar get(const proxy::JObject& obj) const;
    virtual JChar get(const JClass *cls) const;
};

template <> class JField<JShort> : public JFieldBase<JShort> {
public:
    JField(const std::string& name);
    virtual JShort get(const proxy::JObject& obj) const;
    virtual JShort get(const JClass *cls) const;
};

template <> class JField<JInt> : public JFieldBase<JInt> {
public:
    JField(const std::string& name);
    virtual JInt get(const proxy::JObject& obj) const;
    virtual JInt get(const JClass *cls) const;
};

template <> class JField<JLong> : public JFieldBase<JLong> {
public:
    JField(const std::string& name);
    virtual JLong get(const proxy::JObject& obj) const;
    virtual JLong get(const JClass *cls) const;
};

template <> class JField<JDouble> : public JFieldBase<JDouble> {
public:
    JField(const std::string& name);
    virtual JDouble get(const proxy::JObject& obj) const;
    virtual JDouble get(const JClass *cls) const;
};

template <> class JField<JFloat> : public JFieldBase<JFloat> {
public:
    JField(const std::string& name);
    virtual JFloat get(const proxy::JObject& obj) const;
    virtual JFloat get(const JClass *cls) const;
};

}

#endif

