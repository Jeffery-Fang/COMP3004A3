#ifndef ALLOCATIONALGORITHM_H
#define ALLOCATIONALGORITHM_H

#include "Elevator.h"

class AllocationAlgorithm{
public:
    virtual int allocate(Elevator** elevators, int request_floor, int num_elevators) = 0;
    //allocate is an algorithm for determining the optimal elevator given an array of elevators and a
    //request floor
private:

};

#endif // ALLOCATIONALGORITHM_H
