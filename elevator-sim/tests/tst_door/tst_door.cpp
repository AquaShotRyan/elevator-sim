#include <QtTest>
#include "../../app/door.h"

class TestDoor : public QObject {
    Q_OBJECT
    Door* door;
    private slots:
        void init() {
            qDebug() << "Setting up test...";
            door = new Door();
        }

        void cleanup() {
            qDebug() << "Cleaning up test...";
            delete door;
        }

        // closed status returns false when open
        void test_open() {
            door->open();
            QCOMPARE(door->getClosed(), false);
        }

        // closed status return true when closed
        void test_close() {
            door->close();
            QCOMPARE(door->getClosed(), true);
        }
};

QTEST_MAIN(TestDoor)
#include "tst_door.moc"
