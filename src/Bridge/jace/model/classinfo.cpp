#include "classinfo.h"

namespace jace {
namespace model {

ClassInfo::ClassInfo(const QString name, QObject *parent) :
    QObject(parent), real(name), mapped(name) {
}

void ClassInfo::renameClass(const QString mappedName) {
    QString oldName = mapped;
    mapped = mappedName;
    emit nameChanged(oldName, mappedName);
}

} // namespace model
} // namespace jace
