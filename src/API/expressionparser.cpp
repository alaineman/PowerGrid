#include "expressionparser.h"
#include "java/lang/class.h"
#include "java/lang/string.h"

ExpressionParser::ExpressionParser(RSClassMapper *mapper)
        : QObject(), rscm(mapper) {
    if (!mapper) {
        throw std::invalid_argument("NULL RSClassMapper");
    }
}

template <typename T>
T ExpressionParser::evaluate(QString expression) {
    Q_UNUSED(expression);
    //TODO loop over expression parts and evaluate piece by piece

    return NULL;
}

QString ExpressionParser::evaluateToString(QString expression) {
    Q_UNUSED(expression);
    //TODO convert arbitrary JValue type to String
    return QString();
}

Object *ExpressionParser::getField(Object obj, QString fieldName) {
    if (obj.isNull()) throw JNIException("Dereferencing NULL while getting Field named: " % fieldName);
    JNIEnv* env = jace::helper::attach();
    jobject jobj = obj.getJavaJniObject();
    jclass type = env->GetObjectClass(jobj);
    if (!type) throw JNIException("Cannot get type of object");
    jfieldID fieldID = getReflectedFieldID(type, qPrintable(fieldName));
    jobject jresult = env->GetObjectField(jobj, fieldID);
    Object* result = new Object(jresult);
    if (jresult) {
        env->DeleteLocalRef(jresult);
    }
    env->DeleteLocalRef(type);
    return result;
}

template <typename P>
P ExpressionParser::getPrimitive(Object obj, QString fieldName) {
    if (obj.isNull()) throw JNIException("Dereferencing NULL while getting Field named " % fieldName);
    JNIEnv* env  = jace::helper::attach();
    jobject jobj = obj.getJavaJniObject();
    jclass type  = env->GetObjectClass(jobj);
    if (!type) throw JNIException("Cannot get type of object");
    jfieldID field = getReflectedFieldID(type, qPrintable(fieldName));
    if (!field) throw JNIException("Cannot find Field named" % fieldName);
    P value = getFieldValue<P>(env, jobj, field);
    env->DeleteLocalRef(type);
    return value;
}

std::string ExpressionParser::convertFieldName(Object obj, QString fieldName) const {
    String className = obj.getClass().getName();
    RSClass* rsc = rscm->getRSClass(className.toQString());
    return rsc->getFieldName(fieldName);
}

jobject ExpressionParser::getReflectedField(jclass type, const char *name) const throw(JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass classClass = env->FindClass("java/lang/Class");
    if (!classClass) throw JNIException("Cannot find java.lang.Class");
    jmethodID getField = env->GetMethodID(classClass,
          "getDeclaredField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    if (!getField) throw JNIException("Cannot find Class.getDeclaredField(String)");
    jstring fieldName = env->NewStringUTF(name);
    if (!fieldName) throw JNIException("Cannot create Java String");
    jobject fieldObject = env->CallObjectMethod(type, getField, fieldName);

    env->DeleteLocalRef(fieldName);
    env->DeleteLocalRef(classClass);

    if (env->ExceptionCheck()) {
        env->ExceptionClear();
        throw JNIException("Exception retrieving Field object");
    }
    return fieldObject;
}

jfieldID ExpressionParser::getReflectedFieldID(jclass type, const char *name) const throw(JNIException) {
    JNIEnv* env = jace::helper::attach();
    jobject fieldObject = getReflectedField(type, name);
    if (!fieldObject) throw JNIException("Field not found");
    jfieldID fieldID = env->FromReflectedField(fieldObject);
    if (!fieldID) throw JNIException("Error converting Java Field to JNI FieldID");
    env->DeleteLocalRef(fieldObject);
    return fieldID;
}
