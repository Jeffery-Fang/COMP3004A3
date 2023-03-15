#include "mainwindow.h"
#include "Elevator.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Elevator* temp = new Elevator(0,0,5,false,false,false);
    temp->ring();
    temp->display("Current Floor: 1");
    temp->announce("Arriving soon");
    temp->open_door();
    temp->close_door();
    temp->detectLocation();
    temp->detectObstructed();
    temp->detectOverloaded();

    delete temp;

    qInfo("Hello World");
    return a.exec();
}
