#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include<QTimer>
#include<QDateTime>

MainWindow2::MainWindow2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/denis/Desktop/BabyStepsFBun/icon.png");
    setWindowIcon(icon);
    displayTime();
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_NextVenituriWindow_clicked()
{

    QString week1=ui->Saptamana1Salariala->text();
    QString week2=ui->Saptamana2Salariala->text();
    QString week3=ui->Saptamana3Salariala->text();
    QString week4=ui->Saptamana4Salariala->text();
    QString sVenituriStraine=ui->VenituriStraine->text();

    bool isPositive = false;
    bool isNumber1 = false;bool isNumber2 = false;bool isNumber3 = false;bool isNumber4 = false;
    bool isNumberClandestin=false;

    try
    {
        double iWeek1 = week1.toDouble(&isNumber1);
        double iWeek2 = week2.toDouble(&isNumber2);
        double iWeek3 = week3.toDouble(&isNumber3);
        double iWeek4 = week4.toDouble(&isNumber4);

        double VenitClandestin=sVenituriStraine.toDouble(&isNumberClandestin);


        if (isNumber1 && iWeek1 >= 0&&isNumber2 && iWeek2 >= 0&&isNumber3 && iWeek3 >= 0&&isNumber4 && iWeek4 >= 0&&isNumberClandestin&&VenitClandestin>=0) {
            isPositive = true;
            }

    if (isPositive) {
        qDebug() << "Numerele introduse sunt pozitive.";
    }
    else { throw 100;}
    }
    catch(int &a)
    {
        QMessageBox::information(this,"Eroare","Reintroduceti datele sau completati \ntoate campurile!\nIn caseta din dreapta introduceti 0\ndaca nu aveti venituri.");
               this->hide();
               MainWindow2 *w2=new MainWindow2();
               w2->show();
    }

}

void MainWindow2::displayTime()
{
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
}

void MainWindow2::showTime()
{
    QTime oraActuala = QTime::currentTime();
    QString textOraActuala = oraActuala.toString("hh:mm:ss");
    ui->clock->setText(textOraActuala);
}



void MainWindow2::on_verticalScrollBar_valueChanged(int value)
{
    //connect(scrollbar, &QScrollBar::valueChanged, this, &MyClass::handleScrollBarValueChanged); // conectarea semnalului valueChanged()
}

