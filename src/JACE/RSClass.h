#ifndef RSCLASS_H
#define RSCLASS_H

#include "jace/os_dep.h"
#include "jace/namespace.h"
#include "jace/JClassImpl.h"
#include "jace/JNIException.h"

#include <string>
using std::string;

#include <QMap>
#include <QString>

class RSClass : public jace::JClassImpl {
  private:
    QString simpleName;
    QMap<QString, QString> fieldMap;
  public:
    JACE_API RSClass(const string name, const QString simpleName, QMap<QString, QString> fMap);
    JACE_API virtual ~RSClass() throw() {}

    JACE_API virtual const QString &getSimpleName() const;
    JACE_API string getFieldName(QString simpleName) const;
};

#endif // RSCLASS_H
