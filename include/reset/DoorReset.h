#pragma once

#include "Reset.h"

class DoorReset : public Reset {
public:
    DoorReset( std::shared_ptr< Room > room, int doorNumber, std::string newDoorState );
    ~DoorReset( );

    virtual void performReset( );

private:
    int doorNumber;
    std::string newDoorState;
};
