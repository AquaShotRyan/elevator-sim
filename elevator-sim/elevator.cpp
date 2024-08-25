#include "elevator.h"

#include "elevatorpanel.h"
#include "floor.h"
#include "passenger.h"
#include "elevatorcontrolsystem.h"

Elevator::Elevator(const int id, Floor* startingFloor, ElevatorControlSystem* ecs):
id(id),
curFloor(startingFloor),
weight(0),
floor(startingFloor->getFloorNum()),
obstacle(false), panel(new ElevatorPanel(this, ecs)),
door(Door()),
ecs(ecs)
{}

Elevator::~Elevator()
{
    delete panel;
}
/* ======================main functions====================== */
bool Elevator::close()
{
    if (obstacle) return false;
    door.close();
    return true;
}
bool Elevator::open()
{
    door.open();
    return true;
}

void Elevator::senseFloor()
{
    curFloor = ecs->getFloor(floor);
}

bool Elevator::addPassenger(Passenger *p)
{
    passengers.push_back(p);
    weight += p->getWeight();
    return true;
}

Passenger* Elevator::removePassenger(const QString& name)
{
    // find index of passenger in elevator's passenger list
    int index = -1;
    for (int i=0; i<passengers.size(); ++i){// find passenger index
        if (passengers.at(i)->getName() == name){
            index = i;
        }
    }
    if (index == -1) return nullptr;

    // remove and return the passenger
    Passenger* p = passengers.at(index);
    passengers.removeAt(index);
    weight -= p->getWeight();
    return p;
}

void Elevator::playMsg(const QString &msg)
{
    qInfo() << "elevator " << QString::number(id) << ": " << msg;
}

void Elevator::ringBell()
{
    door.ringBell();
}

/* ======================floor request functions====================== */
bool Elevator::floorRequestsEmpty()
{
    return floorRequests.empty();
}

void Elevator::addFloorRequest(const int floor)
{
    for (int i=0; i<floorRequests.size(); ++i){
        if (floor == floorRequests.at(i)) return;
    }
    floorRequests.push_back(floor);
}

void Elevator::addFloorRequest(const int floor, const int i)
{
    for (int i=0; i<floorRequests.size(); ++i){
        if (floor == floorRequests.at(i)) return;
    }
    floorRequests.insert(floorRequests.begin() + i, floor);
}

int Elevator::getFloorRequest(const int i){// add validation later
    if (i < 0 || i >= floorRequestSize()) return -1;
    return floorRequests.at(i);
}

int Elevator::popFloorRequest()
{
    int f = floorRequests.at(0);
    floorRequests.pop_front();
    return f;
}

int Elevator::floorRequestSize()
{
    return floorRequests.size();
}

void Elevator::clearRequests()
{
    floorRequests.clear();
}

/* ======================getters and setters====================== */
int Elevator::getId()
{
    return id;
}

int Elevator::getFloorNum()
{
    return floor;
}

int Elevator::getWeight()
{
    return weight;
}

bool Elevator::getObstacle()
{
    return obstacle;
}

bool Elevator::getDoorClosed()
{
    return door.getClosed();
}

ElevatorPanel* Elevator::getPanel()
{
    return panel;
}

Floor* Elevator::getCurFloor()
{
    return curFloor;
}

void Elevator::setFloor(int n)
{
    floor = n;
}

void Elevator::setCurFloor(Floor *f)
{
    curFloor = f;
}

void Elevator::setObstacle(bool blocked)
{
    obstacle = blocked;
}
