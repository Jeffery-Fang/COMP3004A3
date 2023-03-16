#include "Elevator.h"
#include "ECS.h"
#include "Passenger.h"
#include <QtGlobal>
using namespace std;

Elevator::Elevator(){

}

Elevator::Elevator(int elevator_number, int current_floor, int destination_floor, bool obstructed, bool overloaded, bool door_open):
elevator_number(elevator_number), current_floor(current_floor), destination_floor(destination_floor), obstructed(obstructed), overloaded(overloaded), door_open(door_open){
    //set member class variables
}

void Elevator::move(){
    //move() moves the elevator from it's current floor to it's destination floor but also implements
    //the elevator being overloaded

    if(!this->detectOverloaded()){
        if(this->destination_floor == -1){
            //this elevator is idle

            qInfo("Elevator %d is idle", this->getElevatorNumber());
        }else{

            qInfo("Elevator %d moving",this->elevator_number);
            this->current_floor = this->destination_floor;
            this->destination_floor = -1;
            this->displayFloor();
            this->ring();
            this->open_door();
            qInfo("Waiting for 10 sec");
            this->close_door();

        }
    }else{
        this->display("Weight Warning: reduce the weight to proceed");
        this->announce("Weight Warning: reduce the weight to proceed");
        if(!this->detectOverloaded()){
            if(this->destination_floor == -1){
                //this elevator is idle

                qInfo("Elevator %d is idle", this->getElevatorNumber());
            }else{

                qInfo("Elevator %d moving",this->elevator_number);
                this->current_floor = this->destination_floor;
                this->destination_floor = -1;
                this->displayFloor();
                this->ring();
                this->open_door();
                qInfo("Waiting for 10 sec");
                this->close_door();

            }
        }else{
            this->display("Weight Warning: reduce the weight to proceed");
            this->announce("Weight Warning: reduce the weight to proceed");
        }
    }

}

void Elevator::setDestination(int destination_floor){
    //setDestination() just sets the destination floor to represent passenger selecting a destination

    this->destination_floor = destination_floor;
}

int Elevator::getElevatorNumber(){
    //getElevatorNumber() returns the elevator number and is used by the ECS to determine the optimal
    //elevators number

    return this->elevator_number;
}

int Elevator::getDestination(){
    //getDestination() returns the elevator destination and is used by the ECS to determine the optimal
    //elevator

    return this->destination_floor;
}

void Elevator::ring(){
    //ring() represents the ringing of the elevators bell so it will be used when the elevator serves a request

    qInfo("Bell rung");
}

void Elevator::display(char* message){
    //display() represents the display of this elevator

    qInfo("Elevator %d Display: %s" , this->elevator_number, message);
}

void Elevator::displayFloor(){
    //displayFloor() represents the usual case when the display is showing the current floor

    qInfo("Current Floor: %d", this->current_floor);
}

void Elevator::announce(char* message){
    //announce() represents the sound system of this elevator

    qInfo("Elevator %d Audio: %s" , this->elevator_number, message);
}

void Elevator::open_door(){
    //open_door() represents the elevator opening its door

    qInfo("Opening door");
    this->door_open = true;
}

void Elevator::close_door(){
    //close_door() represents the elevator closing its door and also implements if the door is obstructed

    if(!this->detectObstructed()){
        qInfo("Closing door");
        this->door_open = false;
    }else{
        qInfo("Door obstructed remove obstacle");
        qInfo("Wait 5 sec");
        if(!this->detectObstructed()){
            qInfo("Closing door");
            this->door_open = false;
        }else{
            this->display("Warning:Remove obstacle to continue");
            this->announce("Warning:Remove obstacle to continue");

        }
    }
}

int Elevator::detectLocation(){
    //detectLocation() represents the elevator signalling its sensor to get its location

    qInfo("Elevator %d detecting location", this->elevator_number);
    return this->current_floor;
}

bool Elevator::detectObstructed(){
    //detectObstructed() represents the elevator signalling its light sensor to detect obstructions

    if(this->obstructed){
        qInfo("Elevator %d detecting obstruction", this->elevator_number);
    }
    return this->obstructed;
}

bool Elevator::detectOverloaded(){
    //detectOverloaded() represents the elevator signalling its weight sensor to detect overloading

    if(this->overloaded){
        qInfo("Elevator %d detecting overload", this->elevator_number);
    }
    return this->overloaded;
}

void Elevator::helpRequested(ECS* owner, Passenger* p){
    //helpRequested represents the help button being pressed

    qInfo("Help button pressed");
    owner->connect(this->elevator_number,p);
}
