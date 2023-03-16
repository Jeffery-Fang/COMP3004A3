#include "Floor.h"
#include <QtGlobal>
#include "ECS.h"
using namespace std;

Floor::Floor(){

}

Floor::Floor(int floor_number):floor_number(floor_number){
    //set member variables
}

int Floor::makeRequest(ECS* owner){
    //makeRequest() represents the floor button being pressed and sending that request to the ECS
    //this causes the ECS to allocate an elevator to this floor and once it arrives it turns off
    //the lit button

    qInfo("Floor button for floor %d is lit", this->floor_number);
    int temp = owner->serveFloor(this->floor_number);
    qInfo("Floor button for floor %d is unlit", this->floor_number);
    return temp;
}


