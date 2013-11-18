#include "rsclassmapper.h"
#include <stdexcept>

QFile RSClassMapper::defaultDataFile ("cache/classnames.dat");

RSClassMapper::RSClassMapper(QFile dataFile) : source (dataFile) {}

RSClassMapper::~RSClassMapper() {}

quint32 RSClassMapper::parseData() {
  if (source.exists()) {
    classMap.clear();
    source.open(QIODevice::ReadOnly);
    while (source.canReadLine()) {
      QByteArray rawData = source.readLine();
      QString line = QString::fromLatin1(rawData);
      QString key = line.section(';', 0, 0);
      QString value = line.section(';', 1, 1);
      classMap.insert(key, value);
    }
    source.close();
    return classMap.size();
  } else {
    throw std::runtime_error("File not found");
  }
}
