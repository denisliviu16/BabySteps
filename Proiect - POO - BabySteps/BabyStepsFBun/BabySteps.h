#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BabySteps.h"
#include "signup.h"
#include "qmessagebox.h"
#include "mainwindow2.h"
#include "signupcontinue.h"



class BabySteps : public QMainWindow
{
    Q_OBJECT

public:
    BabySteps(QWidget *parent = nullptr);
    ~BabySteps();
    void setWindowStyle();
    void displayTime();

private slots:
    void showTime();
    void on_login_clicked();

    void on_login_2_clicked();

private:
    Ui::BabyStepsClass ui;
};
