#ifndef JACE_MODEL_CLASSINFO_H
#define JACE_MODEL_CLASSINFO_H

#include <QObject>
#include <QString>
#include <QHash>
#include "mappable.h"

namespace jace {
namespace model {

class FieldInfo;

class ClassInfo : public Mappable {
    Q_OBJECT
    Q_DISABLE_COPY(ClassInfo)

    QHash<QString, FieldInfo*> fields;
public:
    explicit ClassInfo(const QString name, QObject *parent = 0);
    virtual ~ClassInfo();

    FieldInfo* getField(const QString name) const;
signals:
    void fieldAdded(FieldInfo* field);
public slots:
    void addField(const QString name);
};

} // namespace model
} // namespace jace

#endif // JACE_MODEL_CLASSINFO_H
