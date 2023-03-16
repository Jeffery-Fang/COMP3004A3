#include "ECS.h"
#include "Passenger.h"

#include <iostream>
#include <QtGlobal>
using namespace std;

ECS::ECS(int num_floors, int num_elevators, int algorithmnum){
    //initialize the ECS by allocating a user specified number of floors and elevators
    //as well as a variable allocation algorithm

    this->floors = new Floor*[num_floors+1];
    this->elevators = new Elevator*[num_elevators+1];

    for(int i = 1; i < num_floors+1; i++){
        floors[i] = new Floor(i);
    }

    for(int i = 1; i < num_elevators+1; i++){
        elevators[i] = new Elevator(i, 1, -1, false, false, false);
    }

    if(algorithmnum == 1){
        AA = new Algorithm1();
    }else{
        AA = new Algorithm2();
    }

    this->num_floors = num_floors;
    this->num_elevators = num_elevators;
}

ECS::~ECS(){

//    for(int i = 0; i < (sizeof(this->floors)/sizeof(this->floors[0])); i ++){
//        delete this->floors[i];
//    }

//    for(int i = 0; i < (sizeof(this->elevators)/sizeof(this->elevators[0])); i ++){
//        delete this->elevators[i];
//    }

//    delete [] this->floors;
//    delete [] this->elevators;
//    delete this->AA;
}

int ECS::serveFloor(int floor_number){
    //use AA to allocate the elevator then make that elevator serve its request and come to the requesting floor

    int optimal = this->AA->allocate(this->elevators, floor_number, this->num_elevators);

    qInfo("Elevator %d serving current request", this->elevators[optimal]->getElevatorNumber());
    this->elevators[optimal]->move();
    qInfo("Served existing request");
    this->elevators[optimal]->setDestination(floor_number);
    this->elevators[optimal]->move();

    return optimal;
}

void ECS::serveElevator(int elevator_number){
    //serveElevator() just moves the given elevator to its destination representing the ECS serving
    //a passengers request

    this->getElevator(elevator_number)->move();

}

Elevator* ECS::getElevator(int elevator_number){

    return elevators[elevator_number];
}

void ECS::connect(int elevator_number, Passenger* p){
    //connect() simulates the ECS connecting an elevators sound system to the safety services
    //outcome depends on whether the passenger is concious or not

    qInfo("Connected");
    qInfo("Safety service prompts response");

    if(p->respond()){
        qInfo("Passenger responded");
    }else{
        qInfo("Passenger didn't respond");
        qInfo("911 called");
    }

}

void ECS::Fire(bool fromBuilding, int elevator_number){
    //Fire() simulates the ECS receiving a fire signal either from the building or a specific elevator

    if(fromBuilding){
        qInfo("Fire signal from building");

        for(int i = 1; i < this->num_elevators+1; i++){
            this->elevators[i]->display("Fire Warning: Leave building immediately");
            this->elevators[i]->announce("Fire Warning: Leave building immediately");
        }

        for(int i = 1; i < this->num_elevators+1; i++){
            this->elevators[i]->setDestination(1);
            this->elevators[i]->move();
        }

    }else{
        qInfo("Fire signal from elevator");

        this->elevators[elevator_number]->display("Fire Warning: Leave building immediately");
        this->elevators[elevator_number]->announce("Fire Warning: Leave building immediately");
        this->elevators[elevator_number]->setDestination(1);
        this->elevators[elevator_number]->move();
    }
}

void ECS::powerOut(){
    //powerOut() simulates the ECS receiving a power out signal

    for(int i = 1; i < this->num_elevators+1; i++){
        this->elevators[i]->display("Power Outage");
        this->elevators[i]->announce("Power Outage");
    }

    for(int i = 1; i < this->num_elevators+1; i++){
        this->elevators[i]->setDestination(1);
        this->elevators[i]->move();
        this->elevators[i]->display("Leave building immediately");
        this->elevators[i]->announce("Leave building immediately");
    }

}
