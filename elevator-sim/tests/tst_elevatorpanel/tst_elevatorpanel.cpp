#include <QtTest>
#include <../../app/elevatorcontrolsystem.h>
#include <../../app/elevator.h>
#include <../../app/elevatorpanel.h>

class TestElevatorPanel : public QObject {
    Q_OBJECT
    private slots:
        void init() {
            qDebug() << "Setting up test...";
        }

        void cleanup() {
            qDebug() << "Cleaning up test...";
        }

        void testElevatorPanel() {
            int FLOORS_NUM = 7;

            ElevatorControlSystem* ecs = new ElevatorControlSystem(3, FLOORS_NUM);
            Elevator* elevator = ecs->getElevator(1);
            ElevatorPanel* panel = elevator->getPanel();

            QCOMPARE(panel->openDoor(), true);
        }
};

QTEST_MAIN(TestElevatorPanel)
#include "tst_elevatorpanel.moc"
