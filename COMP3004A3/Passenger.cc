#include "Passenger.h"
#include "Elevator.h"
#include "ECS.h"

using namespace std;

Passenger::Passenger(int current_floor, int destination_floor, bool unconcious):
current_floor(current_floor),destination_floor(destination_floor),unconcious(unconcious){

}

int Passenger::pressFloorButton(Floor* cur_floor, ECS* owner){
    return cur_floor->makeRequest(owner);
}

void Passenger::pressElevatorButton(Elevator* cur_elevator, ECS* owner){
    qInfo("Press destination button");
    cur_elevator->setDestination(this->destination_floor);
    qInfo("Destination set");
    owner->serveElevator(cur_elevator->getElevatorNumber());
}

bool Passenger::respond(){

    return !this->unconcious;
}


