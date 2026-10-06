#ifndef ELEVATORCONTROLSYSTEM_H
#define ELEVATORCONTROLSYSTEM_H

#include "defs.h"
#include <cmath>
#include <QTimer>

class Floor;
class Passenger;
class Elevator;

class ElevatorControlSystem : public QObject{
    Q_OBJECT
public:
    ElevatorControlSystem(const int elevators, const int floors);
    ~ElevatorControlSystem();

    // main functions
    void moveAllElevators();// moves every elevator to the first request in its list
    void handleFloorRequest(const int floor, const bool direction);// adds a request from the floor (up and down panel) to an elevator
    void handleElevatorRequest(const int elevatorId, const int floor);// adds a request to an elevator from the elevator panel

    // safety functions
    void signalFire();// makes every elevator follow fire protocol
    void respondHelp(const int id);
    void signalPowerOut();// makes every elevator follow power out protocol

    // helper functions for moving an elevator
    bool moveElevator(const int id, const int floor);// moves a single elevator to a floor
    void fulfillRequest(const int id);// moves an elevator to the first request on its list
    bool checkWeight(const int weight);

    // floor adding optimization functions
    bool findDirection(Elevator* e);// finds the direction of an elevator

    int findFloorDistance(Elevator* e, const int floor);// returns position of floor in the requests queue, returns -1 if it's not in the queue
    Elevator* findShortestElevator(QVector<Elevator*> eList, const int floor);// finds the shortest floor distance if the elevator is already going to the floor

    int findAboveBelow(Elevator* e, const int floor, const bool direction);// returns the distance between the floor and last floor of an elevator if applicable
    Elevator* findAboveBelowElevator(QVector<Elevator*> eList, const int floor, const bool direction);// returns the shortest distance found from findAboveBelow function

    int findPassing(Elevator* e, const int floor, const bool direction);// return distance if an elevator passes the floor
    Elevator* findPassingElevator(QVector<Elevator*> eList, const int floor, const bool direction);// returns the shortest distance found from findPassing function

    Elevator* findBestElevator(const int floor, const bool direction);// uses above functions to find the opitimal elevator to add a request to

    void addFloorRequest(Elevator* e, const int floor, const bool direction);

    // getters
    Elevator* getElevator(const int id);
    Floor* getFloor(const int floor);
    int getTopFloor();

private:
    const int floorsNum;// number of floors in the building
    const int maxWeight;
    QVector<Elevator*> elevators;
    QVector<Floor*> floors;



public slots:
    void callEmergency();// simulates calling 911 in the help button protocol
};

#endif
