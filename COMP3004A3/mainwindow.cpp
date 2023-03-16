#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    Passenger* me = new Passenger(1,5,false);
    Passenger* myself = new Passenger(5,1,false);
    Passenger* I = new Passenger(3,5,false);

    Floor* currentMe = new Floor(1);
    Floor* currentMyself = new Floor(5);
    Floor* currentI = new Floor(3);

    ECS* temp = new ECS(5,2,1);

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

void MainWindow::Help(){
    Passenger* me = new Passenger(1,5,true);
    Elevator* current = new Elevator(1,1,5,false,false,false);
    ECS* temp = new ECS(5,2,1);

    current->helpRequested(temp,me);
    qInfo("\n");

    delete me;
    delete current;
    delete temp;
}


void MainWindow::Obstacle(){
    Elevator* current = new Elevator(1,1,5,true,false,false);

    current->close_door();
    qInfo("\n");

    delete current;
}

void MainWindow::Fire(){
    ECS* temp = new ECS(5,2,1);

    temp->Fire(true,-1);
    qInfo("\n");

    delete temp;
}

void MainWindow::Overload(){
    Elevator* temp = new Elevator(1,1,5,false,true,false);

    temp->move();
    qInfo("\n");

    delete temp;
}

void MainWindow::PowerOut(){
    ECS* temp = new ECS(5,2,1);

    temp->powerOut();
    qInfo("\n");

    delete temp;
}


