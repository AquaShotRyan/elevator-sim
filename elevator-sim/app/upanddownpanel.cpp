#include "upanddownpanel.h"

UpAndDownPanel::UpAndDownPanel(ElevatorControlSystem* ecs):
ecs(ecs), up(false), down(false)
{   
}

bool UpAndDownPanel::requestUp(const int floor)
{
    // check if it's already requested or on the top floor
    if (up == true || floor == ecs->getTopFloor()) return false;

    // send request to ecs
    ecs->handleFloorRequest(floor, true);
    up = true;
    return true;
}

bool UpAndDownPanel::requestDown(const int floor)
{
    // check if it's already requested or on the first floor
    if (down == true || floor == 1) return false;

    // send request to ecs
    ecs->handleFloorRequest(floor, false);
    down = true;
    return true;
}

void UpAndDownPanel::cancelUp()
{
    up = false;
}

void UpAndDownPanel::cancelDown()
{
    down = false;
}
