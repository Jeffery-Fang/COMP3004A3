#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <iostream>
#include <QtGlobal>

using namespace std;

class Passenger;
class ECS;

class Elevator{

public:
    Elevator();
    Elevator(int elevator_number, int current_floor, int destination_floor, bool obstructed, bool overloaded, bool door_open);

    void move();

    void setDestination(int destination_floor);

    int getElevatorNumber();

    int getDestination();

    void ring();
    //ring represents the ringing of the elevator bell

    void display(char* message);
    //display() represents the display system of the elevator

    void displayFloor();

    void announce(char* message);
    //announce() represents the sound system of the elevator

    void open_door();
    //open_door() represents the opening of the elevator door

    void close_door();
    //close_door() represents the closing of the elevator door

    int detectLocation();
    //detectLocation returns the destination_floor as this simulation assumes that elevators arrive at a destination then handle a floor request and repeat

    bool detectObstructed();
    //detectObstructed returns the obstructed variable

    bool detectOverloaded();
    //detectOverloaded returns the overloaded variable

    void helpRequested(ECS* owner, Passenger* p);

private:
    int elevator_number;
    int current_floor;              //current_floor represents the floor that the elevator is currently on
    int destination_floor;          //destination_floor represents the floor that the elevator is going to
    bool obstructed;                //obstructed represents whether or not the door is blocked
    bool overloaded;                //overloaded represents whether or not the elevator is overloaded
    bool door_open;                 //door_open represents whether or not the elevator door is open
};

#endif // ELEVATOR_H
