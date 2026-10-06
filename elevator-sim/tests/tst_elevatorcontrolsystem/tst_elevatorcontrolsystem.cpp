#include <QtTest>
#include <../../app/elevatorcontrolsystem.h>
#include <../../app/elevator.h>
#include <../../app/floor.h>

int ELEVATORS_NUM = 3;
int FLOORS_NUM = 7;
int E_ID = 1;
int F_ID = 2;

class TestElevatorControlSystem : public QObject {
    Q_OBJECT
    ElevatorControlSystem* ecs;
    private slots:
        void init() {
            qDebug() << "Setting up test...";
            ecs = new ElevatorControlSystem(ELEVATORS_NUM, FLOORS_NUM);
        }

        void cleanup() {
            qDebug() << "Cleaning up test...";
            delete ecs;
        }

        // Returns false the elevator id is invalid
        void test_move_elevator_1() {
            QCOMPARE(ecs->moveElevator(100, F_ID), false);
        }

        // Returns false if floor number is above the highest floor
        void test_move_elevator_2() {
            QCOMPARE(ecs->moveElevator(E_ID, FLOORS_NUM + 1), false);
        }

        // Returns false if the floor number is below 1
        void test_move_elevator_3() {
            QCOMPARE(ecs->moveElevator(E_ID, 0), false);
        }

        // Returns false if there's an obstacle
        void test_move_elevator_4() {
            Elevator* e = ecs->getElevator(E_ID);

            e->open();
            e->setObstacle(true);

            QCOMPARE(ecs->moveElevator(E_ID, 1), false);
        }

        // Returns true if the elevator is successfully moved
        void test_move_elevator_5() {
            // Verify returns true
            QCOMPARE(ecs->moveElevator(E_ID, F_ID), true);
            // Verify elevator is removed from old floor
            QCOMPARE(ecs->getFloor(1)->removeElevator(E_ID), false);
            // Verify elevator was added to new floor
            QCOMPARE(ecs->getFloor(F_ID)->removeElevator(E_ID), true);

            // TODO: test up and down buttons are unilluminated when it's implemented
        }

        // Returns false if the floor is below the elevator
        void test_find_direction_1() {
            Elevator* e = ecs->getElevator(E_ID);
            ecs->moveElevator(E_ID, 3);

            e->addFloorRequest(2);

            QCOMPARE(ecs->findDirection(e), false);
        }

        // Returns true if the floor is above the elevator
        void test_find_direction_2() {
            Elevator* e = ecs->getElevator(E_ID);
            ecs->moveElevator(E_ID, 3);

            e->addFloorRequest(4);

            QCOMPARE(ecs->findDirection(e), true);
        }

        // Returns position of floor in the floor request queue
        void test_find_floor_distance_1() {
            Elevator* e = ecs->getElevator(E_ID);

            ecs->moveElevator(E_ID, 3);
            ecs->addFloorRequest(e, 4, true);
            ecs->addFloorRequest(e, 5, false);
            ecs->addFloorRequest(e, 2, true);

            int result = ecs->findFloorDistance(e, 2);
            qDebug() << "Distance: " << result;

            QCOMPARE(result, 2);
        }

        // Returns -1 if the floor isn't in the queue
        void test_find_floor_distance_2() {
            Elevator* e = ecs->getElevator(E_ID);

            ecs->moveElevator(E_ID, 3);
            e->addFloorRequest(4);
            e->addFloorRequest(5);
            e->addFloorRequest(2);

            int result = ecs->findFloorDistance(e, 6);
            qDebug() << "Distance: " << result;

            QCOMPARE(result, -1);
        }

        // Returns nullptr if no elevator has the floor request
        void test_find_shortest_elevator_1() {
            Elevator* e1 = ecs->getElevator(1);
            Elevator* e2 = ecs->getElevator(2);
            Elevator* e3 = ecs->getElevator(3);
            QVector<Elevator*> elevators = {e1, e2, e3};

            e1->addFloorRequest(4);
            e2->addFloorRequest(5);
            e3->addFloorRequest(6);

            Elevator* result = ecs->findShortestElevator(elevators, 3);
            QCOMPARE(result, nullptr);
        }

        // If all elevators contain the request, it returns the elevator with the floor closest to the head of the array
        void test_find_shortest_elevator_2() {
            Elevator* e1 = ecs->getElevator(1);
            Elevator* e2 = ecs->getElevator(2);
            Elevator* e3 = ecs->getElevator(3);
            QVector<Elevator*> elevators = {e1, e2, e3};

            e1->addFloorRequest(4);
            e1->addFloorRequest(2);
            e1->addFloorRequest(5);
            e1->addFloorRequest(6);
            e1->addFloorRequest(3);

            e2->addFloorRequest(5);
            e2->addFloorRequest(2);
            e2->addFloorRequest(3);

            e3->addFloorRequest(6);
            e3->addFloorRequest(1);
            e3->addFloorRequest(7);
            e3->addFloorRequest(3);

            Elevator* result = ecs->findShortestElevator(elevators, 3);
            QCOMPARE(result, e2);
        }

        // If the distance is the same for all elevators, it returns the first elevator
        void test_find_shortest_elevator_3() {
            Elevator* e1 = ecs->getElevator(1);
            Elevator* e2 = ecs->getElevator(2);
            Elevator* e3 = ecs->getElevator(3);
            QVector<Elevator*> elevators = {e1, e2, e3};

            e1->addFloorRequest(4);
            e1->addFloorRequest(6);
            e1->addFloorRequest(3);

            e2->addFloorRequest(5);
            e2->addFloorRequest(2);
            e2->addFloorRequest(3);

            e3->addFloorRequest(6);
            e3->addFloorRequest(7);
            e3->addFloorRequest(3);

            Elevator* result = ecs->findShortestElevator(elevators, 3);
            QCOMPARE(result, e1);
        }

        // If only one elevator has the floor, then that elevator will be returned
        void test_find_shortest_elevator_4() {
            Elevator* e1 = ecs->getElevator(1);
            Elevator* e2 = ecs->getElevator(2);
            Elevator* e3 = ecs->getElevator(3);
            QVector<Elevator*> elevators = {e1, e2, e3};

            e1->addFloorRequest(4);
            e1->addFloorRequest(6);
            e1->addFloorRequest(7);

            e2->addFloorRequest(5);
            e2->addFloorRequest(2);
            e2->addFloorRequest(3);

            e3->addFloorRequest(6);
            e3->addFloorRequest(7);
            e3->addFloorRequest(5);

            Elevator* result = ecs->findShortestElevator(elevators, 3);
            QCOMPARE(result, e2);
        }

        // Returns -1 if the floor isn't in the elevator's floor requests
        void test_find_above_below_1() {
            Elevator* e = ecs->getElevator(E_ID);

            QCOMPARE(ecs->findAboveBelow(e, 3, true), -1);
        }

        void test_find_above_below_2_data() {
            QTest::addColumn<int>("last_floor"); // last floor in elevator's queue
            QTest::addColumn<int>("floor");
            QTest::addColumn<bool>("direction");
            QTest::addColumn<int>("expected");

            QTest::newRow("Returns positive number if the floor is above last floor and direction is true (up)") << 3 << 5 << true << 2;
            QTest::newRow("Returns positive number if the floor is below last floor and direction is false (down)") << 4 << 1 << false << 3;
            QTest::newRow("Returns -1 if the floors are the same") << 3 << 3 << true << -1;
            QTest::newRow("Returns -1 if the floors are the same") << 3 << 3 << false << -1;
            QTest::newRow("Returns -1 if the floor is above the last floor, but the direction is incorrect (false, down)") << 3 << 5 << false << -1;
            QTest::newRow("Returns -1 if the floor is below the last floor, but the direction is incorrect (true, up)") << 4 << 1 << true << -1;
        }

        void test_find_above_below_2() {

            QFETCH(int, last_floor);
            QFETCH(int, floor);
            QFETCH(bool, direction);
            QFETCH(int, expected);


            Elevator* e = ecs->getElevator(E_ID);
            ecs->moveElevator(E_ID, last_floor);
            e->addFloorRequest(last_floor);

            int result = ecs->findAboveBelow(e, floor, direction);
            qDebug() << "Distance: " << result;
            QCOMPARE(result, expected);
        }

        void test_find_above_below_elevator_data() {
            QTest::addColumn<int>("e1_last_floor");
            QTest::addColumn<int>("e2_last_floor");
            QTest::addColumn<int>("e3_last_floor");
            QTest::addColumn<int>("floor");
            QTest::addColumn<bool>("direction");
            QTest::addColumn<int>("expected_best_elevator_id");

            QTest::newRow("Returns nullptr if the floor is below all the elevators and the direction is true (up)") << 4 << 5 << 6 << 2 << true << -1;
            QTest::newRow("Returns nullptr if the floor is above all the elevators and the direction is false (down))") << 4 << 5 << 6 << 7 << false << -1;
            QTest::newRow("If only one elevator is below the floor and the direction is true (up), it returns that elevator") << 5 << 2 << 6 << 3 << true << 2;
            QTest::newRow("If only one elevator is above the floor and the direction is false (down), it returns that elevator") << 2 << 3 << 5 << 4 << false << 3;
        }

        void test_find_above_below_elevator() {
            QFETCH(int, e1_last_floor);
            QFETCH(int, e2_last_floor);
            QFETCH(int, e3_last_floor);
            QFETCH(int, floor);
            QFETCH(bool, direction);
            QFETCH(int, expected_best_elevator_id);

            Elevator* e1 = ecs->getElevator(1);
            Elevator* e2 = ecs->getElevator(2);
            Elevator* e3 = ecs->getElevator(3);

            e1->addFloorRequest(e1_last_floor);
            e2->addFloorRequest(e2_last_floor);
            e3->addFloorRequest(e3_last_floor);

            Elevator* e = ecs->findAboveBelowElevator({e1, e2, e3}, floor, direction);
            int id = -1;

            if (e == nullptr){
                qDebug() << "Elevator: none";
            }else{
                id = e->getId();
                qDebug() << "Elevator: " << id;
            }

            QCOMPARE(id, expected_best_elevator_id);
        }

        void test_find_passing_data() {
            QTest::addColumn<int>("cur_floor");
            QTest::addColumn<int>("next_floor_1");
            QTest::addColumn<int>("next_floor_2");
            QTest::addColumn<int>("floor");
            QTest::addColumn<bool>("direction");
            QTest::addColumn<int>("expected_distance");

            // Cases with 1 floor request in the queue
            QTest::addRow("If the requested floor is between the elevator's current (below) and next floor (above), and the direction is UP, then the distance is 0") << 2 << 4 << -1 << 3 << true << 0;
            QTest::addRow("If the requsted fllor is between the elevator's current (above) and next floor (below), and the direction is DOWN, then the distance is 0") << 4 << 2 << -1 << 3 << false << 0;
            QTest::addRow("If the requested floor is between the elevator's current (below) and next floor (above), and the direction is DOWN, then the distance is -1 (invalid)") << 2 << 4 << -1 << 3 << false << -1;
            QTest::addRow("If the requested floor is between the elevator's current (above) and next floor (below), and the direction is UP, then the distance is -1 (invalid)") << 4 << 2 << -1 << 3 << true << -1;

            // Cases with 2 floor requests in the queue
            QTest::addRow("If the cur floor is 2, the two floors in the queue are 3 and 5, the requested floor is 4, and the direction is UP then the distance is 1") << 2 << 3 << 5 << 4 << true << 1;
            QTest::addRow("If the cur floor is 7, the two floors in the queue are 5 and 1, the requested floor is 2, and the direction is DOWN, then the distance is 1") << 7 << 5 << 1 << 2 << false << 1;
            QTest::addRow("If the cur floor is 2, the two floors in the queue are 3 and 5, the requested floor is 4, and the direction is DOWN then the distance is -1") << 2 << 3 << 5 << 4 << false << -1;
            QTest::addRow("If the cur floor is 7, the two floors in the queue are 5 and 1, the requested floor is 2, and the direction is UP, then the distance is -1") << 7 << 5 << 1 << 2 << true << -1;
        }

        // Cases checking the current floor and the first (and only) floor in the floor request queue
        void test_find_passing() {
            QFETCH(int, cur_floor);
            QFETCH(int, next_floor_1);
            QFETCH(int, next_floor_2);
            QFETCH(int, floor);
            QFETCH(bool, direction);
            QFETCH(int, expected_distance);

            Elevator* e = ecs->getElevator(E_ID);
            ecs->moveElevator(e->getId(), cur_floor);
            e->addFloorRequest(next_floor_1);
            if (next_floor_2 > 0)
                e->addFloorRequest(next_floor_2);

            int result = ecs->findPassing(e, floor, direction);
            qDebug() << "Distance: " << result;
            QCOMPARE(result, expected_distance);
        }

};

QTEST_MAIN(TestElevatorControlSystem)
#include "tst_elevatorcontrolsystem.moc"
