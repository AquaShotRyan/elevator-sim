#ifndef FLOOR_H
#define FLOOR_H

#include "defs.h"

#include "upanddownpanel.h"
class Elevator;
class Passenger;
class ElevatorControlSystem;

class Floor
{
public:
    Floor(ElevatorControlSystem* ecs, const int floorNum);

    // main functions
    void addPassenger(Passenger* p);
    Passenger* removePassenger(const QString& name);
    void addElevator(Elevator* e);
    bool removeElevator(const int id);
    bool requestUp();
    bool requestDown();
    void cancelUp();
    void cancelDown();
    Elevator* findOpenElevator();

    // getters
    int getFloorNum();

private:
    const int floorNum;
    UpAndDownPanel panel;
    QVector<Passenger*> passengers;// passengers in this floor
    QVector<Elevator*> elevators;// represents elevators stopped at this floor

};

#endif
