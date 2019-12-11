#include "programme.h"
#include <QDebug>
Programme::Programme()
{
Prog_ID=0;
Poste="";
Section="";




}
Programme::Programme(int Prog_ID,QString Poste,QString Section)
{
  this->Prog_ID=Prog_ID;
  this->Poste=Poste;
  this->Section=Section;

}
int Programme::get_Prog_ID(){return Prog_ID;}
QString Programme::get_Poste(){return  Poste;}
QString Programme::get_Section(){return Section;}





bool Programme::ajouter()
{
QSqlQuery query;
QString res1= QString::number(Prog_ID);





query.prepare("INSERT INTO Programme (Prog_ID, Poste, Section) "
                    "VALUES (:Prog_ID, :Poste, :Section)");
query.bindValue(":Prog_ID", res1);
query.bindValue(":Poste", Poste);
query.bindValue(":Section", Section);




return    query.exec();
}

QSqlQueryModel * Programme::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Programme");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Prog_ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Poste"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Section"));

    return model;
}

bool Programme::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);

    query.prepare("UPDATE Programme SET Poste=:poste, Section=:section WHERE Prog_ID=:id");
    query.bindValue(":id", res);
    query.bindValue(":poste", Poste);
    query.bindValue(":section", Section);


    return    query.exec();
}

bool Programme::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Programme where Prog_ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

