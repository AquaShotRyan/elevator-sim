#include <QtTest>
#include <stdexcept>

// The class being tested (normally in its own header)
class Math {
public:
    int add(int a, int b) { return a + b; }
    double divide(double a, double b) {
        if (b == 0) throw std::invalid_argument("Division by zero");
        return a / b;
    }
};

// The test class
class TestMath : public QObject
{
    Q_OBJECT

private slots:
    // Called before each test function
    void init() {
        qDebug() << "Setting up test...";
    }

    // Called after each test function
    void cleanup() {
        qDebug() << "Cleaning up test...";
    }

    // A simple test
    void testAdd() {
        Math math;
        QCOMPARE(math.add(2, 3), 5);
        QCOMPARE(math.add(-1, 1), 0);
        QCOMPARE(math.add(0, 0), 0);
    }

    // A test using data-driven rows
    void testAdd_dataDriven_data() {
        QTest::addColumn<int>("a");
        QTest::addColumn<int>("b");
        QTest::addColumn<int>("expected");

        QTest::newRow("positive") << 2 << 3 << 5;
        QTest::newRow("negative") << -2 << -3 << -5;
        QTest::newRow("mixed")    << -2 <<  5 <<  3;
        QTest::newRow("zeros")    <<  0 <<  0 <<  0;
    }

    // method that creates data must have this method name appended with _data
    void testAdd_dataDriven() {
        QFETCH(int, a);
        QFETCH(int, b);
        QFETCH(int, expected);
        Math math;
        QCOMPARE(math.add(a, b), expected);
    }

    // A test that expects an exception (Qt 5.3+)
    void testDivideByZero() {
        Math math;
        QVERIFY_EXCEPTION_THROWN(math.divide(10, 0), std::invalid_argument);
    }

    // A test using QVERIFY
    void testDivide() {
        Math math;
        QVERIFY(qFuzzyCompare(math.divide(10.0, 2.0), 5.0));
    }
};

// Boilerplate to run the tests
QTEST_MAIN(TestMath)
#include "tst_example.moc"
