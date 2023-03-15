#include "Elevator.h"
#include <QtGlobal>
using namespace std;

Elevator::Elevator(int elevator_number, int current_floor, int destination_floor, bool obstructed, bool overloaded, bool door_open):
elevator_number(elevator_number), current_floor(current_floor), destination_floor(destination_floor), obstructed(obstructed), overloaded(overloaded), door_open(door_open){
    //set member class variables
}

void Elevator::ring(){
    //ring() represents the ringing of the elevators bell so it will be used when the elevator serves a request
    qInfo("Bell rung");
}

void Elevator::display(char* message){
    //display() represents the display of this elevator
    qInfo("Display: %s" , message);
}

void Elevator::announce(char* message){
    //announce() represents the sound system of this elevator
    qInfo("Audio: %s" , message);
}

void Elevator::open_door(){
    //open_door() represents the elevator opening its door
    qInfo("Opening door");
    this->door_open = true;
}

void Elevator::close_door(){
    //close_door() represents the elevator closing its door
    qInfo("Closing door");
    this->door_open = false;
}

int Elevator::detectLocation(){
    //detectLocation() represents the elevator signalling its sensor to get its location
    qInfo("Elevator %d detectic location", this->elevator_number);
    return this->destination_floor;
}

bool Elevator::detectObstructed(){
    //detectObstructed() represents the elevator signalling its light sensor to detect obstructions
    qInfo("Elevator %d detecting obstruction", this->elevator_number);
    return this->obstructed;
}

bool Elevator::detectOverloaded(){
    //detectOverloaded() represents the elevator signalling its weight sensor to detect overloading
    qInfo("Elevator %d detecting overload", this->elevator_number);
    return this->overloaded;
}
