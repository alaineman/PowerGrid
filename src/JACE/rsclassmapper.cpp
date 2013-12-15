#include "rsclassmapper.h"
#include <stdexcept>

QFile RSClassMapper::defaultDataFile ("cache/classnames.dat");

RSClassMapper::RSClassMapper(QString dataFile) : source (dataFile) {}

RSClassMapper::~RSClassMapper() {}

void RSClassMapper::parseData() {
  QFile sourceFile (source);
  if (sourceFile.exists()) {
    classMap.clear();
    sourceFile.open(QIODevice::ReadOnly);
    while (sourceFile.canReadLine()) {
      QByteArray rawData = sourceFile.readLine();
      QString line = QString::fromLatin1(rawData);
      QString key = line.section(';', 0, 0);
      QString value = line.section(';', 1, 1);
      classMap.insert(key, value);
    }
    sourceFile.close();
  } else {
    throw std::runtime_error("File not found");
  }
}
