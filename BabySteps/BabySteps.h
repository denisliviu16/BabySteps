#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BabySteps.h"



class BabySteps : public QMainWindow
{
    Q_OBJECT

public:
    BabySteps(QWidget *parent = nullptr);
    ~BabySteps();
    void setWindowStyle();
private:
    Ui::BabyStepsClass ui;
    void showTime();
};
