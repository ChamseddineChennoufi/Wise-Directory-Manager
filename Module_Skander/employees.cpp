#include "employees.h"
#include <QDebug>
Employees::Employees()
{
Employee_ID=0;
Nom="";
Prenom="";
CIN=0;


Email="";
Num_Tel=0;
Adresse="";
Grade="";
Fonction="";
Prog_iD=0;
}
Employees::Employees(int Employee_ID,QString Nom,QString Prenom,int CIN,QString Email,int Num_Tel,QString Adresse,QString Grade,QString Fonction,int Prog_iD)
{
  this->Employee_ID=Employee_ID;
  this->Nom=Nom;
  this->Prenom=Prenom;
  this->CIN=CIN;

    this->Email=Email;
    this->Num_Tel=Num_Tel;
    this->Adresse=Adresse;
    this->Grade=Grade;
    this->Fonction=Fonction;
    this->Prog_iD=Prog_iD;
}
int Employees::get_Emp_ID(){return Employee_ID;}
QString Employees::get_Nom(){return  Nom;}
QString Employees::get_Prenom(){return Prenom;}
int Employees::get_CIN(){return CIN;}

QString Employees::get_Email(){return  Email;}
int Employees::get_NumTel(){return  Num_Tel;}
QString Employees::get_Adresse(){return  Adresse;}
QString Employees::get_Grade(){return  Grade;}
QString Employees::get_Fonction(){return  Fonction;}
int Employees::get_ProgID(){return  Prog_iD;}


bool Employees::ajouter()
{
QSqlQuery query;
QString res1= QString::number(Employee_ID);
QString res2= QString::number(CIN);
QString res3= QString::number(Num_Tel);
QString res4= QString::number(Prog_iD);


query.prepare("INSERT INTO Employees (Employee_ID, Nom, Prenom, CIN, Email, Num_Tel, Adresse, Grade, Fonction, Prog_iD) "
                    "VALUES (:Employee_ID, :Nom, :Prenom, :CIN, :Email, :Num_Tel, :Adresse, :Grade, :Fonction, :Prog_iD)");
query.bindValue(":Employee_ID", res1);
query.bindValue(":Nom", Nom);
query.bindValue(":Prenom", Prenom);
query.bindValue(":CIN", res2);

query.bindValue(":Email", Email);
query.bindValue(":Num_Tel", res3);
query.bindValue(":Adresse", Adresse);
query.bindValue(":Grade", Grade);
query.bindValue(":Fonction", Fonction);
query.bindValue(":Prog_iD", res4);

return    query.exec();
}

bool Employees::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    QString res2= QString::number(CIN);
    QString res3= QString::number(Num_Tel);
    QString res4= QString::number(Prog_iD);
    query.prepare("UPDATE Employees SET Nom=:nom,  Prenom=:prenom, CIN=:cin, Email=:email, Num_Tel=:num, Adresse=:adresse, Grade=:grade, Fonction=:fonction, Prog_iD=:progid WHERE Employee_ID=:id");
    query.bindValue(":id", res);
    query.bindValue(":nom", Nom);
    query.bindValue(":prenom", Prenom);
    query.bindValue(":cin", res2);
    query.bindValue(":email", Email);
    query.bindValue(":num", res3);
    query.bindValue(":adresse", Adresse);
    query.bindValue(":grade", Grade);
    query.bindValue(":fonction", Fonction);
    query.bindValue(":progid", res4);

    return    query.exec();
}

QSqlQueryModel * Employees::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Employees");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Employee_ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));

model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num_Tel"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Grade"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Fonction"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("Prog_iD"));
    return model;
}

QSqlQueryModel* Employees:: recherche( const QString  &Employee_ID)
 {
    QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select * from Employees where(Employee_ID LIKE '"+Employee_ID+"')");



     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Employee_ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num_Tel"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("Adresse"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("Grade"));
       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Fonction"));
         model->setHeaderData(9, Qt::Horizontal, QObject::tr("Prog_ID"));
         return model;
 }

bool Employees::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Employees where Employee_ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

