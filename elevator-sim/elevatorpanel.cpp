#include "elevatorpanel.h"

#include "elevator.h"
#include "elevatorcontrolsystem.h"

ElevatorPanel::ElevatorPanel(Elevator* elevator, ElevatorControlSystem* ecs):
elevator(elevator), ecs(ecs)
{
}

bool ElevatorPanel::requestFloor(const int f)
{
    // send request to ecs
    ecs->handleElevatorRequest(elevator->getId(), f);
    return true;
}

bool ElevatorPanel::openDoor()
{
    return elevator->open();
}

bool ElevatorPanel::closeDoor()
{
    return elevator->close();
}

void ElevatorPanel::signalHelp()
{
    // send signal to ecs
    ecs->respondHelp(elevator->getId());
}

void ElevatorPanel::signalFire()
{
    // send signal to ecs
    ecs->signalFire();
}
