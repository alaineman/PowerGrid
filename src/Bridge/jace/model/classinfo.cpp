#include "classinfo.h"

#include "fieldinfo.h"
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(clsInfo, "ClassInfo")

namespace jace {
namespace model {

ClassInfo::ClassInfo(const QString name, QObject *parent) :
    Mappable(name, parent) {
}
ClassInfo::~ClassInfo() {
}

FieldInfo* ClassInfo::getField(const QString name) const {
    auto it = fields.find(name);
    if (it == fields.end()) {
        return nullptr;
    } else {
        return *it;
    }
}

void ClassInfo::addField(const QString name) {
    if (fields.contains(name)) {
        qCWarning(clsInfo) << "Tried to add duplicate field" << name
                           << "to class" << activeName();
    } else {
        FieldInfo *info = new FieldInfo(name, this);
        fields.insert(name, info);
        emit fieldAdded(info);
    }
}

} // namespace model
} // namespace jace
