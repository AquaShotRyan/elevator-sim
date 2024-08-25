#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "defs.h"

#include "elevator.h"
#include "elevatorcontrolsystem.h"
#include "passenger.h"
#include "floor.h"

class Controller
{
public:
    Controller();
    ~Controller();

    void moveAllElevators();

    // elevator panel
    bool requestFloor(const int floor);// selected passenger requests a floor
    bool closeDoor();// selected passenger closes a door in an elevator
    bool openDoor();// selected passenger opens a door in an elevator
    bool clickHelp();// selected passenger clicks the help button in an elevator
    bool clickFire();// selected passenger clicks the fire button in an elevator

    // other passenger controls
    bool requestUp();
    bool requestDown();
    bool enterElevator();
    bool exitElevator();
    bool selectPassenger(const QString& name);// select a new selected passenger

    // admin controls
    void selectElevator(const int id);// select a new selected elevator
    bool blockDoor();
    void signalFire();
    void signalFire(Elevator* eOnFire);
    void signalPowerOut();

    // getters
    int getElevatorFloorNum(const int id);
    QString getPassengerInfo(const QString& name);
    int getWeight();
    int getCurElevatorFloorNum();// for elevator panel floor display
    int getCurElevatorId();// for elevator panel id display
    QVector<int> getRequestsList(const int eId);
    Passenger* getSelectedPassenger();

private:
    ElevatorControlSystem* ecs;
    QVector<Passenger*> passengers;
    Passenger* selectedPassenger;
    Elevator* selectedElevator;

    Elevator* getElevator(const int id);
    Passenger* getPassenger(const QString& name);

};

#endif
