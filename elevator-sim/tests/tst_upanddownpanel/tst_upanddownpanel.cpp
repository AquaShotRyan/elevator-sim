#include <QtTest>
#include <../../app/elevatorcontrolsystem.h>
#include <../../app/upanddownpanel.h>
#include <../../app/floor.h>

class TestUpAndDownPanel : public QObject {
    Q_OBJECT
    private slots:
        void init() {
            qDebug() << "Setting up test...";
        }

        void cleanup() {
            qDebug() << "Cleaning up test...";
        }

        void testUpAndDownPanel() {
            int FLOORS_NUM = 7;
            int CUR_FLOOR_NUM = 2;

            ElevatorControlSystem* ecs = new ElevatorControlSystem(3, FLOORS_NUM);
            UpAndDownPanel* upAndDownPanel = new UpAndDownPanel(ecs);

            QCOMPARE(upAndDownPanel->requestDown(CUR_FLOOR_NUM), true);
        }
};

QTEST_MAIN(TestUpAndDownPanel)
#include "tst_upanddownpanel.moc"
