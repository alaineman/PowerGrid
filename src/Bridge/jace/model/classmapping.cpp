#include "classmapping.h"

#include <QLoggingCategory>

#include "classinfo.h"

Q_LOGGING_CATEGORY(clsMap, "ClassMapping")

namespace jace {
namespace model {

ClassMapping::ClassMapping(QObject *parent) :
    QObject(parent) {
}
ClassMapping::~ClassMapping() {
}

ClassInfo* ClassMapping::findOrCompute(const QString name) {
    auto it = classes.find(name);
    if (it != classes.end()) {
        return it.value();
    }
    ClassInfo *info = new ClassInfo(name, this);
    Q_CHECK_PTR(info);
    connect(info, SIGNAL(nameChanged(QString,QString)),
            this, SLOT(renameClass(QString,QString)));
    classes.insert(name, info);
    return info;
}

ClassInfo* ClassMapping::find(const QString name) const {
    auto it = classes.find(name);
    if (it != classes.end()) {
        return it.value();
    } else {
        return nullptr;
    }
}

void ClassMapping::renameClass(QString oldName, QString newName) {
    // If the ClassInfo doesn't exist yet, we simply create it now.
    ClassInfo *info = findOrCompute(oldName);
    Q_ASSERT(info != NULL); // findOrCompute should never return NULL.
    classes.remove(oldName);
    classes.insert(newName, info);
    emit classRenamed(oldName, newName);
}

} // namespace mapping
} // namespace jace
