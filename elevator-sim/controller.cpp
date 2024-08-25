#include "controller.h"

Controller::Controller():
selectedPassenger(nullptr), selectedElevator(nullptr), ecs(new ElevatorControlSystem(ELEVATORS, FLOORS))
{
    // hard coded 3 passengers for assignment
    Passenger* p1 = new Passenger("steve", 300, ecs->getFloor(1));
    Passenger* p2 = new Passenger("robin", 250, ecs->getFloor(1));
    Passenger* p3 = new Passenger("ryan", 160, ecs->getFloor(1));

    passengers.push_back(p1);
    passengers.push_back(p2);
    passengers.push_back(p3);
}

Controller::~Controller()
{
    for (int i=0; i<passengers.size(); ++i){
        delete passengers.at(i);
    }
    delete ecs;
}

/* ========private functions======== */
Elevator* Controller::getElevator(const int id)
{
    return ecs->getElevator(id);
}

Passenger* Controller::getPassenger(const QString &name)
{
    for (int i=0; i<passengers.size(); ++i){
        if (passengers.at(i)->getName() == name)
            return passengers.at(i);
    }
    return nullptr;
}

/* ========other functions======== */
void Controller::moveAllElevators()
{
    ecs->moveAllElevators();
}


/* ========getters======== */
int Controller::getElevatorFloorNum(const int id)
{
    Elevator* e = ecs->getElevator(id);
    if (e == nullptr) return -1;
    return e->getFloorNum();
}

QString Controller::getPassengerInfo(const QString &name)
{
    Passenger* p = getPassenger(name);
    if (p==nullptr) return "NULL";

    QString n = p->getName();
    QString fNum;
    QString eNum;
    QString weight = QString::number(p->getWeight());

    Floor* floor = p->getFloor();
    Elevator* elevator = p->getElevator();

    if (floor == nullptr) fNum = "NULL";
    else fNum = QString::number(floor->getFloorNum());
    if (elevator == nullptr) eNum = "NULL";
    else eNum = "e"+QString::number(elevator->getId());


    return "name: "+n+"\nweight: "+weight+"\nfloor: "+fNum+"\nelevator: "+eNum;
}

int Controller::getWeight()
{
    if (selectedElevator == nullptr) return -1;
    return selectedElevator->getWeight();
}

int Controller::getCurElevatorFloorNum()
{
    if (selectedPassenger == nullptr) return -1;
    if (selectedPassenger->getElevator() == nullptr) return -1;
    return selectedPassenger->getElevator()->getFloorNum();
}

int Controller::getCurElevatorId()
{
    if (selectedPassenger == nullptr) return -1;
    if (selectedPassenger->getElevator() == nullptr) return -1;
    return selectedPassenger->getElevator()->getId();
}

Passenger* Controller::getSelectedPassenger()
{
    return selectedPassenger;
}

/* ========elevator panel======== */
bool Controller::requestFloor(const int floor)
{
    if (selectedPassenger == nullptr) return false;
    return selectedPassenger->selectFloor(floor);
}

bool Controller::closeDoor()
{
    if (selectedPassenger == nullptr) return false;
    return selectedPassenger->pressClose();
}

bool Controller::openDoor()
{
    if (selectedPassenger == nullptr) return false;
    return selectedPassenger->pressOpen();
}

bool Controller::clickHelp()
{
    if (selectedPassenger == nullptr ) return false;
    return selectedPassenger->pressHelp();
}

bool Controller::clickFire()
{
    if (selectedPassenger == nullptr) return false;
    return selectedPassenger->pressFire();
}

QVector<int> Controller::getRequestsList(const int eId)
{
    QVector<int> list = {};
    Elevator* e = getElevator(eId);
    if (!e) return list;

    // add all requests to list
    for (int i=0; i<e->floorRequestSize(); ++i){
        list.push_back(e->getFloorRequest(i));
    }
    return list;
}

/* ========other passenger controls======== */
bool Controller::selectPassenger(const QString& name)
{
    selectedPassenger = getPassenger(name);
    if (selectedPassenger == nullptr)
        return false;
    return true;
}

bool Controller::requestUp()
{
    if (selectedPassenger == nullptr) return false;
    return selectedPassenger->requestElevatorUp();
}

bool Controller::requestDown()
{
    if (selectedPassenger == nullptr) return false;
    return selectedPassenger->requestElevatorDown();
}

bool Controller::enterElevator()
{
    if (selectedPassenger == nullptr) return false;
    return selectedPassenger->enterElevator();
}

bool Controller::exitElevator()
{
    if (selectedPassenger == nullptr) return false;
    return selectedPassenger->exitElevator();
}

/* ========admin controls======== */
void Controller::selectElevator(const int id)
{
    selectedElevator = ecs->getElevator(id);
}

bool Controller::blockDoor()
{
    if (selectedElevator == nullptr || selectedElevator->getObstacle() == true) return false;
    selectedElevator->setObstacle(true);
    return true;
}

void Controller::signalFire()
{
    ecs->signalFire();
}

void Controller::signalPowerOut()
{
    ecs->signalPowerOut();
}
