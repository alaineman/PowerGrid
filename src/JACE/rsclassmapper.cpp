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
        QFile file ("cache/updaterData.xml");
        QXmlStreamReader reader (&file);
        reader.setNamespaceProcessing(false);
        QString currentClass;
        QString fieldName;
        while (!reader.atEnd()) {
            reader.readNext();
            // Switches in while loop, still annoying
            switch (reader.tokenType()) {
            case QXmlStreamReader::NoToken:
            case QXmlStreamReader::Invalid:
                goto checkError; // Switches in while loop, still annoying...
            case QXmlStreamReader::StartElement:
                if (currentClass.isEmpty()) {
                    // TODO read name() as class name and store as currentClass
                } else {
                    // TODO read name() as field name and store as fieldName
                }
                break;
            case QXmlStreamReader::EndElement:
                if (fieldName.isEmpty()) {
                    currentClass.clear();
                } else {
                    fieldName.clear();
                }
                break;
            case QXmlStreamReader::Characters:
                // TODO read name() as obfuscated field name and store as
                break;
            default:
                break;
            }
        }
    }
}
