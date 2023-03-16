#ifndef ECS_H
#define ECS_H

#include "Elevator.h"
#include "Floor.h"
#include "AllocationAlgorithm.h"
#include "Algorithm1.h"
#include "Algorithm2.h"
#include <iostream>
#include <QtGlobal>

using namespace std;
class ECS{
public:
    ECS(int num_floors, int num_elevators, int algorithmnum);
    ~ECS();
    //ECS class simulates the ECS with num_floors determining the number of floors num_elevators determining
    //the number of elevators and algorithmnum determing the allocation algorithm by having these variables
    //we support different numbers of elevators and floors and different allocation algorithms

    int serveFloor(int floor_number);
    //serveFloor() represents the ECS determining the optimal elevator and then sending it to the requesting floor

    void serveElevator(int elevator_number);
    //serveElevator() represents the ECS moving an elevator from it's current floor to it's destination floor
    //AKA serving the passengers request

    Elevator* getElevator(int elevator_number);
    //get elevator is used by other classes to get an elevator once it has been allocated

    void connect(int elevator_number, Passenger* p);
    //connect() simulates connecting the audio system of a given elevator to safety services

    void Fire(bool fromBuilding, int elevator_number);
    //Fire() simulates the ECS receiving a fire signal either from the building or a specific elevator

    void powerOut();
    //powerOut() simulates the ECS receiving a power out signal

private:
    //floors, elevators and AA result in the ECS being able to support variable numbers of floors
    //elevators and different allocation algorithms

    int num_floors;
    int num_elevators;
    Floor** floors;
    Elevator** elevators;
    AllocationAlgorithm* AA;
};

#endif // ECS_H
