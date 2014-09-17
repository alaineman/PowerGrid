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
     * @brief Evaluates the expression and returns the result
     * @param expression - the expression to evaluate
     * @return the result of the expression
     * @throws jace::JNIException - when an error occurs in the JNI, or when
     *         the field could not be found (the message of the JNIException
     *         will contain the missing field).
     */
    JValue* evaluate(QString expression);
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
     * @brief Returns the contents of the given field.
     * @param obj - the object to retrieve the field for
     * @param fieldName - the name of the field to retrieve
     * @return the contents of the field.
     */
    JValue* getField(Object obj, QString fieldName);

    std::string convertFieldName(Object obj, QString fieldName) const;
protected:
    /**
     * @brief Retrieves a Reflected Field Object.
     * @param type - the class to get the Field from
     * @param name - the name of the Field to retrieve the Reflection Object for.
     * @return the reflected Field Object for the provided data, or NULL if the Field
     *         does not exist.
     * @throws jace::JNIException - when an error occurs in the JNI, or when either of the
     *         parameters is invalid.
     */
    jobject getReflectedField(jclass type, const char* name) const throw(JNIException);
};

#endif // EXPRESSIONPARSER_H
