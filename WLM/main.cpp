#include "login.h"
#include "sqldbt.h"
#include "agents.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SQLDB c;
    bool test=c.createsqldb();
    Login w;
    w.checkdb(test);
    w.show();


    return a.exec();
}
