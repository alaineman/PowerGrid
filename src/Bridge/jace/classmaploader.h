#ifndef CLASSMAPLOADER_H
#define CLASSMAPLOADER_H

#include <QObject>

#include <QJsonDocument>

namespace jace {

class ClassMapLoader : public QObject {
    Q_OBJECT

    QJsonDocument document;
public:
    explicit ClassMapLoader(QObject *parent = 0);

signals:
    void mappingReady();
    void mappingError(QString err);
public slots:
    void read(const QByteArray& jsonData);
private:
    void readClass(const QJsonObject& obj);
};

}

#endif // CLASSMAPLOADER_H
