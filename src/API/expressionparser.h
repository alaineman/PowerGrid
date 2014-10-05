#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <QObject>
#include <QString>

#include "jace/JNIException.h"
#include "jace/RSClassMapper.h"
#include "jace/proxy/JValue.h"
using namespace jace;
using namespace jace::proxy;

#include "java/lang/object.h"
using namespace java::lang;

namespace API {

/**
 * @brief The ExpressionParser class
 */
class ExpressionParser : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(ExpressionParser)
private:
    RSClassMapper* rscm;
public:
    /**
     * @brief Creates a new ExpressionParser that uses the provided RSClassMapper
     * @param mapper - the RSClassMapper to use.
     */
    ExpressionParser(RSClassMapper* mapper);

    /**
     * @brief Evaluates the expression and returns the result.
     *
     * If the result of the expression is a primitive, the primitive will be boxed
     * (by the JVM). It is possible to cast the Object to the boxed primitive type
     * to retrieve it. This is not required to create a String representation, as the
     * toString() method of the Java class provides this without needing to unbox the
     * primitive first.
     *
     * @param expression - the expression to evaluate
     * @return the result of the expression
     * @throws jace::JNIException - when an error occurs in the JNI, or when
     *         the field could not be found (the message of the JNIException
     *         will contain the missing field).
     */
    Object evaluate(QString expression);

    /**
     * @brief Evaluates the expression and converts the result into a QString.
     *
     * If any exception occurs during the evaluation, the message of the exception
     * is returned. Otherwise, the string equivalent of the result is returned.
     *
     * For object return types, this means an invocation to Object.toString().
     * For primitive types, this means a string representation of the primitive,
     * corresponding with the behavior of (Java's) @c String.valueOf(...) methods.
     *
     * @param expression - the expression to parse
     * @return the result of the expression
     */
    QString evaluateToString(QString expression);

    /**
     * @brief Translates the field name to the real (obfuscated) name.
     *
     * If no mapping exists, the original field name is returned. This ensures
     * this function also returns the expected value for non-obfuscated classes.
     *
     * @param obj       - the Object for which to translate the field
     * @param fieldName - the name of the field.
     * @return            the real name of the field.
     */
    QString convertFieldName(Object obj, QString fieldName) const;
};

}

#endif // EXPRESSIONPARSER_H
