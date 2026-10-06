QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    door.cpp \
    elevator.cpp \
    elevatorcontrolsystem.cpp \
    elevatorpanel.cpp \
    floor.cpp \
    main.cpp \
    mainwindow.cpp \
    passenger.cpp \
    upanddownpanel.cpp

HEADERS += \
    controller.h \
    defs.h \
    door.h \
    elevator.h \
    elevatorcontrolsystem.h \
    elevatorpanel.h \
    floor.h \
    mainwindow.h \
    passenger.h \
    upanddownpanel.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
