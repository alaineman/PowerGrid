#include "classmaploader.h"

namespace jace {

ClassMapLoader::ClassMapLoader(QObject *parent) : QObject(parent) {
}

void ClassMapLoader::read(const QByteArray& jsonData) {
    emit mappingError(QStringLiteral("read() function not implemented"));
    QJsonParseError parseError;
    document.fromJson(jsonData, &parseError);
    if (parseError.error) {
        emit mappingError(parseError.errorString());
    } else {

    }
}

}
