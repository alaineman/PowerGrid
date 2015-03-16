#include "classmapping.h"

#include <QLoggingCategory>

#include "classinfo.h"

Q_LOGGING_CATEGORY(clsMap, "ClassMapping")

namespace jace {
namespace model {

ClassMapping::ClassMapping(QObject *parent) :
    QObject(parent) {
}

ClassInfo* ClassMapping::find(const QString name, bool computeIfAbsent) {
    auto it = classes.find(name);
    if (it != classes.end()) {
        return it.value();
    }
    if (computeIfAbsent) {
        ClassInfo *info = new ClassInfo(name, this);
        connect(info, SIGNAL(mapped(QString,QString)),
                this, SLOT(renameClass(QString,QString)));
        classes.insert(name, info);
        return info;
    }
    return nullptr;
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
    ClassInfo *info = find(oldName);
    if (info != nullptr) {
        classes.remove(oldName);
        classes.insert(newName, info);
    } else Q_UNREACHABLE();
}

} // namespace mapping
} // namespace jace
