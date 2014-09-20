#include "expressionparser.h"

ExpressionParser::ExpressionParser(RSClassMapper *mapper)
        : QObject(), rscm(mapper) {
    if (!mapper) {
        throw std::invalid_argument("NULL RSClassMapper");
    }
}

JValue* ExpressionParser::evaluate(QString expression) {
    Q_UNUSED(expression);
    //TODO loop over expression parts and evaluate piece by piece
    return NULL;
}

QString ExpressionParser::evaluateToString(QString expression) {
    Q_UNUSED(expression);
    //TODO convert arbitrary JValue type to String
    return QString();
}

JValue* ExpressionParser::getField(Object obj, QString fieldName) {
    if (obj.isNull()) throw JNIException("Dereferencing NULL while getting Field named: " % fieldName);
    JNIEnv* env = jace::helper::attach();
    jobject jobj = obj.getJavaJniObject();
    jclass type = env->GetObjectClass(jobj);
    if (!type) throw JNIException("Cannot get type of object");

    jobject field = getReflectedField(type, qPrintable(fieldName));
    if (!field) throw JNIException("Cannot find Field named " % fieldName);
    jfieldID fieldID = env->FromReflectedField(field);
    if (!fieldID) throw JNIException("Cannot convert to FieldID: " % fieldName);
    jobject result = env->GetObjectField(jobj, fieldID);
    //TODO add support for primitive types
    return new JObject(result);
}

std::string ExpressionParser::convertFieldName(Object obj, QString fieldName) const {
    const jace::JClass* cls = obj.getJavaJniClass();
    //TODO Implement ExpressionParser::convertFieldName(Object,QString)
    return std::string();
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
