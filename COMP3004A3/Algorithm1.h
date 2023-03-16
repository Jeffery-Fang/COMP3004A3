#ifndef ALGORITHM1_H
#define ALGORITHM1_H

#include "AllocationAlgorithm.h"

class Algorithm1: virtual public AllocationAlgorithm{
    //allocation will be determined by checking the destination floor of all elevators and determining
    //which one is closest to the floor requesting

public:
    int allocate(Elevator** elevators, int request_floor, int num_elevators);
    //Algorithm1 overrides the allocate method with the above described method of determining the
    //optimal elevator
};

#endif // ALGORITHM1_H
