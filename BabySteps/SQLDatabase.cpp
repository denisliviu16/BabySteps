#include "SQLDatabase.h"

#include<QtSql/qsqldatabase.h>
#include<QtSql/qsqlquery.h>

//void SQLDatabase::connectToDatabase()
//{
//	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
//	db.setDatabaseName("Driver={SQL Server};Server=DESKTOP-4BTGSLL\\SQLEXPRESS;Database=Northwind;UID=DESKTOP-4BTGSLL\\Denis;PWD = ;Integrated Security=SSPI;");
//	if (db.open())
//	{
//		QSqlQuery query;
//		query.prepare("INSERT INTO Shop (ProductID,ProductName,UnitPrice,UnitStock)"
//			"VALUES (:id,:name,:price,:stock)");
//		query.bindValue(":id", 1005);
//		query.bindValue(":name", "Cereale");
//		query.bindValue(":price", 15);
//		query.bindValue(":stock", 100);
//	}
//}


