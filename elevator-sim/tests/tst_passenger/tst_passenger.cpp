#include <QtTest>
#include <../../app/elevatorcontrolsystem.h>
#include <../../app/elevator.h>
#include <../../app/passenger.h>
#include <../../app/floor.h>

int FLOORS_NUM = 7;
int CUR_FLOOR_NUM = 2;
int ELEVATORS_NUM = 1;

class TestPassenger : public QObject {
    Q_OBJECT
    ElevatorControlSystem* ecs;
    Floor* floor;
    private slots:
        void init() {
            qDebug() << "Setting up test...";
            ecs = new ElevatorControlSystem(ELEVATORS_NUM, FLOORS_NUM);
            floor = ecs->getFloor(CUR_FLOOR_NUM);
        }

        void cleanup() {
            qDebug() << "Cleaning up test...";
            delete ecs;
        }

        void testPassenger() {
            int FLOORS_NUM = 7;
            int CUR_FLOOR_NUM = 2;

            ElevatorControlSystem* ecs = new ElevatorControlSystem(3, FLOORS_NUM);

            Passenger* passenger = new Passenger("garry", 50, ecs->getFloor(CUR_FLOOR_NUM));

            QCOMPARE(passenger->getWeight(), 50);
        }

        // Refactor to make Passenger more testable
};

QTEST_MAIN(TestPassenger)
#include "tst_passenger.moc"
