#ifndef JACE_MODEL_CLASSINFO_H
#define JACE_MODEL_CLASSINFO_H

#include <QObject>

namespace jace {
namespace model {

class ClassInfo : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(ClassInfo)

    QString real, mapped;
public:
    explicit ClassInfo(const QString name, QObject *parent = 0);

    QString realName()   const { return real; }
    QString mappedName() const { return mapped; }
signals:
    void nameChanged(QString oldName, QString newName);
public slots:
    void renameClass(const QString mappedName);
};

} // namespace model
} // namespace jace

#endif // JACE_MODEL_CLASSINFO_H
