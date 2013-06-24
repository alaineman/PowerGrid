#ifndef CLASSMODELBUILDER_H
#define CLASSMODELBUILDER_H

#include <QFile>
#include <QString>
#include "jniclass.h"
#include "javaenv.h"

namespace jni {

  /**
   * Builder class for the Runescape class model
   *
   * This class takes a mapping from obfuscated Java Identifier names to semantic names and produces a mapping with the resulting JNIClass objects.
   * It is required to provide the JavaEnv object that has access to the classes in the mapping, since this class automatically fills the JNIClass
   * objects with their jmethodIDs and jfieldIDs where appropriate.
   */
  class ClassModelBuilder {
    private:
      qint16  revision;
      QString gamepack;
      QFile   file;
      QMap<QString, JNIClass*> mappings;
      QMap<QString, qint64>    constants;

      /// Parses a String from the (opened) file in the format (length)(char data...)
      QString  parseString();
      /// parses a 1-byte unsigned integer from the file
      quint8    parse1();
      /// parses a 2-byte unsigned integer from the file
      quint16   parse2();
      /// parses a 4-byte unsigned integer from the file
      quint32   parse4();
      /// parses a 8-byte unsigned integer from the file
      quint64   parse8();
   public:

      /**
       * creates a new ClassModelBuilder
       * @param source the source containing the mapping.
       */
      ClassModelBuilder(QString source);

      /**
       * Parses the source and creates the mapping
       * @return the amount of Classes parsed and saved
       */
      int ParseFile();

      /**
       * @return the gamepack revision as given in the file, or 0 if not yet parsed
       */
      qint16 getRevision() const { return revision; }
      /**
       * @return the gamepack name, or an empty QString when not yet parsed
       */
      QString getGamepack() const { return gamepack; }

      /**
       * @return true if and only if the file is parsed and mapping data is saved, false otherwise.
       */
      bool isParsed() const { return mappings.isEmpty(); }
  };

}

#endif // CLASSMODELBUILDER_H

