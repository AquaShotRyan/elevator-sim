#ifndef ELEVATORPANEL_H
#define ELEVATORPANEL_H

#include "defs.h"

class ElevatorControlSystem;
class Elevator;

class ElevatorPanel
{
public:
    ElevatorPanel(Elevator* elevator, ElevatorControlSystem* ecs);

    // main functions
    bool requestFloor(const int f);// use a button to request a floor
    bool openDoor();
    bool closeDoor();

    // safety
    void signalHelp();// use a button to signal for help
    void signalFire();// use a button to signal for fire

private:
    Elevator* elevator;
    ElevatorControlSystem* ecs;
};

#endif
