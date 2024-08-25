#include "door.h"

Door::Door():
closed(true)
{}

void Door::open(){
    closed = false;
}

void Door::close(){
    closed = true;
}

bool Door::getClosed(){
    return closed;
}

void Door::ringBell(){
    qInfo() << "*bell ring";
}
