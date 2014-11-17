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
 * @brief Simple Java Expression Parser.
 *
 * This class can parse Java expressions consisting of a series of field getters.
 *
 * For example, the following would retrieve the name of the local player according
 * to the client:
 *
 *     evaluate("Client.getLocalPlayer().getName()");
 *
 * The braces are optional, but the name has to be the same as the getter method name
 * (so "Client.localPlayer.name" will not work, but "Client.getLocalPlayer.getName" will).
 * In fact, the braces are ignored completely, so "Client().getLocalPlayer()" will still return
 * the local player, even though "Client" is a class name and not a field.
 *
 * Calls to evaluate are first converted to their obfuscated equivalents if such a mapping
 * exists, and otherwise are interpreted as-is. This means it is possible to mix obfuscated
 * and non-obfuscated code and everything will still work as expected. However, it also means
 * the evaluate function will automatically fail if a required binding is not available, so
 * callers should always catch errors thrown by functions in this class.
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
