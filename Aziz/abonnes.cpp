#include "abonnes.h"
#include <QDebug>
abonnes::abonnes()
{
id=0;
nom="";
prenom="";
email="";
date_inscription="";
livre_acheter="";

}
abonnes::abonnes(int id,QString nom,QString prenom,QString email,QString date_inscription,QString livre_acheter)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->email=email;
  this->date_inscription=date_inscription;
  this->livre_acheter=livre_acheter;
}
int abonnes::get_id(){return  id;}
QString abonnes::get_nom(){return nom;}
QString abonnes::get_prenom(){return prenom;}
QString abonnes::get_email(){return email ;}
QString abonnes::get_date_inscription(){return date_inscription ;}
QString abonnes::get_livre_acheter() {return livre_acheter ;}

bool abonnes::ajouter_2()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO abonnes (ID,NOM,PRENOM,EMAIL,DATE_INSCRIPTION,LIVRE_ACHETER) "
                    "VALUES (:id, :nom, :prenom, :email, :date_inscription, :livre_acheter)");
query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":email",email);
query.bindValue(":date_inscription",date_inscription);
query.bindValue(":livre_acheter",livre_acheter);


return    query.exec();
}

QSqlQueryModel * abonnes::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonnes");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_inscription"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Livre_acheter"));

    return model;
}

bool abonnes::supprimer_2(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from abonnes where id = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool abonnes::modifier_2(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE abonnes SET NOM=:nom,  PRENOM=:prenom,EMAIL=:email,DATE_INSCRIPTION=date_inscription,LIVRE_ACHETER=livre_acheter WHERE ID=:id");
    query.bindValue(":id", res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":date inscription", date_inscription);
    query.bindValue(":livre acheter", livre_acheter);


return    query.exec();
}
 QSqlQueryModel* abonnes:: recherche(const QString & id)
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from abonnes where (ID LIKE'"+id+"%')");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_inscription"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Livre_acheter"));


         return model;
 }
