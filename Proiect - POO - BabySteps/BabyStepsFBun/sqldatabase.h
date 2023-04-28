#ifndef SQLDATABASE_H
#define SQLDATABASE_H
#include <QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

class sqldatabase
{
public:
    sqldatabase();
    void connectToDatabase();
};

#endif // SQLDATABASE_H
