#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "defs.h"
#include "controller.h"
#include "passenger.h"
#include <QMainWindow>
#include <QTextBrowser>
#include <QComboBox>
#include <QTimer>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_floorButton1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_p1_radioButton_clicked();
    void on_comboBox_activated(const QString &arg1);
    void timeout();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_p2_radioButton_clicked();
    void on_p3_radioButton_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();

private:
    Ui::MainWindow *ui;
    Controller* controller;// interface for UI to control the elevator system
    QTextBrowser* console;// the text browser to output text

    // passenger text browsers to show some metadata
    QTextBrowser* p1Data;
    QTextBrowser* p2Data;
    QTextBrowser* p3Data;

    // top row of current floor numbers for each elevator
    QTextBrowser* e1Floor;
    QTextBrowser* e2Floor;
    QTextBrowser* e3Floor;

    // displays inside elevator
    QTextBrowser* eFloorDisplay;
    QTextBrowser* eIdDisplay;

    // elevator drop down box display
    QComboBox* elevatorSelection;

    // the cart representations to show a visual of where elevators are at
    QTextBrowser* e1Cart;
    QTextBrowser* e2Cart;
    QTextBrowser* e3Cart;

    // elevator floor buttons
    QPushButton* floorBtn1;
    QPushButton* floorBtn2;
    QPushButton* floorBtn3;
    QPushButton* floorBtn4;
    QPushButton* floorBtn5;
    QPushButton* floorBtn6;
    QPushButton* floorBtn7;

    // timer that calls a slot to update every 10 seconds
    QTimer* timer;

    void updateButtons(const int eId);// updates buttons to be illuminated in the elevator panel
    void resetButtons();// resets illumination of all buttons
    void update();// updates values displayed
};
#endif // MAINWINDOW_H
