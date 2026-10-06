/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *ElevatorFloorStatus;
    QLabel *label_2;
    QTextBrowser *e1_floor;
    QLabel *label_3;
    QTextBrowser *e2_floor;
    QLabel *label_4;
    QTextBrowser *e3_floor;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *ElevatorTesting;
    QLabel *label_7;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QTextBrowser *weight;
    QPushButton *pushButton_17;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *ConsoleDisplay;
    QTextBrowser *console;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *EmergencyTesting;
    QLabel *label_6;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *PassengerControl;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser_8;
    QTextBrowser *textBrowser;
    QGridLayout *gridLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_12;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *p1_text;
    QRadioButton *p1_radioButton;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *p2_text;
    QRadioButton *p2_radioButton;
    QHBoxLayout *horizontalLayout_4;
    QTextBrowser *p3_text;
    QRadioButton *p3_radioButton;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QFrame *line_14;
    QFrame *line_15;
    QFrame *line_16;
    QFrame *line_17;
    QFrame *line_18;
    QFrame *line_19;
    QFrame *line_20;
    QFrame *line_21;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QTextBrowser *textBrowser_11;
    QTextBrowser *textBrowser_12;
    QTextBrowser *textBrowser_13;
    QMenuBar *menubar;
    QMenu *menuCentral_Elevator_Simulation;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget_5 = new QWidget(centralwidget);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(20, 10, 371, 41));
        ElevatorFloorStatus = new QHBoxLayout(horizontalLayoutWidget_5);
        ElevatorFloorStatus->setObjectName(QString::fromUtf8("ElevatorFloorStatus"));
        ElevatorFloorStatus->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        ElevatorFloorStatus->addWidget(label_2);

        e1_floor = new QTextBrowser(horizontalLayoutWidget_5);
        e1_floor->setObjectName(QString::fromUtf8("e1_floor"));
        e1_floor->setStyleSheet(QString::fromUtf8("font: 18pt \"DejaVu Sans\";\n"
"background-color:black;\n"
"color:yellow;\n"
"\n"
""));

        ElevatorFloorStatus->addWidget(e1_floor);

        label_3 = new QLabel(horizontalLayoutWidget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        ElevatorFloorStatus->addWidget(label_3);

        e2_floor = new QTextBrowser(horizontalLayoutWidget_5);
        e2_floor->setObjectName(QString::fromUtf8("e2_floor"));
        e2_floor->setStyleSheet(QString::fromUtf8("font: 18pt \"DejaVu Sans\";\n"
"background-color:black;\n"
"color:yellow;"));

        ElevatorFloorStatus->addWidget(e2_floor);

        label_4 = new QLabel(horizontalLayoutWidget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        ElevatorFloorStatus->addWidget(label_4);

        e3_floor = new QTextBrowser(horizontalLayoutWidget_5);
        e3_floor->setObjectName(QString::fromUtf8("e3_floor"));
        e3_floor->setStyleSheet(QString::fromUtf8("font: 18pt \"DejaVu Sans\";\n"
"background-color:black;\n"
"color:yellow;"));

        ElevatorFloorStatus->addWidget(e3_floor);

        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(230, 430, 161, 111));
        ElevatorTesting = new QVBoxLayout(verticalLayoutWidget_5);
        ElevatorTesting->setSpacing(4);
        ElevatorTesting->setObjectName(QString::fromUtf8("ElevatorTesting"));
        ElevatorTesting->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        ElevatorTesting->addWidget(label_7);

        comboBox = new QComboBox(verticalLayoutWidget_5);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        ElevatorTesting->addWidget(comboBox);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(verticalLayoutWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_8->addWidget(label_5);

        weight = new QTextBrowser(verticalLayoutWidget_5);
        weight->setObjectName(QString::fromUtf8("weight"));

        horizontalLayout_8->addWidget(weight);


        ElevatorTesting->addLayout(horizontalLayout_8);

        pushButton_17 = new QPushButton(verticalLayoutWidget_5);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));

        ElevatorTesting->addWidget(pushButton_17);

        horizontalLayoutWidget_7 = new QWidget(centralwidget);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(410, 440, 371, 101));
        ConsoleDisplay = new QHBoxLayout(horizontalLayoutWidget_7);
        ConsoleDisplay->setObjectName(QString::fromUtf8("ConsoleDisplay"));
        ConsoleDisplay->setContentsMargins(0, 0, 0, 0);
        console = new QTextBrowser(horizontalLayoutWidget_7);
        console->setObjectName(QString::fromUtf8("console"));
        console->setStyleSheet(QString::fromUtf8("font: 8pt \"DejaVu Sans Mono\";"));

        ConsoleDisplay->addWidget(console);

        verticalLayoutWidget_6 = new QWidget(centralwidget);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(20, 430, 191, 111));
        EmergencyTesting = new QVBoxLayout(verticalLayoutWidget_6);
        EmergencyTesting->setObjectName(QString::fromUtf8("EmergencyTesting"));
        EmergencyTesting->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        EmergencyTesting->addWidget(label_6);

        pushButton_18 = new QPushButton(verticalLayoutWidget_6);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

        EmergencyTesting->addWidget(pushButton_18);

        pushButton_19 = new QPushButton(verticalLayoutWidget_6);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));

        EmergencyTesting->addWidget(pushButton_19);

        verticalLayoutWidget_7 = new QWidget(centralwidget);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(410, 10, 371, 411));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        PassengerControl = new QVBoxLayout();
        PassengerControl->setObjectName(QString::fromUtf8("PassengerControl"));
        label = new QLabel(verticalLayoutWidget_7);
        label->setObjectName(QString::fromUtf8("label"));

        PassengerControl->addWidget(label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textBrowser_8 = new QTextBrowser(verticalLayoutWidget_7);
        textBrowser_8->setObjectName(QString::fromUtf8("textBrowser_8"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser_8->sizePolicy().hasHeightForWidth());
        textBrowser_8->setSizePolicy(sizePolicy);
        textBrowser_8->setMaximumSize(QSize(100, 50));
        textBrowser_8->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"color:green;"));

        verticalLayout_2->addWidget(textBrowser_8);

        textBrowser = new QTextBrowser(verticalLayoutWidget_7);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMaximumSize(QSize(100, 50));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"color:green;"));

        verticalLayout_2->addWidget(textBrowser);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_5 = new QPushButton(verticalLayoutWidget_7);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMaximumSize(QSize(50, 16777215));
        pushButton_5->setFlat(false);

        gridLayout->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(verticalLayoutWidget_7);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMaximumSize(QSize(50, 16777215));
        pushButton_6->setFlat(false);

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);

        pushButton_12 = new QPushButton(verticalLayoutWidget_7);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        sizePolicy1.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy1);
        pushButton_12->setMaximumSize(QSize(50, 16777215));
        pushButton_12->setStyleSheet(QString::fromUtf8("color:white; \n"
"background-color: black;"));

        gridLayout->addWidget(pushButton_12, 12, 1, 1, 1);

        pushButton_4 = new QPushButton(verticalLayoutWidget_7);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMaximumSize(QSize(50, 16777215));
        pushButton_4->setFlat(false);

        gridLayout->addWidget(pushButton_4, 4, 1, 1, 1);

        pushButton_2 = new QPushButton(verticalLayoutWidget_7);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMaximumSize(QSize(50, 16777215));
        pushButton_2->setFlat(false);

        gridLayout->addWidget(pushButton_2, 6, 1, 1, 1);

        pushButton_3 = new QPushButton(verticalLayoutWidget_7);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMaximumSize(QSize(50, 16777215));
        pushButton_3->setFlat(false);

        gridLayout->addWidget(pushButton_3, 4, 0, 1, 1);

        pushButton_9 = new QPushButton(verticalLayoutWidget_7);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setMaximumSize(QSize(50, 16777215));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color:yellow;"));

        gridLayout->addWidget(pushButton_9, 13, 0, 1, 1);

        pushButton_10 = new QPushButton(verticalLayoutWidget_7);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);
        pushButton_10->setMaximumSize(QSize(50, 16777215));
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color:red"));

        gridLayout->addWidget(pushButton_10, 13, 1, 1, 1);

        pushButton_11 = new QPushButton(verticalLayoutWidget_7);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);
        pushButton_11->setMaximumSize(QSize(50, 16777215));
        pushButton_11->setStyleSheet(QString::fromUtf8("color:white; \n"
"background-color: black;"));

        gridLayout->addWidget(pushButton_11, 12, 0, 1, 1);

        pushButton = new QPushButton(verticalLayoutWidget_7);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMaximumSize(QSize(50, 16777215));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton->setFlat(false);

        gridLayout->addWidget(pushButton, 6, 0, 1, 1);

        pushButton_7 = new QPushButton(verticalLayoutWidget_7);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setMaximumSize(QSize(50, 16777215));
        pushButton_7->setFlat(false);

        gridLayout->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(verticalLayoutWidget_7);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setMaximumSize(QSize(50, 16777215));
        pushButton_8->setFlat(false);

        gridLayout->addWidget(pushButton_8, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        p1_text = new QTextBrowser(verticalLayoutWidget_7);
        p1_text->setObjectName(QString::fromUtf8("p1_text"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(p1_text->sizePolicy().hasHeightForWidth());
        p1_text->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(p1_text);

        p1_radioButton = new QRadioButton(verticalLayoutWidget_7);
        p1_radioButton->setObjectName(QString::fromUtf8("p1_radioButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(p1_radioButton->sizePolicy().hasHeightForWidth());
        p1_radioButton->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(p1_radioButton);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        p2_text = new QTextBrowser(verticalLayoutWidget_7);
        p2_text->setObjectName(QString::fromUtf8("p2_text"));

        horizontalLayout_3->addWidget(p2_text);

        p2_radioButton = new QRadioButton(verticalLayoutWidget_7);
        p2_radioButton->setObjectName(QString::fromUtf8("p2_radioButton"));
        sizePolicy3.setHeightForWidth(p2_radioButton->sizePolicy().hasHeightForWidth());
        p2_radioButton->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(p2_radioButton);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        p3_text = new QTextBrowser(verticalLayoutWidget_7);
        p3_text->setObjectName(QString::fromUtf8("p3_text"));

        horizontalLayout_4->addWidget(p3_text);

        p3_radioButton = new QRadioButton(verticalLayoutWidget_7);
        p3_radioButton->setObjectName(QString::fromUtf8("p3_radioButton"));
        sizePolicy3.setHeightForWidth(p3_radioButton->sizePolicy().hasHeightForWidth());
        p3_radioButton->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(p3_radioButton);


        verticalLayout_4->addLayout(horizontalLayout_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_13 = new QPushButton(verticalLayoutWidget_7);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        gridLayout_2->addWidget(pushButton_13, 0, 0, 1, 1);

        pushButton_14 = new QPushButton(verticalLayoutWidget_7);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        gridLayout_2->addWidget(pushButton_14, 0, 1, 1, 1);

        pushButton_15 = new QPushButton(verticalLayoutWidget_7);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        gridLayout_2->addWidget(pushButton_15, 1, 0, 1, 1);

        pushButton_16 = new QPushButton(verticalLayoutWidget_7);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));

        gridLayout_2->addWidget(pushButton_16, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);


        horizontalLayout_5->addLayout(verticalLayout_4);


        PassengerControl->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(PassengerControl);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 370, 391, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 0, 20, 551));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 540, 391, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(210, 420, 20, 131));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(390, 0, 20, 551));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(10, -10, 781, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(10, 50, 391, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(400, 420, 391, 20));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(400, 540, 391, 20));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(centralwidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(780, 0, 20, 551));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);
        line_11 = new QFrame(centralwidget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(70, 60, 20, 361));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);
        line_12 = new QFrame(centralwidget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(180, 60, 20, 361));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);
        line_13 = new QFrame(centralwidget);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setGeometry(QRect(10, 330, 391, 20));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);
        line_14 = new QFrame(centralwidget);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setGeometry(QRect(10, 290, 391, 20));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);
        line_15 = new QFrame(centralwidget);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setGeometry(QRect(10, 250, 391, 20));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);
        line_16 = new QFrame(centralwidget);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setGeometry(QRect(10, 210, 391, 20));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);
        line_17 = new QFrame(centralwidget);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setGeometry(QRect(10, 170, 391, 20));
        line_17->setFrameShape(QFrame::HLine);
        line_17->setFrameShadow(QFrame::Sunken);
        line_18 = new QFrame(centralwidget);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setGeometry(QRect(10, 130, 391, 20));
        line_18->setFrameShape(QFrame::HLine);
        line_18->setFrameShadow(QFrame::Sunken);
        line_19 = new QFrame(centralwidget);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setGeometry(QRect(10, 90, 391, 20));
        line_19->setFrameShape(QFrame::HLine);
        line_19->setFrameShadow(QFrame::Sunken);
        line_20 = new QFrame(centralwidget);
        line_20->setObjectName(QString::fromUtf8("line_20"));
        line_20->setGeometry(QRect(10, 410, 391, 20));
        line_20->setFrameShape(QFrame::HLine);
        line_20->setFrameShadow(QFrame::Sunken);
        line_21 = new QFrame(centralwidget);
        line_21->setObjectName(QString::fromUtf8("line_21"));
        line_21->setGeometry(QRect(290, 60, 20, 361));
        line_21->setFrameShape(QFrame::VLine);
        line_21->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 70, 62, 17));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 110, 62, 17));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 150, 62, 17));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 190, 62, 17));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 230, 62, 17));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 270, 62, 17));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 310, 62, 17));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 350, 62, 17));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 390, 62, 17));
        textBrowser_11 = new QTextBrowser(centralwidget);
        textBrowser_11->setObjectName(QString::fromUtf8("textBrowser_11"));
        textBrowser_11->setGeometry(QRect(90, 380, 91, 31));
        textBrowser_12 = new QTextBrowser(centralwidget);
        textBrowser_12->setObjectName(QString::fromUtf8("textBrowser_12"));
        textBrowser_12->setGeometry(QRect(200, 380, 91, 31));
        textBrowser_13 = new QTextBrowser(centralwidget);
        textBrowser_13->setObjectName(QString::fromUtf8("textBrowser_13"));
        textBrowser_13->setGeometry(QRect(310, 380, 91, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuCentral_Elevator_Simulation = new QMenu(menubar);
        menuCentral_Elevator_Simulation->setObjectName(QString::fromUtf8("menuCentral_Elevator_Simulation"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuCentral_Elevator_Simulation->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "E1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "E2", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "E3", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Elevator Testing", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Weight", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Block Door", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Emergency Testing", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Fire", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Power Out", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Passenger Control", nullptr));
        textBrowser_8->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Floor 1</p></body></html>", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Elevator 1</p></body></html>", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", ">| |<", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Fire", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "|< >|", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        p1_radioButton->setText(QCoreApplication::translate("MainWindow", "Passenger 1", nullptr));
        p2_radioButton->setText(QCoreApplication::translate("MainWindow", "Passenger 2", nullptr));
        p3_radioButton->setText(QCoreApplication::translate("MainWindow", "Passenger 3", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Up", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Floor 9", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Floor 8", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Floor 7", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Floor 6", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Floor 5", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Floor 4", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Floor 3", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Floor 2", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Floor 1", nullptr));
        textBrowser_11->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Elevator 1</p></body></html>", nullptr));
        textBrowser_12->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Elevator 2</p></body></html>", nullptr));
        textBrowser_13->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Elevator 3</p></body></html>", nullptr));
        menuCentral_Elevator_Simulation->setTitle(QCoreApplication::translate("MainWindow", "Central Elevator Simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
