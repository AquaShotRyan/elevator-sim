#include "elevatorcontrolsystem.h"
#include "elevator.h"
#include "passenger.h"
#include "floor.h"

ElevatorControlSystem::ElevatorControlSystem(const int elevatorsNum, const int floorsNum):
floorsNum(floorsNum), maxWeight(MAX_WEIGHT)
{
    for (int i=0; i<floorsNum; ++i){// initialize number of floors
        floors.push_back(new Floor(this, i+1));
    }

    for (int i=0; i<elevatorsNum; ++i){// initialize number of elevators
        elevators.push_back(new Elevator(i+1, floors.first(), this));
    }
}

ElevatorControlSystem::~ElevatorControlSystem(){
    for (int i=0; i<floors.size(); ++i){
        delete floors.at(i);
    }
    for (int i=0; i<elevators.size(); ++i){
        delete elevators.at(i);
    }
}

/* =============getters============= */
Elevator* ElevatorControlSystem::getElevator(const int id){
    for (int i=0; i<elevators.size(); ++i){
        if (elevators.at(i)->getId() == id) return elevators.at(i);
    }
    return nullptr;
}

Floor* ElevatorControlSystem::getFloor(const int floor)
{
    for (int i=0; i<floors.size(); ++i){
        if (floors.at(i)->getFloorNum() == floor)
           return floors.at(i);
    }
    return nullptr;
}

int ElevatorControlSystem::getTopFloor()
{
    return floorsNum;
}

/* =============main ecs functions=============*/
void ElevatorControlSystem::moveAllElevators()
{
    int id;
    for (int i = 0; i<elevators.size(); ++i)
    {
        id = i+1;
        fulfillRequest(id);
    }
}

void ElevatorControlSystem::fulfillRequest(const int id)
{
    Elevator* e = getElevator(id);
    if (e == nullptr) return;

    // check for requests in list
    if (e->floorRequestsEmpty()){
        e->close();
        return;
    }

    // move the elevator to front most request in list
    if (moveElevator(id, e->getFloorRequest(0)))
        e->popFloorRequest();
}

void ElevatorControlSystem::handleFloorRequest(const int floor, const bool direction)
{   

    for (int i=0; i<elevators.size(); ++i){
        // an elevator is already on the floor
        if (elevators.at(i)->getFloorNum() == floor){
            if (elevators.at(i)->getDoorClosed() == false) return;// door already open for guest to exit, don't add the request
            elevators.at(i)->addFloorRequest(floor);
            return;
        }
    }

    // find optimal elevator to give floor to and add the floor to the elevator
    Elevator* bestElevator = findBestElevator(floor, direction);
    addFloorRequest(bestElevator, floor, direction);
    return;
}

void ElevatorControlSystem::handleElevatorRequest(const int elevatorId, const int floor) // not optimal, work on later
{
    Elevator* e = getElevator(elevatorId);

    // if already on floor, dont add
    if (e->getFloorNum() == floor) return;

    // if  no requests, just add the floor to the end
    if (e->floorRequestSize() == 0){
        e->addFloorRequest(floor);
        return;
    }

    addFloorRequest(e, floor, findDirection(e));
}

/* =============safety functions============= */
bool ElevatorControlSystem::checkWeight(const int weight)
{
    if (weight > MAX_WEIGHT) return false;
    return true;
}

void ElevatorControlSystem::signalFire()
{
    qInfo("Fire Alarm Sounded");
    // move all elevators to safe floor
    for(int i=0; i<elevators.size(); ++i){
        Elevator* e = elevators.at(i);
        e->clearRequests();
        e->addFloorRequest(1);// safe floor is floor 1
        e->playMsg("Evacuate the elevator when on a safe floor and exit the building");
    }
}

void ElevatorControlSystem::respondHelp(const int id)
{
    Elevator* e = getElevator(id);
    if (!e){
        qInfo("help is not coming");
        return;
    }
    e->clearRequests();// elevator should stay still while it waits for help
    qInfo() << "help signal called for elevator " << QString::number(id) << ", attempting to connect to building safety services";
    QTimer::singleShot(5000, this, &ElevatorControlSystem::callEmergency);
}

void ElevatorControlSystem::callEmergency()
{
    qInfo("911 dialed (after 5s)");
}

void ElevatorControlSystem::signalPowerOut()
{
    for (int i=0; i<elevators.size(); ++i){
        Elevator* e = elevators.at(i);
        e->clearRequests();
        e->addFloorRequest(1);// safe floor is floor 1
        e->playMsg("A power outage has occured. Evacuate the elevator when on a safe floor");
    }
}

/* =============Helper Functions============= */
bool ElevatorControlSystem::moveElevator(const int id, const int floor)// check for obstacles later
{
    Elevator* e = getElevator(id);
    if (e == nullptr || floor > floorsNum || floor < 1) return false;

    // check weight
    if (checkWeight(e->getWeight()) == false){
        e->playMsg("elevator is overweight, please unload some passengers and the elevator will attemp to move again");
        return false;
    }

    // close door
    if (!e->close()){
        e->playMsg("obstacle blocking door, cannot proceed");
        return false;
    }

    // remove elevator from floor
    e->getCurFloor()->removeElevator(id);

    // set elevator's new floor
    e->setFloor(floor);
    e->senseFloor();// could just give it the new floor pointer directly, but this is for the sake of simulating real life sensors

    // add elevator to new floor
    e->getCurFloor()->addElevator(e);

    // unilluminate the up and down buttons
    e->getCurFloor()->cancelDown();
    e->getCurFloor()->cancelUp();

    // open door
    e->open();
    e->ringBell();
    return true;
}

bool ElevatorControlSystem::findDirection(Elevator* e)
{
    if (e->getFloorNum() < e->getFloorRequest(0))
        return true;
    else
        return false;
}

int ElevatorControlSystem::findFloorDistance(Elevator *e, const int floor)
{
    int distance = 0;
    for (int i=0; i<e->floorRequestSize(); ++i){
        if (e->getFloorRequest(i) == floor || e->getFloorNum() == floor)
            return distance;
        distance++;
    }
    return -1;
}

Elevator* ElevatorControlSystem::findShortestElevator(QVector<Elevator*> eList, const int floor)
{
    Elevator* bestElevator = nullptr;

    for (int i=0; i<eList.size(); ++i){
        Elevator* curElevator = eList.at(i);
        int findResult = findFloorDistance(curElevator, floor);

        if (findResult != -1 && bestElevator == nullptr)
            bestElevator = curElevator;
        else if (bestElevator != nullptr){
            if (findResult < findFloorDistance(bestElevator, floor) && findResult != -1)
                bestElevator = curElevator;
        }
    }
    return bestElevator;
}

int ElevatorControlSystem::findAboveBelow(Elevator *e, const int floor, const bool direction)
{
    if (e->floorRequestSize() == 0) return -1;

    int lastFloor = e->getFloorRequest(e->floorRequestSize()-1);

    if (direction == true){
        if (lastFloor < floor)
            return floor - lastFloor;
        return -1;
    }else{
        if (lastFloor > floor)
            return lastFloor - floor;
        return -1;
    }
}

Elevator* ElevatorControlSystem::findAboveBelowElevator(QVector<Elevator*> eList, const int floor, const bool direction)
{
    Elevator* bestElevator = nullptr;
    int findResult;
    for(int i=0; i<eList.size(); ++i){
        findResult = findAboveBelow(eList.at(i), floor, direction);

        if (findResult != -1 && bestElevator == nullptr)
            bestElevator = eList.at(i);
        else if (bestElevator != nullptr){
            if (findResult < findAboveBelow(bestElevator, floor, direction) && findResult != -1)
                bestElevator = eList.at(i);
        }
    }
    return bestElevator;
}

int ElevatorControlSystem::findPassing(Elevator* e, const int floor, const bool direction)
{
    int distance = 0;

    // If the elevator is going up
    if (direction == true){
        // If the elevator's current floor is BELOW the floor requested AND the elevator's next floor is ABOVE the requested floor
        if (e->getFloorNum() < floor && floor < e->getFloorRequest(0))
            return distance;

        // Find distance (pos in queue) until the elevator's floors will pass requested floor
        if (e->floorRequestSize() > 1){
            for (int i=0; i<e->floorRequestSize(); ++i){
                ++distance;
                if (e->getFloorRequest(i+1) < 1)
                    break;
                if (e->getFloorRequest(i) < floor && floor < e->getFloorRequest(i+1))
                    return distance;
            }
        }

        return -1;

    }else{
        // If the elevator's current floor is ABOVE the floor requested AND the elevat's next floor is BELOW the requested floor
        if (e->getFloorNum() > floor && floor > e->getFloorRequest(0))
            return distance;

        // Find distance (pos in queue) until the elevator's floors will pass requested floor
        if (e->floorRequestSize() > 1){
            for (int i=0; i<e->floorRequestSize(); ++i){
                ++distance;
                if (e->getFloorRequest(i+1) < 1) // accessing an int index out of bounds returns -1
                    break;
                if (e->getFloorRequest(i) > floor && floor > e->getFloorRequest(i+1))
                    return distance;
            }
        }

        return -1;
    }
}

Elevator* ElevatorControlSystem::findPassingElevator(QVector<Elevator*> eList, const int floor, const bool direction)
{
    Elevator* bestElevator = nullptr;
    int findResult;
    for (int i=0; i<eList.size(); ++i){
        findResult = findPassing(eList.at(i), floor, direction);
        if (findResult != -1 && bestElevator == nullptr)
            bestElevator = eList.at(i);
        else if (bestElevator != nullptr){
            if (findResult < findPassing(bestElevator, floor, direction && findResult != -1))
                bestElevator = eList.at(i);
        }
    }
    return bestElevator;
}

Elevator* ElevatorControlSystem::findBestElevator(const int floor, const bool direction)
{
    QVector<Elevator*> elevatorsSameDirection;

    // get all elevators going in the same diretion
    for (int i=0; i<elevators.size(); ++i){
        if (elevators.at(i)->floorRequestSize() != 0){
            if (findDirection(elevators.at(i)) == direction)
                elevatorsSameDirection.push_back(elevators.at(i));
        }
    }

    Elevator* bestElevator = nullptr;

    // use idle elevators first
    for (int i=0; i<elevators.size(); ++i){     
        if (elevators.at(i)->floorRequestSize() == 0)
            return elevators.at(i);
    }

    // use elevators going in the same direction
    bestElevator = findShortestElevator(elevatorsSameDirection, floor);
    if (bestElevator != nullptr)
        return bestElevator;
    bestElevator = findPassingElevator(elevatorsSameDirection, floor, direction);
    if (bestElevator != nullptr)
        return bestElevator;
    bestElevator = findAboveBelowElevator(elevatorsSameDirection, floor, direction);
    if (bestElevator != nullptr)
        return bestElevator;

    // if all elevators only going opposite directions, get elevator whose last floor is closest
    bestElevator = elevators.at(0);
    int lastElevatorRequest;
    int lastBestElevatorRequest;
    for (int i=0; i<elevators.size(); ++i){
        lastElevatorRequest = elevators.at(i)->getFloorRequest(elevators.at(i)->floorRequestSize()-1);
        lastBestElevatorRequest = bestElevator->getFloorRequest(bestElevator->floorRequestSize() - 1);
        if (abs(lastElevatorRequest - floor) < abs(lastBestElevatorRequest - floor))
            bestElevator = elevators.at(i);
    }
    return bestElevator;
}

void ElevatorControlSystem::addFloorRequest(Elevator *e, const int floor, const bool direction)
{
    int size = e->floorRequestSize();
    // if already on list, don't add
    for (int i=0; i<size; ++i){
        if (e->getFloorRequest(i) == floor)
            return;
    }

    // add elevator into list
    if (findDirection(e) == true){
        if (direction == true){
            if (floor > e->getFloorNum()){
                // add in sorted order
                for (int i=0; i<size; ++i){
                    if (e->getFloorRequest(i) > floor){
                        e->addFloorRequest(floor, i);
                        return;
                    }
                }
            }
        }
        e->addFloorRequest(floor);
        return;
    }else{
        if (direction == false){
            if (floor < e->getFloorNum()){
                for (int i=0; i<size; ++i){
                    if (e->getFloorRequest(i) < floor){
                        e->addFloorRequest(floor, i);
                        return;
                    }
                }
            }
        }
        e->addFloorRequest(floor);
        return;
    }
}
