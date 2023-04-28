#include "sqldatabase.h"
#include<QtSql/QSqlDatabase>>
#include <QtSql/QSqlQuery>>
#include <QtSql/QSqlError>
sqldatabase::sqldatabase()
{

}

void sqldatabase::connectToDatabase()
{
    QSqlDatabase sqlmdb = QSqlDatabase::addDatabase("QODBC");
    QString dsn = QString("DRIVER={SQL SERVER};Server=DESKTOP-4BTGSLL\\SQLEXPRESS;Database=BabySteps;Trusted_Connection=True;");
    sqlmdb.setDatabaseName(dsn);

    if(!sqlmdb.open())
    {
        qDebug()<<"Failed to connect to database:"<<sqlmdb.lastError().text();
    }

}
