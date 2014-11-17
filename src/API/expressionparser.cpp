#include "expressionparser.h"
#include "java/lang/class.h"
#include "java/lang/string.h"

#include "jace/MappingUnavailableException.h"

namespace API {

ExpressionParser::ExpressionParser(RSClassMapper *mapper)
        : QObject(), rscm(mapper) {
    Q_ASSERT(mapper != NULL);
}

Object ExpressionParser::evaluate(QString expression) {
    QStringList parts = expression.split(".");
    QString str(parts.at(0));
    str.replace('/', '.');
    str.replace(" ", "");
    str.replace("()", "");
    Class cls = Class::forName(str);
    if (parts.size() == 1) {
        return cls;
    }
    Object obj = cls.getStaticFieldContent(parts.at(1));
    for (int nextField = 2; nextField < parts.size(); nextField++) {
        if (obj.isNull()) {
            throw JNIException("Dereferenced NULL at position: " % QString::number(nextField));
        }
        Class objClass = obj.getClass();
        QString fieldName = convertFieldName(obj, parts.at(nextField));
        obj = objClass.getFieldContent(fieldName, obj);
    }
    return obj;
}

QString ExpressionParser::evaluateToString(QString expression) {
    return evaluate(expression).toString().toQString();
}

QString ExpressionParser::convertFieldName(Object obj, QString fieldName) const {
    String className = obj.getClass().getName();
    try {
        RSClass* rsc = rscm->getRSClass(className.toQString());
        return QString::fromStdString(rsc->getFieldName(fieldName));
    } catch (jace::MappingUnavailableException& ex) {
        // No mapping exists, so we assume the class is not obfuscated.
        // In that case we can just return the argument field name.
        return fieldName;
    }
}

}
