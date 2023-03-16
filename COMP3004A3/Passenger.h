#ifndef PASSENGER_H
#define PASSENGER_H

#include "Floor.h"
#include "Elevator.h"

using namespace std;

class Passenger{
public:
    Passenger(int current_floor, int destination_floor, bool unconcious);
    //Passenger class represents a generic passenger which should a current floor, destination floor
    //and should be either concious or unconcious to specify if they will reply when prompted

    int pressFloorButton(Floor* cur_floor, ECS* owner);
    //pressFloorButton() simulates the passenger pressing a floor button at their current floor

    void pressElevatorButton(Elevator* cur_elevator, ECS* owner);
    //pressElevatorButton() simulates the passenger pressing a destination button in the elevator
    //that ser ved the floor request

    bool respond();
    //respond() simulates the passenger responding when prompted and it will depend on whether or
    //not the passenger is concious

private:

    int current_floor;
    int destination_floor;
    bool unconcious;
};

#endif // PASSENGER_H
