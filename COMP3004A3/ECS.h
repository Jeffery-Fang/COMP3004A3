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

    int serveFloor(int floor_number);
    //serveFloor() represents the ECS determining the optimal elevator and then sending it to the requesting floor
    void serveElevator(int elevator_number);
    //serveElevator() represents the ECS moving an elevator from it's current floor to it's destination floor
    //AKA serving the passengers request
    void moveElevator(int elevator_number);

    Elevator* getElevator(int elevator_number);

    void connect(int elevator_number, Passenger* p);

    void Fire(bool fromBuilding, int elevator_number);

    void powerOut();

private:

    int num_floors;
    int num_elevators;
    Floor** floors;
    Elevator** elevators;
    AllocationAlgorithm* AA;
};

#endif // ECS_H
