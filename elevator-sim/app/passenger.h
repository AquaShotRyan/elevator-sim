#ifndef PASSENGER_H
#define PASSENGER_H

#include "defs.h"

class Elevator;
class Floor;
class ElevatorPanel;


class Passenger
{
public:
    Passenger(const QString& name, const int weight, Floor* startingFloor);

    // main functions
    bool requestElevatorUp();// use the up and down panel
    bool requestElevatorDown();
    bool enterElevator();
    bool exitElevator();
    bool selectFloor(const int floor);// use a floor button inside an elevator
    bool pressHelp();
    bool pressFire();
    bool pressClose();
    bool pressOpen();

    // getters and setters
    QString getName();
    int getWeight();
    Floor* getFloor();
    Elevator* getElevator();

    void setFloor(Floor* floor);
    void setElevator(Elevator* elevator);

private:
    QString name;
    const int weight;
    Floor* curFloor;// reference to floor passenger is in
    Elevator* curElevator;// reference to elevator passenger is in

};

#endif
