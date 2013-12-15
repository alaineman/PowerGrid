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

    QString source;
    QMap<QString, QString> classMap;
  public:
    static RSClassMapper* DefaultInstance();

    explicit RSClassMapper(QString dataFile);
    virtual ~RSClassMapper();

    QString dataFile() const { return source; }
    QString getRealName(QString semanticName) const { return classMap.find(semanticName).value(); }

    void parseData();
};

#endif // RSCLASSMAPPER_H
