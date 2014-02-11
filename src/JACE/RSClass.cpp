#include "RSClass.h"
#include "MappingUnavailableException.h"
using std::string;

/**
 * Creates a new RSClass with the given name and type name.
 *
 * @param name - The name of this class, suitable for use in
 *               a call to JNIEnv::FindClass.
 * @param simpleName the simple (semantic) name of the RSClass
 */
RSClass::RSClass(const string name, const QString simpleName, QMap<QString, QString> fMap, QMap<QString, int> mMap) :
  JClassImpl(name),
  simpleName (simpleName),
  fieldMap (fMap),
  modifierMap (mMap ) {
}

const QString &RSClass::getSimpleName() const {
  return simpleName;
}

string RSClass::getFieldName(QString simpleName) const {
  QMap<QString, QString>::const_iterator it = fieldMap.find(simpleName);
  if (it == fieldMap.cend()) {
      throw MappingUnavailableException((this->simpleName + simpleName).toStdString());
  }
  return it.value().toStdString();
}

int RSClass::getFieldModifier(QString simpleName) const {
    QMap<QString, int>::const_iterator it = modifierMap.find(simpleName);
    if (it == modifierMap.cend()) {
        return 1; // equivalent to no modifier ( f*1 == f )
    } else {
        return it.value();
    }
}
