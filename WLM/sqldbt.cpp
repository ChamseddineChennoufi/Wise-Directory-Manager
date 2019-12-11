#include "sqldbt.h"

SQLDB::SQLDB()
{

}

bool SQLDB::createsqldb()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ElectricInk");
    db.setUserName("ElectricInk");
    db.setPassword("esprit18");
    if(db.open())
    {
        test=true;
    }
    return test;
}
