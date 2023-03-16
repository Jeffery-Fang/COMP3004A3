#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Passenger.h"
#include "Elevator.h"
#include "Floor.h"
#include "ECS.h"
#include "AllocationAlgorithm.h"
#include "Algorithm1.h"
#include "Algorithm2.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void General();
    void General2();
    void Help();
    void Obstacle();
    void Fire();
    void Overload();
    void PowerOut();
};


#endif // MAINWINDOW_H
