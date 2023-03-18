#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initialize connection between the buttons and the slots
    connect(ui->General_Scenario,SIGNAL(clicked()),this, SLOT(General()));
    connect(ui->General_Scenario_2,SIGNAL(clicked()),this, SLOT(General2()));
    connect(ui->Help_Requested,SIGNAL(clicked()),this, SLOT(Help()));
    connect(ui->Door_Obstructed,SIGNAL(clicked()),this, SLOT(Obstacle()));
    connect(ui->Fire,SIGNAL(clicked()),this, SLOT(Fire()));
    connect(ui->Overloaded,SIGNAL(clicked()),this, SLOT(Overload()));
    connect(ui->Power_Out,SIGNAL(clicked()),this, SLOT(PowerOut()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::General(){
    //this slot implements the general scenario outline in the assignment spec with algorithm1

    Passenger* me = new Passenger(1,5,false);
    Passenger* myself = new Passenger(5,1,false);
    Passenger* I = new Passenger(3,5,false);

    Floor* currentMe = new Floor(1);
    Floor* currentMyself = new Floor(5);
    Floor* currentI = new Floor(3);

    ECS* temp = new ECS(5,2,1);

    qInfo("General Scenario Algorithm 1");
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

void MainWindow::General2(){
    //this slot implements the general scenario outline in the assignment spec with algorithm2

    Passenger* me = new Passenger(1,5,false);
    Passenger* myself = new Passenger(5,1,false);
    Passenger* I = new Passenger(3,5,false);

    Floor* currentMe = new Floor(1);
    Floor* currentMyself = new Floor(5);
    Floor* currentI = new Floor(3);

    ECS* temp = new ECS(5,2,2);

    qInfo("General Scenario Algorithm 2");
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

void MainWindow::Help(){
    //this slot implements the help requested scenario where the passenger is unconcious and doesn't respond

    Passenger* me = new Passenger(1,5,true);
    Elevator* current = new Elevator(1,1,5,false,false,false);
    ECS* temp = new ECS(5,2,1);

    qInfo("Help Requested");
    me->pressHelpButton(temp,current);
    qInfo("\n");

    delete me;
    delete current;
    delete temp;
}


void MainWindow::Obstacle(){
    //this slot implements the door obstructed scenario where the obstruction isn't removed

    Elevator* current = new Elevator(1,1,5,true,false,false);

    qInfo("Door Obstructed");
    current->close_door();
    qInfo("\n");

    delete current;
}

void MainWindow::Fire(){
    //this slot implements the fire scenario where the signal is from the building where the safe floor is floor 1

    ECS* temp = new ECS(5,2,1);

    qInfo("Fire Signal Received");
    temp->Fire(true,-1);
    qInfo("\n");

    delete temp;
}

void MainWindow::Overload(){
    //this slot implements the overloaded scenario where the weight isn't reduced

    Elevator* temp = new Elevator(1,1,5,false,true,false);

    qInfo("Elevator Overloaded");
    temp->move();
    qInfo("\n");

    delete temp;
}

void MainWindow::PowerOut(){
    //this slot implements the power out scenario where the safe floor is floor 1

    ECS* temp = new ECS(5,2,1);

    qInfo("Power Out Signal Received");
    temp->powerOut();
    qInfo("\n");

    delete temp;
}


