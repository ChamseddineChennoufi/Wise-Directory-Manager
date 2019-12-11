#include "agents.h"

#include <QDebug>
Employees::Employees()
{
    CINA=0;
    Nom="";
    Prenom="";
    Email="";
    NumTel=0;
    Adresse="";
    Usr="";
    Pwd="";
    lvl=0;
}
Employees::Employees(long CINA,QString Nom,QString Prenom,QString Usr,QString Pwd, double Salary,int lvl, long IDEmp, QString Email,long NumTel,QString Adresse)
{
    this->CINA=CINA;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Usr=Usr;
    this->Pwd=Pwd;
    this->Salary=Salary;
    this->lvl=lvl;
    this->IDEmp=IDEmp;
    this->NumTel=NumTel;
    this->Email=Email;
    this->Adresse=Adresse;

}

long Employees::get_CINA(){return CINA;}
QString Employees::get_Nom(){return Nom;}
QString Employees::get_Prenom(){return Prenom;}
QString Employees::get_Email(){return Email;}
long Employees::get_NumTel(){return NumTel;}
QString Employees::get_Adresse(){return Adresse;}
QString Employees::get_User(){return Usr;}
QString Employees::get_Pwd(){return Pwd;}
int Employees::get_lvl(){return lvl;}


bool Employees::ajouter()
{
QSqlQuery query;
QString res1= QString::number(CINA);
QString res2= QString::number(Salary);
QString res3= QString::number(lvl);
QString res4= QString::number(IDEmp);
QString res5= QString::number(NumTel);

query.prepare("INSERT INTO Agents (CINA, Nom, Prenom, Usr, Pwd, Salary, lvl, IDEmp, Email, NumTel, Adresse) VALUES (:CINA, :Nom, :Prenom, :Usr, :Pwd, :Salary, :lvl, :IDEmp, :Email, :NumTel, :Adresse)");
query.bindValue(":CINA", res1);
query.bindValue(":Nom", Nom);
query.bindValue(":Prenom", Prenom);
query.bindValue(":Usr", Usr);
query.bindValue(":Pwd", Pwd);
query.bindValue(":Salary", res2);
query.bindValue(":lvl", res3);
query.bindValue(":IDEmp", res4);
query.bindValue(":Email", Email);
query.bindValue(":NumTel", res5);
query.bindValue(":Adresse", Adresse);

return    query.exec();
}

bool Employees::modifier(long id)
{
    QSqlQuery query;
    QString res1= QString::number(CINA);
    QString res2= QString::number(Salary);
    QString res3= QString::number(lvl);
    QString res4= QString::number(IDEmp);
    QString res5= QString::number(NumTel);
    QString res6= QString::number(id);

    query.prepare("UPDATE Agents SET CINA=:CINA, Nom=:Nom, Prenom=:Prenom, Usr=:Usr, Pwd=:Pwd, Salary=:Salary, lvl=:lvl, IDEmp=:IDEmp, Email=:Email, NumTel=:NumTel, Adresse=:Adresse WHERE CINA=:id");
    query.bindValue(":CINA", res1);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":Usr", Usr);
    query.bindValue(":Pwd", Pwd);
    query.bindValue(":Salary", res2);
    query.bindValue(":lvl", res3);
    query.bindValue(":IDEmp", res4);
    query.bindValue(":Email", Email);
    query.bindValue(":NumTel", res5);
    query.bindValue(":Adresse", Adresse);
    query.bindValue(":id", res6);
    return    query.exec();
}

QSqlQueryModel * Employees::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Agents");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CINA"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Username"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Pwd"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salary"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("lvl"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("IDEmp"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("NumTel"));
model->setHeaderData(10, Qt::Horizontal, QObject::tr("Adresse"));
    return model;
}

QSqlQueryModel* Employees:: recherche( const QString  &id)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Agents where (CINA LIKE '"+id+"')");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CINA"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Username"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Pwd"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salary"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("lvl"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("IDemp"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Adresse"));
    return model;
 }

bool Employees::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from Agents where CINA = :id ");
query.bindValue(":id", res);
return    query.exec();
}
