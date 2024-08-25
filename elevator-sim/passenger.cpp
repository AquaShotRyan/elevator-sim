#include "passenger.h"

#include "floor.h"
#include "elevator.h"
#include "elevatorpanel.h"

Passenger::Passenger(const QString& name, const int weight, Floor* startingFloor):
name(name), weight(weight), curFloor(startingFloor), curElevator(nullptr)
{
    startingFloor->addPassenger(this);
}

/* ========================main functions======================== */
bool Passenger::requestElevatorUp()
{
    if (curFloor == nullptr) return false;
    curFloor->requestUp();
    return true;
}

bool Passenger::requestElevatorDown()
{
    if (curFloor == nullptr) return false;
    curFloor->requestDown();
    return true;
}

bool Passenger::enterElevator()
{
    if (curFloor == nullptr) return false;

    // find any open elevator in the current floor
    Elevator* e = curFloor->findOpenElevator();
    if (e == nullptr) return false;

    // add passenger to elevator and remove self from floor
    e->addPassenger(curFloor->removePassenger(name));
    curElevator = e; // passenger is in the elevator
    curFloor = nullptr;// not in a floor anymore, represented by nullptr
    return true;
}

bool Passenger::exitElevator()
{
    if (curElevator == nullptr) return false;
    if (curElevator->getDoorClosed() == true) return false;

    // get the floor (object) the elevator is at
    Floor* floor = curElevator->getCurFloor();
    if (floor == nullptr) return false;

    // add passenger to floor and remove self from elevator
    floor->addPassenger(curElevator->removePassenger(name));
    curFloor = floor;
    curElevator = nullptr;
    return true;
}

bool Passenger::selectFloor(const int floor)
{
    if (curElevator == nullptr) return false;
    curElevator->getPanel()->requestFloor(floor);
    return true;
}

bool Passenger::pressHelp()
{
    if (curElevator == nullptr) return false;
    curElevator->getPanel()->signalHelp();
    return true;
}

bool Passenger::pressFire()
{
    if (curElevator == nullptr) return false;
    curElevator->getPanel()->signalFire();
    return true;
}

bool Passenger::pressClose()
{
    if (curElevator == nullptr) return false;
    curElevator->getPanel()->closeDoor();
    return true;
}

bool Passenger::pressOpen()
{
    if (curElevator == nullptr) return false;
    curElevator->getPanel()->openDoor();
    return true;
}

/* ========================getters and setters======================== */
QString Passenger::getName()
{
    return name;
}

int Passenger::getWeight()
{
    return weight;
}
Floor* Passenger::getFloor()
{
    return curFloor;
}
Elevator* Passenger::getElevator()
{
    return curElevator;
}

void Passenger::setFloor(Floor* floor)
{
    curFloor = floor;
}

void Passenger::setElevator(Elevator* elevator)
{
    curElevator = elevator;
}
