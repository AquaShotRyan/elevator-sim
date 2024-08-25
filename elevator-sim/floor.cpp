#include "floor.h"

#include "passenger.h"
#include "elevator.h"
#include "elevatorcontrolsystem.h"

Floor::Floor(ElevatorControlSystem* ecs, const int floorNum):
panel(ecs), floorNum(floorNum)
{
}

/* ========================main functions======================== */
void Floor::addPassenger(Passenger* p)
{
    passengers.push_back(p);
}

Passenger* Floor::removePassenger(const QString& name)
{
    // find passenger by name and remove them
    for (int i=0; i<passengers.size(); ++i){
        if (passengers.at(i)->getName().compare(name) == 0){
            Passenger* p = passengers.at(i);
            passengers.erase(passengers.begin() + i);
            return p;
        }
    }
    // if passenger doesn't exist, return nullptr
    return nullptr;
}

void Floor::addElevator(Elevator* e)
{
    elevators.push_back(e);
}

bool Floor::removeElevator(const int id)
{
    // find elevator by id and remove them
    for (int i=0; i<elevators.size(); ++i){
        if (elevators.at(i)->getId() == id){
            elevators.erase(elevators.begin() + i);
            return true;
        }
    }
    // if elevator doesn't exist, return nullptr
    return false;
}

bool Floor::requestUp()
{
    return panel.requestUp(floorNum);
}

bool Floor::requestDown()
{
    return panel.requestDown(floorNum);
}

void Floor::cancelUp()
{
    panel.cancelUp();
}

void Floor::cancelDown()
{
    panel.cancelUp();
}

Elevator* Floor::findOpenElevator()
{
    // find an elevator on the floor where the door is opened
    for (int i=0; i<elevators.size(); ++i){
        if (elevators.at(i)->getDoorClosed() == false){
            return elevators.at(i);
        }
    }
    // if not open elevators found, return nullptr
    return nullptr;
}

/* ========================getters======================== */
int Floor::getFloorNum()
{
    return floorNum;
}
