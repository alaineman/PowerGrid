#include <QObject>
#include <QtTest/QtTest>

#include "tests/MyTestSuite.h"

int main(int argc, char** argv) {

    int result(0);

    result += QTest::qExec(new MyTestSuite, argc, argv);

    return (result ? 1 : 0);
}
