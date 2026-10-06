#include <QtTest>
#include <../../app/elevator.h>
#include <../../app/floor.h>
#include <../../app/elevatorcontrolsystem.h>
#include <../../app/passenger.h>

class TestElevator : public QObject {
    Q_OBJECT
    ElevatorControlSystem* ecs;
    Elevator* elevator;
    private slots:
        void init() {
            qDebug() << "Setting up test...";
            ecs = new ElevatorControlSystem(3, 7);
            elevator = ecs->getElevator(1);
        }

        void cleanup() {
            qDebug() << "Cleaning up test...";
            delete ecs;
        }

        // Passenger is added and elevator weight is increased appropriately
        void test_add_passenger(){
            int WEIGHT = 50;
            Passenger* p = new Passenger("garry", WEIGHT, ecs->getFloor(1));

            elevator->addPassenger(p);

            QCOMPARE(elevator->getPassengersSize(), 1);
            QCOMPARE(elevator->getWeight(), WEIGHT);

            delete p;
        }

        // Passenger is removed and returned and weight is decreased appropriately
        void test_remove_passenger_1() {
            int WEIGHT = 50;
            Passenger* p = new Passenger("garry", WEIGHT, ecs->getFloor(1));

            elevator->addPassenger(p);

            QCOMPARE(elevator->removePassenger(p->getName()), p);
            QCOMPARE(elevator->getPassengersSize(), 0);
            QCOMPARE(elevator->getWeight(), 0);

            delete p;
        }

        // Removing a passenger that doesn't exist returns nullptr
        void test_remove_passenger_2() {
            QCOMPARE(elevator->removePassenger("any name"), nullptr);
        }

        // Pushes floor number to the array
        void test_add_floor_request_1() {
            elevator->addFloorRequest(3);

            QCOMPARE(elevator->getFloorRequest(0), 3);
            QCOMPARE(elevator->floorRequestSize(), 1);
        }

        // Pushing a duplicate floor number doesn't add it
        void test_add_floor_request_2() {
            elevator->addFloorRequest(3);
            elevator->addFloorRequest(3);

            QCOMPARE(elevator->getFloorRequest(0), 3);
            QCOMPARE(elevator->floorRequestSize(), 1);
        }

        // If given an index, the floor is added to that index
        void test_add_floor_request_3() {
            elevator->addFloorRequest(3);
            elevator->addFloorRequest(4, 0);

            QCOMPARE(elevator->getFloorRequest(0), 4);
        }

        // Removes and returns floor request
        void test_pop_floor_request() {
            elevator->addFloorRequest(3);

            QCOMPARE(elevator->popFloorRequest(), 3);
            QCOMPARE(elevator->floorRequestSize(), 0);
        }
};

QTEST_MAIN(TestElevator)
#include "tst_elevator.moc"
