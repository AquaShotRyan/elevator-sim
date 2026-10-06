#ifndef DOOR_H
#define DOOR_H

#include "defs.h"

class Door{

public:
    Door();

    // main functions
    void open();
    void close();
    void ringBell();// redundant, for simulation purposes

    // getters
    bool getClosed();

private:
    bool closed;


};


#endif
