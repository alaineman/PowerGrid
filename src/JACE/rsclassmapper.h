#ifndef RSCLASSMAPPER_H
#define RSCLASSMAPPER_H

#include <QObject>
#include <QMap>
#include <QFile>

class RSClassMapper : public QObject {
    Q_OBJECT
  private:
    static QFile defaultDataFile;
    static RSClassMapper* classmapper;

    QFile source;
    QMap<QString, QString> classMap;
  public:
    static RSClassMapper* DefaultInstance();

    explicit RSClassMapper(QFile dataFile);
    virtual ~RSClassMapper();

    QFile dataFile() const { return source; }
    QString getRealName(QString semanticName) const { return classMap.find(semanticName); }

    void parseData();
};

#endif // RSCLASSMAPPER_H
