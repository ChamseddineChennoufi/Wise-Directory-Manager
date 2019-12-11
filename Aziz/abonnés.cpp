#include "abonnes.h"
#include <QDebug>
abonnés::abonnés()
{
id=0;
nom="";
prénom="";
email="";
date_inscription="";
livre_acheter="";

}
abonnés::abonnés(int id,QString nom,QString prénom,QString email,QString date_inscription,QString livre_acheter)
{
  this->id=id;
  this->nom=nom;
  this->prénom=prénom;
  this->email=email;
  this->date_inscription=date_inscription;
  this->livre_acheter=livre_acheter;
}
int abonnés::get_id(){return  id;}
QString abonnés::get_nom(){return nom;}
QString abonnés::get_prénom(){return prénom;}
QString abonnés::get_email(){return email ;}
QString abonnés::get_date_inscription(){return date_inscription ;}
QString abonnés::get_livre_acheter() {return livre_acheter ;}
bool abonnés::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO abonnés (ID,NOM,Prénom,EMAIL,DATE_INSCRIPTION,LIVRE_ACHETER) "
                    "VALUES (:id, :nom, :prénom, :email, :date_inscription, :livre_acheter)");
query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":prénom",prénom);
query.bindValue(":email",email);
query.bindValue(":date_inscription",date_inscription);
query.bindValue(":livre_acheter",livre_acheter);

return    query.exec();
}

QSqlQueryModel * abonnés::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonnés");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date_inscription"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Livre_acheter"));
    return model;
}

bool abonnés::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from abonnés where identifiant = :id ");
query.bindValue(":id", res);
return    query.exec();
}

