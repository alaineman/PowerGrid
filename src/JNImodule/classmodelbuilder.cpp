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
    qWarning("Calling unimplemented function");
    // implementation here depends on representation of data in input file
    // AKA it is dependant on updater implementation

    // TODO: create ParseFile() function based on updater output format

    file.close();

    return mappings;
  }

}
