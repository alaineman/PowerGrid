#include "classmodelbuilder.h"
#include "jniexception.h"

namespace jni {

  ClassModelBuilder::ClassModelBuilder(JavaEnv *e, QFile source) {
    if (e == NULL) {
      throw jni_error("NULL value for JavaEnv");
    }
    if (!source.exists()) {
      throw jni_error("Source file does not exist");
    }
    if (!source.isReadable()) {
      throw jni_error("Unreadable file");
    }

    env = e;
    file = source;
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
