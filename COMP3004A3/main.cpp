#include "mainwindow.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //GeneralScenario();

    //HelpRequested();

    //DoorObstacle();

    //Fire();

    //Overloaded();

    //powerOut();

    qInfo("End");
    return a.exec();
}
