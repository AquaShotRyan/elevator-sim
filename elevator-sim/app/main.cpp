#include "mainwindow.h"

#include "defs.h"

#include "elevatorcontrolsystem.h"
#include "elevator.h"
#include "floor.h"
#include "passenger.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
