#include <QString>
#include <QtTest>

#include "jace/VmLoader.h"
#include "jace/JNIHelper.h"

#include "jace/JArray.h"
using jace::JArray;

#include "jace/proxy/types/JDouble.h"
#include "jace/proxy/types/JInt.h"
using jace::proxy::types::JDouble;
using jace::proxy::types::JInt;

class JArrayTest : public QObject {
    Q_OBJECT
public:
    JArrayTest() {}
private Q_SLOTS:
    void initTestCase();

    void test_toQList_normal();
    void test_toQList_empty();
    void test_toQList_single();
};

void JArrayTest::initTestCase() {
    // TODO create a VM
}

/**
 * Tests if a JArray's toQList function returns the correct result with
 * an arbitrary array (normal case).
 */
void JArrayTest::test_toQList_normal() {
    JArray<JInt> jarr (4);
    jarr[0] = 4;
    jarr[1] = 2;
    jarr[2] = 1;
    jarr[3] = 0;
    QList<JInt> qlist = jarr.toQList();
    QVERIFY2(qlist.length() == jarr.length(), "length equality");
    QVERIFY2(qlist.at(0) == 4, "qlist[0] == 4");
    QVERIFY2(qlist.at(1) == 2, "qlist[1] == 2");
    QVERIFY2(qlist.at(2) == 1, "qlist[2] == 1");
    QVERIFY2(qlist.at(3) == 0, "qlist[3] == 0");
}
\
/**
 * Tests if an empty JArray converts to an empty QList
 * (border case).
 */
void JArrayTest::test_toQList_empty() {
    JArray<JDouble> jarr (0);
    QList<JDouble> qlist = jarr.toQList();
    QVERIFY2(qlist.isEmpty(), "QList is empty");
}

/**
 * Tests if a singleton JArray converts to a singleton
 * QList (border case).
 */
void JArrayTest::test_toQList_single() {
    JArray<JInt> jarr (1);
    jarr[0] = 3;
    QList<JInt> qlist = jarr.toQList();
    QVERIFY2(qlist.length() == jarr.length(), "length equality");
    QVERIFY2(qlist.at(0) == 3, "qlist[0] == 3");
}

QTEST_APPLESS_MAIN(JArrayTest)

#include "tst_jarraytest.moc"
