/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "RSClassMapper.h"
#include "MappingUnavailableException.h"
#include <stdexcept>
#include <QDebug>
#include <QXmlStreamReader>
#include <iostream>

#include "jace/JNIException.h"
#include "jace/JNIHelper.h"

Q_LOGGING_CATEGORY(logMapper, "MAPPER")

namespace jace {

RSClassMapper* RSClassMapper::classmapper = Q_NULLPTR;

RSClassMapper* RSClassMapper::DefaultInstance() {
    if (! RSClassMapper::classmapper) {
        RSClassMapper::classmapper = new RSClassMapper();
    }
    return RSClassMapper::classmapper;
}

RSClassMapper::RSClassMapper() {}

RSClassMapper::~RSClassMapper() {
    // Upon destruction, delete all maintained RSClass references.
    for (QMap<QString,RSClass*>::Iterator it=classes.begin(); it!=classes.end();it++) {
        RSClass* rsc = it.value();
        if (rsc) {
            delete rsc;
        }
    }
}

QMap<QString, QString> RSClassMapper::getFieldMap(QString className) const {
    QMap<QString, QMap<QString, QString>>::const_iterator it = fieldMap.find(className);
    if (it == fieldMap.cend()) {
        throw MappingUnavailableException(className);
    }
    return it.value();
}

QMap<QString, jlong> RSClassMapper::getModifierMap(QString className) const {
    QMap<QString, QMap<QString, jlong>>::const_iterator it = modifiers.find(className);
    if (it == modifiers.cend()) {
        return QMap<QString, jlong>();
    }
    return it.value();
}

QString RSClassMapper::getRealName(QString semanticName) const {
    QMap<QString, QString>::const_iterator it = classMap.find(semanticName);
    if (it == classMap.end()) {
        throw MappingUnavailableException("class " + semanticName);
    }
    return it.value();
}

RSClass* RSClassMapper::getRSClass(QString name) {
    QMap<QString, RSClass*>::const_iterator it = classes.find(name);
    if (it == classes.cend()) {
        QString realName = getRealName(name);
        RSClass* rsc = new RSClass(realName.toStdString(),
                                   name,
                                   getFieldMap(name),
                                   getModifierMap(name),
                                   getClass(realName));
        classes.insert(name, rsc);
        // We delete the references from the maps to prevent redundancy
        classMap.remove(name);
        fieldMap.remove(name);
        modifiers.remove(name);
        qCDebug(logMapper) << "Linked RS class:" << qPrintable(name);
        return rsc;
    } else {
        return it.value();
    }
}

QString RSClassMapper::getStaticFieldClass(QString fieldName) const {
    QString className = staticClassMap.value(fieldName);
    if (className.isEmpty()) {
        throw MappingUnavailableException("class of static field " + fieldName);
    }
    return className;
}

QString RSClassMapper::getStaticFieldName(QString fieldName) const {
    QString name = staticFieldMap.value(fieldName);
    if (name.isEmpty()) {
        throw MappingUnavailableException("static field " + fieldName);
    }
    return name;
}

jlong RSClassMapper::getStaticFieldModifier(QString fieldName) const {
    QMap<QString, jlong>::ConstIterator it = staticModifierMap.find(fieldName);
    if (it == staticModifierMap.cend()) {
        return 1;
    } else {
        return it.value();
    }
}

void RSClassMapper::parseData(jbyteArray data) throw(JNIException) {
    if (data == NULL) {
        throw JNIException("Received NULL jbyteArray as map data");
    }
    if (classMap.isEmpty()) {
        JNIEnv* env = jace::helper::attach();

        // Transfer the jbyte array to a char buffer
        jint length = env->GetArrayLength(data);
        char buffer [length];
        char* chars = buffer;
        env->GetByteArrayRegion(data, 0, length, reinterpret_cast<jbyte*>(chars));
        qCDebug(logMapper) << "Received" << length << "bytes of updater data";

        // Parse the data using QXmlStreamReader
        QByteArray byteArray (const_cast<const char*>(buffer), length);
        QXmlStreamReader* reader = new QXmlStreamReader(byteArray);
        reader->setNamespaceProcessing(false);
        while (reader->tokenType() != QXmlStreamReader::StartElement) {
            reader->readNext();
        }
        qCDebug(logMapper) << "Parsing updater data for client with hash " << reader->attributes().value("crc");

        int nFields = 0;
        while (!reader->atEnd()) {
            reader->readNext();
            switch(reader->tokenType()) {
            case QXmlStreamReader::NoToken:
            case QXmlStreamReader::Invalid:
                if (reader->hasError()) {
                    throw JNIException("Error parsing XML: " + reader->errorString());
                } else {
                    throw JNIException("Undetermined Error parsing XML");
                }
            case QXmlStreamReader::StartElement:
                nFields += parseClass(reader);
                break;
            default:
                break;
            }
        }

        // One workaround (hopefully temporary): the Client class is named "Client" in C++ (naming conventions),
        // but the updater (as well as the RS client jar file) names it "client" (lower case). Therefore the
        // Client class cannot be properly mapped. This can be circumvented by renaming "client" with "Client"
        // in the data right here.
        QMap<QString, QString> fields = fieldMap.value("client");
        QMap<QString, jlong> mods = modifiers.value("client");
        QString realname = classMap.value("client"); // Should always be "client", but still...

        fieldMap.remove("client");
        modifiers.remove("client");
        classMap.remove("client");

        fieldMap.insert("Client", fields);
        modifiers.insert("Client", mods);
        classMap.insert("Client", realname);

        qCDebug(logMapper) << "Read" << classMap.size() << "classes with" << nFields << "fields in total";
    }
}

int RSClassMapper::parseClass(QXmlStreamReader* reader) throw(JNIException) {
    QStringRef className = reader->name();
    QStringRef mappedClassName = reader->attributes().value("classname");
    if (mappedClassName.isEmpty()) {
        throw JNIException("Missing \"classname\" attribute for class " + className.toString());
    }
    bool isStatic = false;
    if (className == mappedClassName && className != "client") {
        // These classes have static references we might need, so we need to treat them
        // differently.
        isStatic = true;
    }
    // prepare all map entries for this RS class
    QString cName = className.toString();
    //qCDebug(logMapper) << cName;
    if (!isStatic) {
        classMap.insert(cName, mappedClassName.toString());
        fieldMap.insert(cName, QMap<QString, QString>());
        modifiers.insert(cName, QMap<QString, jlong>());
    }
    int nFields = 0;

    while (!reader->atEnd()) {
        reader->readNext();
        switch(reader->tokenType()) {
        case QXmlStreamReader::NoToken:
        case QXmlStreamReader::Invalid:
            if (reader->hasError()) {
                throw JNIException("[class] Error parsing XML: " + reader->errorString());
            } else {
                throw JNIException("[class] Undetermined Error parsing XML");
            }
        case QXmlStreamReader::StartElement:
            parseField(reader, cName, isStatic);
            nFields++;
            break;
        case QXmlStreamReader::EndElement:
            if (reader->name() == cName) {
                return nFields;
            } else {
                throw JNIException("[class] Unexpected end element: " + reader->name().toString());
            }
        default:
            break;
        }
    }
    return nFields;
}

void RSClassMapper::parseField(QXmlStreamReader *reader, QString className, bool isStatic) throw(JNIException) {
    QString fieldName = reader->name().toString();
    //qCDebug(logMapper) << " ->" << fieldName;

    while (!reader->atEnd()) {
        reader->readNext();
        switch(reader->tokenType()) {
        case QXmlStreamReader::NoToken:
        case QXmlStreamReader::Invalid:
            if (reader->hasError()) {
                throw JNIException("[field] Error parsing XML: " + reader->errorString());
            } else {
                throw JNIException("[field] Undetermined Error parsing XML");
            }
        case QXmlStreamReader::StartElement:
            if (reader->name() == "multiplier") {
                parseModifier(reader, className, fieldName, isStatic);
            }
            break;
        case QXmlStreamReader::EndElement:
            if (reader->name() == fieldName) {
                return;
            } else {
                throw JNIException("[field] Unexpected end element: " + reader->name().toString());
            }
        case QXmlStreamReader::Characters:
            // This is the real field name
            if (fieldName.isEmpty()) {
                throw JNIException("[field] Cannot map an empty field name");
            }
            if (isStatic) {
                staticClassMap.insert(fieldName, className);
                staticFieldMap.insert(fieldName, reader->text().toString());
            } else {
                QMap<QString, QString> map = fieldMap.value(className);
                map.insert(fieldName, reader->text().toString());
            }
            break;
        default:
            break;
        }
    }
}

void RSClassMapper::parseModifier(QXmlStreamReader *reader, QString className, QString fieldName, bool isStatic) throw(JNIException) {
    while (!reader->atEnd()) {
        reader->readNext();
        switch(reader->tokenType()) {
        case QXmlStreamReader::NoToken:
        case QXmlStreamReader::Invalid:
            if (reader->hasError()) {
                throw JNIException("[mod] Error parsing XML: " + reader->errorString());
            } else {
                throw JNIException("[mod] Undetermined Error parsing XML");
            }
        case QXmlStreamReader::StartElement:
            if (reader->name() != "multiplier") {
                throw JNIException("[mod] Unexpected start element: " + reader->name().toString());
            }
            break;
        case QXmlStreamReader::EndElement:
            if (reader->name() == "multiplier") {
                return;
            } else {
                throw JNIException("[mod] Unexpected end element: " + reader->name().toString());
            }
        case QXmlStreamReader::Characters:
            {// This is the actual modifier value
                bool ok = true;
                long mod = reader->text().toLong(&ok);
                if (!ok) {
                    throw JNIException("[mod] Cannot convert text \"" + reader->text().toString() + "\" to long");
                }
                if (isStatic) {
                    staticModifierMap.insert(fieldName, mod);
                } else {
                    QMap<QString, jlong> map = modifiers.value(className);
                    map.insert(fieldName, mod);
                }
            }
            break;
        default:
            break;
        }
    }
}

jclass RSClassMapper::getClass(QString name) {
    JNIEnv* env = jace::helper::attach();
    const char* cName = name.toUtf8().constData();
    jclass classLoaderClass = env->FindClass("net/pgrid/loader/RSClassLoader");
    if (! classLoaderClass) throw JNIException("RSClassLoader not found");
    jstring cNameStr = env->NewStringUTF(cName);
    if (! cNameStr) throw JNIException("Cannot create java String");
    jfieldID instance = env->GetStaticFieldID(classLoaderClass, "INSTANCE", "Lnet/pgrid/loader/RSClassLoader;");
    if (! instance) throw JNIException("Cannot find INSTANCE in RSClassLoader");
    jmethodID getClass = env->GetMethodID(classLoaderClass, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
    if (! getClass) throw JNIException("Cannot find getClass(String) in RSClassLoader");

    jobject classLoader = env->GetStaticObjectField(classLoaderClass, instance);
    if (! classLoader) throw JNIException("Cannot get ClassLoader");
    jobject rsClass = env->CallObjectMethod(classLoader, getClass, cNameStr);
    if (! rsClass) throw JNIException("Cannot find RS Class named " + name);

    env->DeleteLocalRef(cNameStr);
    env->DeleteLocalRef(classLoader);
    env->DeleteLocalRef(classLoaderClass);

    return static_cast<jclass>(rsClass);
}

}
