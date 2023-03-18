#ifndef SCENARIOS_H
#define SCENARIOS_H
#include "ECS.h"
#include "Passenger.h"

using namespace std;

void GeneralScenario(){
    Passenger* me = new Passenger(1,5,false);
    Passenger* myself = new Passenger(5,1,false);
    Passenger* I = new Passenger(3,5,false);

    Floor* currentMe = new Floor(1);
    Floor* currentMyself = new Floor(5);
    Floor* currentI = new Floor(3);

    ECS* temp = new ECS(5,2,2);

    qInfo("Passenger 1");
    me->pressElevatorButton(temp->getElevator(me->pressFloorButton(currentMe,temp)),temp);
    qInfo("\n");
    qInfo("Passenger 2");
    myself->pressElevatorButton(temp->getElevator(myself->pressFloorButton(currentMyself,temp)),temp);
    qInfo("\n");
    qInfo("Passenger 3");
    I->pressElevatorButton(temp->getElevator(I->pressFloorButton(currentI,temp)),temp);
    qInfo("\n");

    delete me;
    delete myself;
    delete I;
    delete currentMe;
    delete currentMyself;
    delete currentI;
    delete temp;
}

void HelpRequested(){
    Passenger* me = new Passenger(1,5,true);
    Elevator* current = new Elevator(1,1,5,false,false,false);
    ECS* temp = new ECS(5,2,2);

    me->pressHelpButton(temp,current);

    delete me;
    delete current;
    delete temp;
}

void DoorObstacle(){

    Elevator* current = new Elevator(1,1,5,true,false,false);

    current->close_door();

    delete current;
}

void Fire(){
    ECS* temp = new ECS(5,2,2);

    temp->Fire(true,-1);

    delete temp;
}

void Overloaded(){
    Elevator* temp = new Elevator(1,1,5,false,true,false);

    temp->move();

    delete temp;
}

void powerOut(){
    ECS* temp = new ECS(5,2,2);

    temp->powerOut();

    delete temp;
}

#endif // SCENARIOS_H
