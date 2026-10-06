#ifndef UPANDDOWNPANEL_H
#define UPANDDOWNPANEL_H

#include "elevatorcontrolsystem.h"
class ElevatorControlSystem;

class UpAndDownPanel
{
public:
    UpAndDownPanel(ElevatorControlSystem* ecs);

    // main functions
    bool requestUp(const int floor);
    bool requestDown(const int floor);
    void cancelUp();
    void cancelDown();

private:
    bool up;
    bool down;
    ElevatorControlSystem* ecs;

};

#endif
