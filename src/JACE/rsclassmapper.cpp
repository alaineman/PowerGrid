#include "rsclassmapper.h"
#include "mappingunavailableexception.h"
#include <stdexcept>
#include <QDebug>

QString RSClassMapper::defaultDataFile ("cache/updater.dat");
RSClassMapper* RSClassMapper::classmapper = nullptr;

RSClassMapper* RSClassMapper::DefaultInstance() {
    if (! RSClassMapper::classmapper) {
        RSClassMapper::classmapper = new RSClassMapper(defaultDataFile);
    }
    return RSClassMapper::classmapper;
}

RSClassMapper::RSClassMapper(QString dataFile) : source (dataFile) {}

RSClassMapper::~RSClassMapper() {}

QMap<QString, QString> RSClassMapper::getFieldMap(QString className) const {
    QMap<QString, QMap<QString, QString>>::const_iterator it = fieldMap.find(className);
    if (it == fieldMap.end()) {
        throw MappingUnavailableException(className.toStdString());
    }
    return it.value();
}

QString RSClassMapper::getRealName(QString semanticName) const {
    QMap<QString, QString>::const_iterator it = classMap.find(semanticName);
    if (it == classMap.end()) {
        throw MappingUnavailableException(semanticName.toStdString());
    }
    return it.value();
}

void RSClassMapper::parseData() {
    if (classMap.isEmpty()) {
        // TODO implement actual parsing of updater file.
        qDebug() << "RSClassMapper parsed updater data";
    }
}
