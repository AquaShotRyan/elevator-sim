#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "defs.h"

#define ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION "error: no passenger selected, not in elevator, or can't exit elevator"
#define ERR_NOT_IN_FLOOR_OR_NO_SELECTION "error: no passenger selected, not in a floor, or no enterable elevators"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , controller(new Controller())
    , timer(new QTimer(this))
{
    ui->setupUi(this);

    console = findChild<QTextBrowser*>("console");

    p1Data = findChild<QTextBrowser*>("p1_text");
    p2Data = findChild<QTextBrowser*>("p2_text");
    p3Data = findChild<QTextBrowser*>("p3_text");

    e1Floor = findChild<QTextBrowser*>("e1_floor");
    e2Floor = findChild<QTextBrowser*>("e2_floor");
    e3Floor = findChild<QTextBrowser*>("e3_floor");

    eFloorDisplay = findChild<QTextBrowser*>("textBrowser_8");
    eIdDisplay = findChild<QTextBrowser*>("textBrowser");

    elevatorSelection = findChild<QComboBox*>("comboBox");
    elevatorSelection->addItems({"Elevator 1", "Elevator 2", "Elevator 3"});

    e1Cart = findChild<QTextBrowser*>("textBrowser_11");
    e2Cart = findChild<QTextBrowser*>("textBrowser_12");
    e3Cart = findChild<QTextBrowser*>("textBrowser_13");

    e1Cart->move(e1Cart->x(), 380-(40*(controller->getElevatorFloorNum(1) - 1)));
    e2Cart->move(e2Cart->x(), 380-(40*(controller->getElevatorFloorNum(2) - 1)));
    e3Cart->move(e3Cart->x(), 380-(40*(controller->getElevatorFloorNum(3) - 1)));

    floorBtn1 = findChild<QPushButton*>("pushButton");
    floorBtn2 = findChild<QPushButton*>("pushButton_2");
    floorBtn3 = findChild<QPushButton*>("pushButton_3");
    floorBtn4 = findChild<QPushButton*>("pushButton_4");
    floorBtn5 = findChild<QPushButton*>("pushButton_5");
    floorBtn6 = findChild<QPushButton*>("pushButton_6");
    floorBtn7 = findChild<QPushButton*>("pushButton_7");

    controller->selectElevator(1);

    //create a timer that calls timeout() slot every 10 seconds (for simulating opening doors for 10 seconds)
    connect(timer, &QTimer::timeout, this, &MainWindow::timeout);
    timer->start(10000);

    update();
}

void MainWindow::timeout()
{
    controller->moveAllElevators();
    update();
    console->append("10 SECONDS PASSED");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete controller;
}

void MainWindow::update()
{
    // display passenger data
    p1Data->setText(controller->getPassengerInfo("steve"));
    p2Data->setText(controller->getPassengerInfo("robin"));
    p3Data->setText(controller->getPassengerInfo("ryan"));

    // display elevator floor trackers
    e1Floor->setText(QString::number(controller->getElevatorFloorNum(1)));
    e2Floor->setText(QString::number(controller->getElevatorFloorNum(2)));
    e3Floor->setText(QString::number(controller->getElevatorFloorNum(3)));

    // display elevator that passenger is in
    eFloorDisplay->setText("Floor: "+QString::number(controller->getCurElevatorFloorNum()));
    eIdDisplay->setText("Elevator: "+QString::number(controller->getCurElevatorId()));

    // display weight
    findChild<QTextBrowser*>("weight")->setText(QString::number(controller->getWeight()));

    // move the carts
    e1Cart->move(e1Cart->x(), 380-(40*(controller->getElevatorFloorNum(1) - 1)));
    e2Cart->move(e2Cart->x(), 380-(40*(controller->getElevatorFloorNum(2) - 1)));
    e3Cart->move(e3Cart->x(), 380-(40*(controller->getElevatorFloorNum(3) - 1)));

    // illuminate any active floor buttons
    resetButtons();
    if (controller->getSelectedPassenger() != nullptr){
        Elevator* e = controller->getSelectedPassenger()->getElevator();
        if (e != nullptr)
            updateButtons(e->getId());
    }
}

void MainWindow::updateButtons(const int eId)
{
    QVector<int> buttons = controller->getRequestsList(eId);
    // loop through buttons and illuminate them
    for (int i=0; i<buttons.size(); ++i){
        int b = buttons.at(i);
        if (b == 1)
            floorBtn1->setStyleSheet("background-color:aqua;");
        else if (b == 2)
            floorBtn2->setStyleSheet("background-color:aqua;");
        else if (b == 3)
            floorBtn3->setStyleSheet("background-color:aqua;");
        else if (b == 4)
            floorBtn4->setStyleSheet("background-color:aqua;");
        else if (b == 5)
            floorBtn5->setStyleSheet("background-color:aqua;");
        else if (b == 6)
            floorBtn6->setStyleSheet("background-color:aqua;");
        else if (b == 7)
            floorBtn7->setStyleSheet("background-color:aqua;");
    }
}

void MainWindow::resetButtons()
{
    floorBtn1->setStyleSheet("");
    floorBtn2->setStyleSheet("");
    floorBtn3->setStyleSheet("");
    floorBtn4->setStyleSheet("");
    floorBtn5->setStyleSheet("");
    floorBtn6->setStyleSheet("");
    floorBtn7->setStyleSheet("");
}

/* ============Elevator Panel============ */
void MainWindow::on_pushButton_clicked()// floor button 1
{
    if (controller->requestFloor(1) == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else{
        console->append("floor button 1");
        update();
    }
}

void MainWindow::on_floorButton1_clicked()// moc file bugged and this needs to be here
{
    return;
}

void MainWindow::on_pushButton_2_clicked()// floor button 2
{
    if (controller->requestFloor(2) == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else{
        console->append("floor button 2");
        update();
    }
}


void MainWindow::on_pushButton_3_clicked()// floor button 3
{
    if (controller->requestFloor(3) == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else{
        console->append("floor button 3");
        update();
    }
}

void MainWindow::on_pushButton_4_clicked()// floor button 4
{
    if (controller->requestFloor(4) == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else{
        console->append("floor button 4");
        update();
    }
}


void MainWindow::on_pushButton_5_clicked()// floor button 5
{
    if (controller->requestFloor(5) == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else{
        console->append("floor button 5");
        update();
    }
}

void MainWindow::on_pushButton_6_clicked()// floor button 6
{
    if (controller->requestFloor(6) == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else{
        console->append("floor button 6");
        update();
    }
}

void MainWindow::on_pushButton_7_clicked()// floor button 7
{
    if (controller->requestFloor(7) == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else{
        console->append("floor button 7");
        update();
    }
}

void MainWindow::on_pushButton_8_clicked()// floor button 8
{
    console->append("floor button 8 (does nothing, only max 7 floors for this GUI)");
}

void MainWindow::on_pushButton_11_clicked()// open door button
{
    if (controller->openDoor() == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else
        console->append("open door button");
}

void MainWindow::on_pushButton_12_clicked()// close door button
{
    if (controller->closeDoor() == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else
        console->append("close door button");
}

void MainWindow::on_pushButton_9_clicked()// help button
{
    if (controller->clickHelp() == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else
        console->append("help button");
}

void MainWindow::on_pushButton_10_clicked()// fire button
{
    if (controller->clickFire() == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else
        console->append("fire button");
}

/* ============Other Passenger Control============ */
void MainWindow::on_p1_radioButton_clicked()// passenger 1 radio button
{
    if (controller->selectPassenger("steve") == false)// hard coded, change later
        console->append("failed to select passenger");
    else{
        update();
        console->append(controller->getSelectedPassenger()->getName() + " selected");
    }
}

void MainWindow::on_p2_radioButton_clicked()// passenger 2 radio button
{
    if (controller->selectPassenger("robin") == false)
        console->append("failed to select passenger");
    else{
        update();
        console->append(controller->getSelectedPassenger()->getName() + " selected");
    }
}

void MainWindow::on_p3_radioButton_clicked()// passenger 3 radio button
{
    if (controller->selectPassenger("ryan") == false)
        console->append("failed to select passenger");
    else{
        update();
        console->append(controller->getSelectedPassenger()->getName() + " selected");
    }
}

void MainWindow::on_pushButton_13_clicked()// request up button
{
    if (controller->requestUp() == false) console->append(ERR_NOT_IN_FLOOR_OR_NO_SELECTION);
    else
        console->append("requested up");
}

void MainWindow::on_pushButton_14_clicked()// request down button
{
    if (controller->requestDown() == false) console->append(ERR_NOT_IN_FLOOR_OR_NO_SELECTION);
    else
        console->append("requested down");
}

void MainWindow::on_pushButton_15_clicked()// enter elevator
{
    if (controller->enterElevator() == false) console->append(ERR_NOT_IN_FLOOR_OR_NO_SELECTION);
    else{
        update();
        console->append("entered elevator");
    }
}

void MainWindow::on_pushButton_16_clicked()// exit elevator
{
    if (controller->exitElevator() == false) console->append(ERR_NOT_IN_ELEVATOR_OR_NO_SELECTION);
    else{
        update();
        console->append("exited elevator");
    }
}

/* ============Admin============ */
void MainWindow::on_comboBox_activated(const QString &arg1)// elevator drop down box
{
    const int id = arg1.split(" ")[1].toInt();
    controller->selectElevator(id);
    update();
    console->append("changing selected elevator to "+QString::number(id));
}

void MainWindow::on_pushButton_17_clicked()// block door
{
    if (controller->blockDoor() == false) console->append("door already blocked");
    else
        console->append("blocked");
}

void MainWindow::on_pushButton_18_clicked()// fire signal button
{
    controller->signalFire();
    console->append("fire alarm sounded");
}

void MainWindow::on_pushButton_19_clicked()// power out signal button
{
    controller->signalPowerOut();
    console->append("building has lost power");
}

