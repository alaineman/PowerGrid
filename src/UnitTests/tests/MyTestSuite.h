#ifndef MYTESTSUITE_H
#define MYTESTSUITE_H

#include <QObject>
#include <QtTest/QtTest>

class MyTestSuite : public QObject {
    Q_OBJECT
private slots:
    void dummyTest();
};

#endif // MYTESTSUITE_H
