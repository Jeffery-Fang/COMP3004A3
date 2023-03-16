#ifndef PASSENGER_H
#define PASSENGER_H

#include "Floor.h"
#include "Elevator.h"

using namespace std;

class Passenger{
public:
    Passenger(int current_floor, int destination_floor, bool unconcious);
    int pressFloorButton(Floor* cur_floor, ECS* owner);
    void pressElevatorButton(Elevator* cur_elevator, ECS* owner);
    bool respond();

private:
    int current_floor;
    int destination_floor;
    bool unconcious;
};

#endif // PASSENGER_H
