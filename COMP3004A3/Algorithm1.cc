#include "Algorithm1.h"
#include "Elevator.h"

using namespace std;

int Algorithm1::allocate(Elevator** elevators, int request_floor, int num_elevators){
    //allocate the elevator by determining the closest elevator to the request floor once each
    //elevator has arrived at their destination floor

    int min = 9999;
    int min_index = 1;

    for(int i = 1; i < num_elevators; i++){
        if(abs(request_floor - elevators[i]->detectLocation()) < min){
            min = elevators[i]->detectLocation();
            min_index = i;
        }
    }

    if(min < 0 || min == 9999){
        return 1;
    }

    return min_index;
}
