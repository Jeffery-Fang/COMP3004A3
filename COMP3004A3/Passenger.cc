#include "Passenger.h"
#include "Elevator.h"
#include "ECS.h"

using namespace std;

Passenger::Passenger(int current_floor, int destination_floor, bool unconcious):
current_floor(current_floor),destination_floor(destination_floor),unconcious(unconcious){
    //initialize the passengers member variables
}

int Passenger::pressFloorButton(Floor* cur_floor, ECS* owner){
    //When the passenger presses a floor button the current floor informs the ECS that a request
    //was made

    return cur_floor->makeRequest(owner);
}

void Passenger::pressElevatorButton(Elevator* cur_elevator, ECS* owner){
    //When the passenger presses a destination button in the elevator it should set the elevators
    //destination and the ECS will have serve the elevator

    qInfo("Press destination button");
    cur_elevator->setDestination(this->destination_floor);
    qInfo("Destination set");
    owner->serveElevator(cur_elevator->getElevatorNumber());
}

bool Passenger::respond(){
    //If the passenger is unconcious then they will not respond when prompted

    return !this->unconcious;
}


