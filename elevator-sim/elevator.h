#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "defs.h"

#include "door.h"

class Floor;
class Door;
class Passenger;
class ElevatorControlSystem;
class ElevatorPanel;

class Elevator
{
public:
    Elevator(const int id, Floor* startingFloor, ElevatorControlSystem* ecs);
    ~Elevator();

    // main functions
    bool close();// door controls
    bool open();
    void senseFloor(); // updates current floor pointer, represents a sensor
    bool addPassenger(Passenger* p);
    Passenger* removePassenger(const QString& name);
    void playMsg(const QString& msg);// simulates audio messages
    void ringBell();// simulates ringing the door bell

    // requests list functions for ecs to use (for encapsulation)
    // these allow the ecs to manipulate the requests vector to optimize handling of floor requests
    bool floorRequestsEmpty();// is empty
    void addFloorRequest(const int floor);// add to the back of the list
    void addFloorRequest(const int floor, const int i);// add to an index
    int getFloorRequest(const int i);
    int popFloorRequest();// pop the front and return the floor
    int floorRequestSize();// size of list
    void clearRequests();// remove everything in list, for safety features

    // getters and setters
    int getId();
    int getFloorNum();
    int getWeight();
    bool getObstacle();
    bool getDoorClosed();
    ElevatorPanel* getPanel();
    Floor* getCurFloor();

    void setCurFloor(Floor* f);
    void setFloor(int n);
    void setObstacle(bool blocked);

private:
    const int id;
    QVector<int> floorRequests;
    int floor;
    int weight;
    bool obstacle;
    Door door;
    ElevatorPanel* panel;
    QVector<Passenger*> passengers;
    Floor* curFloor;
    ElevatorControlSystem* ecs;
};

#endif
