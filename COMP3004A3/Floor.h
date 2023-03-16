#ifndef FLOOR_H
#define FLOOR_H


#include <iostream>
#include <QtGlobal>

class ECS;

using namespace std;

class Floor{
public:
    Floor();
    Floor(int floor_number);
    //Floor class represents the floors the ECS is meant to serve and really only needs a floor number

    int makeRequest(ECS* owner);
    //makeRequest() will cause the ECS to allocate an elevator to this floor
    //first it will print "button lit up" to indicate the floor button is lit
    //then it will cause the input ECS to allocate an elevator(set some elevator current floor to this one
    //and return that elevator number) and finally it will unlight the button

private:
    int floor_number;

};
#endif // FLOOR_H
