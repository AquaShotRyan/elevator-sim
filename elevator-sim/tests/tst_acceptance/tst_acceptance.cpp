#include <QtTest>
#include <../../app/controller.h>
#include <../../app/elevatorcontrolsystem.h>
#include <../../app/elevator.h>
#include <../../app/floor.h>

class TestAcceptance : public QObject {
    Q_OBJECT
    Controller* controller;
    private slots:
        void init() {
            qDebug() << "Setting up test...";
            controller = new Controller();
        }

        void cleanup() {
            qDebug() << "Cleaning up test...";
            delete controller;
        }

        void using_an_elevator() {
            Passenger* p;
            Elevator* e;

            controller->selectPassenger("ryan");
            p = controller->getSelectedPassenger();
            qDebug() << "Selected passenger " << p->getName();

            QCOMPARE(p->getFloor()->getFloorNum(), 1);
            qDebug() << "Verified passenger is on floor 1";

            controller->requestUp();
            qDebug() << "Passenger requested an elevator with the up button";

            controller->moveAllElevators();
            qDebug() << "Updated elevator positions";

            bool enterElevator = controller->enterElevator();
            qDebug() << "Passenger entered an elevator";

            QCOMPARE(enterElevator, true);
            qDebug() << "Verified passenger is in elevator";
            controller->selectElevator(1);
            e = controller->getSelectedElevator();
            qDebug() << "Verifying elevator 1 contains 1 passenger";
            QCOMPARE(e->getPassengersSize(), 1);
            qDebug() << "Verified passenger contains 1 passenger";

            int weight = controller->getWeight();
            QCOMPARE(weight, 160);
            qDebug() << "Verified elevator weight is " << weight;

            controller->requestFloor(5);
            qDebug() << "Requested floor 5";

            controller->moveAllElevators();
            qDebug() << "Updated elevator positions";

            QCOMPARE(controller->getCurElevatorFloorNum(), 5);
            qDebug() << "Verified elevator moved to floor 5";

            controller->exitElevator();
            qDebug() << "Exited elevator";

            QCOMPARE(e->getPassengersSize(), 0);
            qDebug() << "Verified elevator has 0 passengers";
            QCOMPARE(controller->getWeight(), 0);
            qDebug() << "Verified weight of elevator is 0";
            QCOMPARE(p->getFloor()->getFloorNum(), 5);
            qDebug() << "Verified passenger is on floor 5";
        }

        void the_help_alarm() {
            Passenger* p;

            controller->selectPassenger("ryan");
            p = controller->getSelectedPassenger();
            qDebug() << "Selected passenger " << p->getName();

            controller->requestUp();
            qDebug() << "Passenger requested an elevator with the up button";

            controller->moveAllElevators();
            qDebug() << "Updated elevator positions";

            controller->enterElevator();
            qDebug() << "Passenger entered an elevator";

            // Check manually for text output
            controller->clickHelp();
            qDebug() << "Passenger clicked help button";
        }

        void the_light_sensor_is_interrupted() {
            Passenger* p;
            Elevator* e;

            controller->selectPassenger("ryan");
            p = controller->getSelectedPassenger();
            qDebug() << "Selected passenger " << p->getName();

            controller->requestUp();
            qDebug() << "Passenger requested an elevator with the up button";

            controller->moveAllElevators();
            qDebug() << "Updated elevator positions";

            controller->enterElevator();
            qDebug() << "Passenger entered an elevator";

            controller->selectElevator(1);
            e = controller->getSelectedElevator();

            QCOMPARE(controller->blockDoor(), true);
            qDebug() << "An obstacle appeared, blocking the elevator door";

            controller->closeDoor();
            qDebug() << "Attempted to close the door";

            QCOMPARE(e->getDoorClosed(), false);
            qDebug() << "Verifying that the door is still open";
        }

        void the_fire_alarm() {
            Passenger* p;

            controller->selectPassenger("ryan");
            p = controller->getSelectedPassenger();
            qDebug() << "Selected passenger " << p->getName();

            controller->requestUp();
            qDebug() << "Passenger requested an elevator with the up button";

            controller->moveAllElevators();
            qDebug() << "Updated elevator positions";

            controller->enterElevator();
            qDebug() << "Passenger entered an elevator";

            // Check text output manually
            controller->signalFire();
            qDebug() << "Fire alarm signalled";
        }

        void the_overload_alarm() {
            controller->selectPassenger("steve");
            qDebug() << "Selected passenger " << controller->getSelectedPassenger()->getName();

            controller->requestUp();
            qDebug() << "Passenger requested an elevator with the up button";

            controller->moveAllElevators();
            qDebug() << "Updated elevator positions";

            controller->enterElevator();
            qDebug() << controller->getSelectedPassenger() << " has entered the elevator";

            controller->selectPassenger("robin");
            qDebug() << "Selected passenger " << controller->getSelectedPassenger()->getName();

            controller->enterElevator();
            qDebug() << controller->getSelectedPassenger() << " has entered the elevator";

            controller->requestFloor(4);
            qDebug() << "Requested floor 4";

            // Check text output manually for overload msg
            controller->moveAllElevators();
            qDebug() << "Attempted to update elevator positions";

            controller->selectElevator(1);
            QCOMPARE(controller->getCurElevatorFloorNum(), 1);
            qDebug() << "Verified elevator is still on floor 1";
        }

        void the_power_out_alarm() {
            Passenger* p;

            controller->selectPassenger("ryan");
            p = controller->getSelectedPassenger();
            qDebug() << "Selected passenger " << p->getName();

            controller->requestUp();
            qDebug() << "Passenger requested an elevator with the up button";

            controller->moveAllElevators();
            qDebug() << "Updated elevator positions";

            controller->enterElevator();
            qDebug() << "Passenger entered an elevator";

            // Check text output manually
            controller->signalPowerOut();
            qDebug() << "Power out alarm sounded";
        }
};

QTEST_MAIN(TestAcceptance)
#include "tst_acceptance.moc"
