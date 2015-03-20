#ifndef JACE_MAPPING_CLASSMAPPING_H
#define JACE_MAPPING_CLASSMAPPING_H

#include <QObject>
#include <QMap>

namespace jace {
namespace model {

class ClassInfo;

class ClassMapping : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(ClassMapping)

    QMap<QString, ClassInfo*> classes;
public:
    explicit ClassMapping(QObject *parent = 0);
    virtual ~ClassMapping();

    ClassInfo* findOrCompute(const QString name);
    ClassInfo* find(const QString name) const;
signals:
    void classRenamed(QString oldName, QString newName);
public slots:
    void renameClass(QString oldName, QString newName);
};

} // namespace mapping
} // namespace jace

#endif // JACE_MAPPING_CLASSMAPPING_H
