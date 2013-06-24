#include "classmodelbuilder.h"

namespace jni {

  ClassModelBuilder::ClassModelBuilder(QString source) {
    if (source.isEmpty()) {
      throw logic_error("undefined source");
    }
    file.setFileName(source);

    if (!file.exists()) {
      throw logic_error("File does not exist");
    }
  }

  int ClassModelBuilder::ParseFile() {
    if (!file.isOpen()) {
      file.open(QIODevice::ReadOnly);
    }
    QByteArray bytedump = file.readAll(); // TODO - replace readAll() with read(amount) and refactor bytedump reads to file.read(amount).
                                          // Then it also becomes possible to use the parseN and parseString functions (implemented below).

    revision = file.read(1).at(0);

    int indextracker = 2;
    int bytelength = (int) bytedump[indextracker++];
    if(bytedump.size()<=bytedump[indextracker]){
        throw logic_error("invalid length specification");
    }
    QByteArray gamepack_bytes = QByteArray(bytelength, '\0'); //FIX THIS
    for(int i = 0; i<bytelength; i++){
        gamepack_bytes[i]=bytedump[i+indextracker];
        indextracker++;
    }
    const char* cString = gamepack_bytes.constData();
    gamepack = QString::fromUtf8(cString);

    //Implement while loop and find way to ParseString as method
    while( bytedump.size()>indextracker && bytedump[indextracker]==(char)(0) ){

      switch ( bytedump[indextracker++] ){
        case 0: //class
          break;
        case 1: //method
          break;
        case 2: //constant
          break;
        default: throw logic_error("invalid file - parsing error");
      }
      indextracker++;
    }
    file.close();
    return mappings.size();
  }

  QString ClassModelBuilder::parseString() {
    quint8 length = parse1();
    QByteArray stringData = file.read(length);
    if (stringData.length() < length) throw logic_error("Not enough data in file");
    return stringData.constData();
  }

  quint8 ClassModelBuilder::parse1() {
    QByteArray bytes = file.read(1);
    if (bytes.isEmpty()) throw logic_error("Not enough data in file");
    return (quint8)(bytes.at(0));
  }

  quint16 ClassModelBuilder::parse2() {
    QByteArray bytes = file.read(2);
    if (bytes.length() < 2) throw logic_error("Not enough data in file");
    return ((quint16)(bytes.at(0)) << 8) + bytes.at(1);
  }

  quint32 ClassModelBuilder::parse4() {
    QByteArray bytes = file.read(4);
    if (bytes.length() < 4) throw logic_error("Not enough data in file");
    return ((quint32)(bytes.at(0)) << 24) + ((quint32)(bytes.at(1)) << 16) + ((quint16)(bytes.at(2)) << 8) + bytes.at(3);
  }

  quint64 ClassModelBuilder::parse8() {
    QByteArray bytes = file.read(8);
    if (bytes.length() < 8) throw logic_error("Not enough data in file");
    return ((quint64)(bytes.at(0)) << 56) + ((quint64)(bytes.at(1)) << 48) + ((quint64)(bytes.at(2)) << 40) + ((quint64)(bytes.at(3)) << 32) +
           ((quint32)(bytes.at(4)) << 24) + ((quint32)(bytes.at(5)) << 16) + ((quint16)(bytes.at(6)) <<  8) + bytes.at(7);
  }
}
