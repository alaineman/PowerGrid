#include "jace/JField.h"

namespace jace {
using jace::proxy::JObject;

// -- Template specializations for primitive types -- //

// JField<JBoolean> specialization
JField<JBoolean>::JField(const std::string &name) : JFieldBase(name) {}

JBoolean JField<JBoolean>::get(JObject& object ) {
    jfieldID fieldID = this->getFieldID( object.getJavaJniClass() );
    JNIEnv* env = helper::attach();
    jboolean result = env->GetBooleanField( object.getJavaJniObject(), fieldID );
    helper::catchAndThrow();
    return JBoolean( result );
}
JBoolean JField<JBoolean>::get(const JClass* cls ) {
    jfieldID fieldID = this->getFieldID( cls, true );
    JNIEnv* env = helper::attach();
    jboolean result = env->GetStaticBooleanField( cls->getClass(), fieldID );
    helper::catchAndThrow();
    return JBoolean( result );
}

// JField<JByte> specialization
JField<JByte>::JField(const std::string &name) : JFieldBase(name) {}

JByte JField<JByte>::get(JObject& object ) {
    jfieldID fieldID = this->getFieldID( object.getJavaJniClass() );
    JNIEnv* env = helper::attach();
    jbyte result = env->GetByteField( object.getJavaJniObject(), fieldID );
    helper::catchAndThrow();
    return JByte( result );
}
JByte JField<JByte>::get(const JClass* cls ) {
    jfieldID fieldID = this->getFieldID( cls, true );
    JNIEnv* env = helper::attach();
    jbyte result = env->GetStaticByteField( cls->getClass(), fieldID );
    helper::catchAndThrow();
    return JByte( result );
}

// JField<JChar> specialization
JField<JChar>::JField(const std::string &name) : JFieldBase(name) {}

JChar JField<JChar>::get(JObject& object ) {
    jfieldID fieldID = this->getFieldID( object.getJavaJniClass() );
    JNIEnv* env = helper::attach();
    JChar result = env->GetCharField( object.getJavaJniObject(), fieldID );
    helper::catchAndThrow();
    return JChar( result );
}
JChar JField<JChar>::get(const JClass* cls ) {
    jfieldID fieldID = this->getFieldID( cls, true );
    JNIEnv* env = helper::attach();
    jchar result = env->GetStaticCharField( cls->getClass(), fieldID );
    helper::catchAndThrow();
    return JChar( result );
}

// JField<JShort> specialization
JField<JShort>::JField(const std::string &name) : JFieldBase(name) {}

JShort JField<JShort>::get(JObject& object ) {
    jfieldID fieldID = this->getFieldID( object.getJavaJniClass() );
    JNIEnv* env = helper::attach();
    jshort result = env->GetShortField( object.getJavaJniObject(), fieldID );
    helper::catchAndThrow();
    return JShort( result );
}
JShort JField<JShort>::get(const JClass* cls ) {
    jfieldID fieldID = this->getFieldID( cls, true );
    JNIEnv* env = helper::attach();
    jshort result = env->GetStaticShortField( cls->getClass(), fieldID );
    helper::catchAndThrow();
    return JShort( result );
}

// JField<JInt> specialization
JField<JInt>::JField(const std::string &name) : JFieldBase(name) {}

JInt JField<JInt>::get(JObject& object ) {
    jfieldID fieldID = this->getFieldID( object.getJavaJniClass() );
    JNIEnv* env = helper::attach();
    jint result = env->GetIntField( object.getJavaJniObject(), fieldID );
    helper::catchAndThrow();
    return JInt( result );
}
JInt JField<JInt>::get(const JClass* cls ) {
    jfieldID fieldID = this->getFieldID( cls, true );
    JNIEnv* env = helper::attach();
    jint result = env->GetStaticIntField( cls->getClass(), fieldID );
    helper::catchAndThrow();
    return JInt( result );
}

// JField<JLong> specialization
JField<JLong>::JField(const std::string &name) : JFieldBase(name) {}

JLong JField<JLong>::get(JObject& object ) {
    jfieldID fieldID = this->getFieldID( object.getJavaJniClass() );
    JNIEnv* env = helper::attach();
    jlong result = env->GetLongField( object.getJavaJniObject(), fieldID );
    helper::catchAndThrow();
    return JLong( result );
}
JLong JField<JLong>::get(const JClass* cls ) {
    jfieldID fieldID = this->getFieldID( cls, true );
    JNIEnv* env = helper::attach();
    jlong result = env->GetStaticLongField( cls->getClass(), fieldID );
    helper::catchAndThrow();
    return JLong( result );
}

// JField<JDouble> specialization
JField<JDouble>::JField(const std::string &name) : JFieldBase(name) {}

JDouble JField<JDouble>::get(JObject& object ) {
    jfieldID fieldID = this->getFieldID( object.getJavaJniClass() );
    JNIEnv* env = helper::attach();
    jdouble result = env->GetDoubleField( object.getJavaJniObject(), fieldID );
    helper::catchAndThrow();
    return JDouble( result );
}
JDouble JField<JDouble>::get(const JClass* cls ) {
    jfieldID fieldID = this->getFieldID( cls, true );
    JNIEnv* env = helper::attach();
    jdouble result = env->GetStaticDoubleField( cls->getClass(), fieldID );
    helper::catchAndThrow();
    return JDouble( result );
}

// JField<JFloat> specialization
JField<JFloat>::JField(const std::string &name) : JFieldBase(name) {}

JFloat JField<JFloat>::get(JObject& object ) {
    jfieldID fieldID = this->getFieldID( object.getJavaJniClass() );
    JNIEnv* env = helper::attach();
    jfloat result = env->GetFloatField( object.getJavaJniObject(), fieldID );
    helper::catchAndThrow();
    return JFloat( result );
}
JFloat JField<JFloat>::get(const JClass* cls ) {
    jfieldID fieldID = this->getFieldID( cls, true );
    JNIEnv* env = helper::attach();
    jfloat result = env->GetStaticFloatField( cls->getClass(), fieldID );
    helper::catchAndThrow();
    return JFloat( result );
}

}
