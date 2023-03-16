#ifndef ALGORITHM2_H
#define ALGORITHM2_H

#include "AllocationAlgorithm.h"

class Algorithm2: virtual public AllocationAlgorithm{
    //allocation will be determined randomly meaning a random elevator will be selected to served that
    //floor request

public:
    int allocate(Elevator** elevators, int request_floor, int num_elevators);

};


#endif // ALGORITHM2_H
