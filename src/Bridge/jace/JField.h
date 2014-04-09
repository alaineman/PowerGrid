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
    jfieldID getFieldID(const JClass* parentClass, bool isStatic = false) {
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
    virtual Type get(proxy::JObject& obj) = 0;
    /**
     * \brief Returns the (static) field's value
     * \param cls the class that defines the field
     * \return the value of the field
     */
    virtual Type get(const JClass* cls) = 0;
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
    virtual Type get(jace::proxy::JObject& obj) {
        jfieldID fieldID = this->getFieldID( obj.getJavaJniClass() );
        JNIEnv* env = helper::attach();
        jobject res = env->GetObjectField(obj.getJavaJniObject(), fieldID);
        helper::catchAndThrow();
        return Type(res);
    }
    virtual Type get(const JClass *cls) {
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
    virtual JBoolean get(proxy::JObject& obj);
    virtual JBoolean get(const JClass *cls);
};

template <> class JField<JByte> : public JFieldBase<JByte> {
public:
    JField(const std::string& name);
    virtual JByte get(proxy::JObject& obj);
    virtual JByte get(const JClass *cls);
};

template <> class JField<JChar> : public JFieldBase<JChar> {
public:
    JField(const std::string& name);
    virtual JChar get(proxy::JObject& obj);
    virtual JChar get(const JClass *cls);
};

template <> class JField<JShort> : public JFieldBase<JShort> {
public:
    JField(const std::string& name);
    virtual JShort get(proxy::JObject& obj);
    virtual JShort get(const JClass *cls);
};

template <> class JField<JInt> : public JFieldBase<JInt> {
public:
    JField(const std::string& name);
    virtual JInt get(proxy::JObject& obj);
    virtual JInt get(const JClass *cls);
};

template <> class JField<JLong> : public JFieldBase<JLong> {
public:
    JField(const std::string& name);
    virtual JLong get(proxy::JObject& obj);
    virtual JLong get(const JClass *cls);
};

template <> class JField<JDouble> : public JFieldBase<JDouble> {
public:
    JField(const std::string& name);
    virtual JDouble get(proxy::JObject& obj);
    virtual JDouble get(const JClass *cls);
};

template <> class JField<JFloat> : public JFieldBase<JFloat> {
public:
    JField(const std::string& name);
    virtual JFloat get(proxy::JObject& obj);
    virtual JFloat get(const JClass *cls);
};

}

#endif

