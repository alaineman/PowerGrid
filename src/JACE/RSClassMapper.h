#ifndef RSCLASSMAPPER_H
#define RSCLASSMAPPER_H
#include "jace/os_dep.h"
#include "jni.h"
#include "RSClass.h"

#include <QObject>
#include <QMap>
#include <QFile>

class RSClassMapper : public QObject {
    Q_OBJECT
private:
    static RSClassMapper* classmapper;

    QMap<QString, QString> classMap;                // semanticClassName => realClassName
    QMap<QString, QMap<QString, QString>> fieldMap; // semanticClassName => ( semanticFieldName => realFieldName )
    QMap<QString, QMap<QString, int>> modifiers;    // semanticClassName => ( semanticFieldName => modifier value )

    QMap<QString, RSClass*> classes;                // semanticClassname => RSClass representative
public:
    JACE_API static RSClassMapper* DefaultInstance();

    JACE_API explicit RSClassMapper();
    JACE_API virtual ~RSClassMapper();

    JACE_API RSClass* getRSClass(QString name);

    JACE_API void parseData(jbyteArray data);
private:
    JACE_API QMap<QString, QString> getFieldMap(QString className) const;
    JACE_API QMap<QString, int> getModifierMap(QString className) const;
    JACE_API QString getRealName(QString semanticName) const;
};

#endif // RSCLASSMAPPER_H
