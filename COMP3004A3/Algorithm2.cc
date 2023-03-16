#include "Algorithm2.h"

int Algorithm2::allocate(Elevator** elevators, int request_floor, int num_elevators){
    //allocate the elevator by randomly selecting an elevator and sending it to the request floor

    return ((rand()%num_elevators)+1);
}

