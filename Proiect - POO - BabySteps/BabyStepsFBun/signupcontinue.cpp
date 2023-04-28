#include "signupcontinue.h"
#include "BabySteps.h"
#include "ui_signupcontinue.h"
#include<QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

SignUpContinue::SignUpContinue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUpContinue)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/denis/Desktop/BabyStepsFBun/icon.png");
    setWindowIcon(icon);

    QLinearGradient gradient(0, 0, width(), height() / 2);
    gradient.setColorAt(0, QColor(0, 255, 0));
    gradient.setColorAt(1, QColor(255, 255, 255));

    QPalette pal = palette();
    pal.setBrush(QPalette::Window, QBrush(gradient));
    setAutoFillBackground(true);
    setPalette(pal);
    show();
}

SignUpContinue::~SignUpContinue()
{
    delete ui;
}





void SignUpContinue::on_pushButton_clicked()
{

}


void SignUpContinue::on_Register_2_clicked()
{
    QString Username=ui->username->text();
    QString Password=ui->parola->text();
    QString ConfPassword=ui->ConfirmareParola->text();
    QString FirstName=ui->Nume->text();
    QString Surname=ui->Prenume->text();
    QString Email=ui->email->text();
    QString Phone=ui->Telefon->text();
    QString City=ui->Oras->text();
    QString Country=ui->Tara->text();
    QString Birthday=ui->ZiNastere->text();

    QSqlDatabase sqlmdb = QSqlDatabase::addDatabase("QODBC");
    QString dsn = QString("DRIVER={SQL SERVER};Server=DESKTOP-4BTGSLL\\SQLEXPRESS;Database=BabySteps;Trusted_Connection=True;");
    sqlmdb.setDatabaseName(dsn);

    if(!sqlmdb.open())
    {
        qDebug()<<"Failed to connect to database:"<<sqlmdb.lastError().text();
    }
    else
    {
     QSqlQuery query;
     query.prepare("INSERT INTO Users (Password, FirstName, Surname, Email, PhoneNumber,City, Country,Birthday) "
                   "VALUES (:Password, :FirstName, :Surname, :Email,:Phone,:City, :Country,:Birthday)");
     query.bindValue(":Username", Username);
     query.bindValue(":Password", Password);
     query.bindValue(":FirstName", FirstName);
     query.bindValue(":Surname", Surname);
     query.bindValue(":Email", Email);
     query.bindValue(":Phone", Phone);
     query.bindValue(":City", City);
     query.bindValue(":Country", Country);
     query.bindValue(":Birthday", Birthday);

     if(!query.exec())
     {
         qDebug()<<"Failed to insert data into table:"<<query.lastError().text();
     }
     else
     {
         qDebug()<<"Data inserted successfully!";
     }
    }

    this->hide();
    BabySteps * back = new BabySteps();
    back->show();
}

