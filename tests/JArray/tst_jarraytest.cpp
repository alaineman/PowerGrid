#include <QString>
#include <QtTest>

#include "jace/JArray.h"

class JArrayTest : public QObject
{
    Q_OBJECT

public:
    JArrayTest();

private Q_SLOTS:
    void testCase1();
};

JArrayTest::JArrayTest()
{
}

void JArrayTest::test()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(JArrayTest)

#include "tst_jarraytest.moc"
