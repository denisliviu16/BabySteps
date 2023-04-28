QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BabySteps.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow2.cpp \
    signup.cpp \
    signupcontinue.cpp \
    sqldatabase.cpp

HEADERS += \
    BabySteps.h \
    mainwindow.h \
    mainwindow2.h \
    signup.h \
    signupcontinue.h \
    sqldatabase.h

FORMS += \
    BabySteps.ui \
    mainwindow.ui \
    mainwindow2.ui \
    signupcontinue.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
