#include "classmodelbuilder.h"
#include "jniexception.h"

namespace jni {

  ClassModelBuilder::ClassModelBuilder(const char* source) {
    if (source == NULL || source[0] == 0) {
      throw jni_error("undefined source");
    }
    file.setFileName(source);

    if (!file.exists()) {
      throw jni_error("File does not exist");
    }
  }

  QMap<QString, JNIClass*> ClassModelBuilder::ParseFile() {
    if (!file.isOpen()) {
      file.open(QIODevice::ReadOnly);
    }
    QByteArray bytedump = file.readAll();
    if(bytedump.isNull() || bytedump.isEmpty() || bytedump.size()<4){
        throw logic_error("invalid file");
    }

    int indextracker = 0;

    reversion = (short)((bytedump[indextracker]) << 8) + (short)(bytedump[indextracker++]);

    int bytelength = (int) bytedump[indextracker++];
    if(bytedump.size()<=bytedump[indextracker]){
        throw logic_error("invalid file");
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
     return mappings;
  }




}
