#include <QtTest>
#include <../../app/floor.h>
#include <../../app/elevatorcontrolsystem.h>
#include <../../app/elevator.h>
#include <../../app/passenger.h>

int FLOORS_NUM = 7;
int ELEVATORS_NUM = 1;

class TestFloor : public QObject {
    Q_OBJECT
    ElevatorControlSystem* ecs;
    Floor* startingFloor;
    Floor* testFloor;
    private slots:
        void init() {
            qDebug() << "Setting up test...";
            ecs = new ElevatorControlSystem(ELEVATORS_NUM, FLOORS_NUM);
            startingFloor = ecs->getFloor(2);
            testFloor = new Floor(ecs, 6); // Floor that's not part of floors created by ecs
        }

        void cleanup() {
            qDebug() << "Cleaning up test...";
            delete ecs;
            delete testFloor;
        }

        // After adding the passenger, removing the same passenger should return the passenger (it's been added)
        void test_add_passenger_1() {
            Passenger* passenger = new Passenger("garry", 50, startingFloor);

            testFloor->addPassenger(passenger);

            QCOMPARE(testFloor->removePassenger("garry"), passenger);

            delete passenger;
        }

        // After adding a passenger, adding the passenger again should throw an exception
//        void test_add_passenger_2() {
//            Passenger* passenger = new Passenger("garry", 50, startingFloor);

//            testFloor->addPassenger(passenger);

//            QVERIFY_EXCEPTION_THROWN(testFloor->addPassenger(passenger), std::runtime_error);

//            delete passenger;
//        }

        // After removing the passenger, removing the same passenger again should return nullptr (it's been removed)
        void test_remove_passenger() {
            Passenger* passenger = new Passenger("garry", 50, startingFloor);
            testFloor->addPassenger(passenger);
            testFloor->removePassenger("garry");

            Passenger* removedPassenger = testFloor->removePassenger("garry");
            QCOMPARE(removedPassenger, nullptr);

            delete passenger;
        }

        // After adding an elevtor, removing the same elevator should return true
        void test_add_elevator_1() {
            Elevator* elevator = ecs->getElevator(1);
            testFloor->addElevator(elevator);

            QCOMPARE(testFloor->removeElevator(1), true);
        }

//        // Throws an exception if you attempt to add a nullptr
//        void test_add_elevator_2() {
//            QVERIFY_EXCEPTION_THROWN(testFloor->addElevator(nullptr), std::runtime_error);
//        }

//        // Throws an exception if you attempt to add a duplicate elevator
//        void test_add_elevator_3() {
//            Elevator* elevator = ecs->getElevator(1);
//            testFloor->addElevator(elevator);
//            QVERIFY_EXCEPTION_THROWN(testFloor->addElevator(elevator), std::runtime_error);
//        }

        // After removing the elevator, removing the same elevator should return false (it's been removed)
        void test_remove_elevator_1() {
            Elevator* elevator = ecs->getElevator(1);

            testFloor->addElevator(elevator);
            testFloor->removeElevator(1);

            QCOMPARE(testFloor->removeElevator(1), false);
        }

        // Should return its floor number
        void test_get_floor_num() {
            QCOMPARE(testFloor->getFloorNum(), 6);
        }

};

QTEST_MAIN(TestFloor)
#include "tst_floor.moc"
