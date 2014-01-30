#include "rsclassmapper.h"
#include "mappingunavailableexception.h"
#include <stdexcept>
#include <QDebug>
#include <QXmlStreamReader>
#include "jace/JNIException.h"

using jace::JNIException;

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
        // TODO maybe pull directly from server?
        QXmlStreamReader reader (QFile("cache/updaterData.xml"));
        reader.readNext();
        if (reader.name() != "client") {
            qDebug() << "No client tag as start tag, but" << reader.name();
        }
        while (!reader.atEnd()) {
            reader.readNext();
            // TODO parse class and store in classMap
            parseFieldElement(reader /*, className*/);
        }
        if (reader.hasError()) {
            throw JNIException("Failed to parse updater data");
        }
        qDebug() << "RSClassMapper parsed updater data";
    }
}

void RSClassMapper::parseFieldElement(QXmlStreamReader reader) {
    // TODO parse a field and store in field map
}
