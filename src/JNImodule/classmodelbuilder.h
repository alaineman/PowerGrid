#ifndef CLASSMODELBUILDER_H
#define CLASSMODELBUILDER_H

#include <QFile>
#include "jniclass.h"
#include "javaenv.h"

namespace jni {

  /**
   * @brief Builder class for the Runescape class model
   *
   * This class takes a mapping from obfuscated Java Identifier names to semantic names and produces a mapping with the resulting JNIClass objects.
   * It is required to provide the JavaEnv object that has access to the classes in the mapping, since this class automatically fills the JNIClass
   * objects with their jmethodIDs and jfieldIDs where appropriate.
   */
  class ClassModelBuilder {
    private:
      short reversion;
      QString gamepack;
      QFile file;
      QMap<QString, JNIClass*> mappings;
      QMap<QString, long> constants;

    public:

      /**
       * @brief creates a new ClassModelBuilder
       * @param source the source containing the mapping.
       */
      ClassModelBuilder(const char* source);

      /**
       * @brief Parses the source and creates the mapping
       * @return a QMap containing all mapped JNIClass objects.
       */
      QMap<QString, JNIClass*> ParseFile();

      short getReversion();
      QString getGamepack();
  };

}

#endif // CLASSMODELBUILDER_H

