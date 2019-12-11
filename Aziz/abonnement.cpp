#include "abonnement.h"
#include <QDebug>
Abonnement::Abonnement()
{
id=0;
type="";
prix=0;
duree=0;


}
Abonnement::Abonnement(int id,QString type,int prix,int duree)
{
  this->id=id;
  this->type=type;
  this->prix=prix;
  this->duree=duree;
}
int Abonnement::get_id(){return  id;}
QString Abonnement::get_type(){return type;}
int Abonnement::get_prix(){return prix;}
int Abonnement::get_duree(){return duree ;}

bool Abonnement::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res1= QString::number(duree);
QString p= QString::number(prix);
query.prepare("INSERT INTO abonnement (ID,TYPE,PRIX,DUREE) "
                    "VALUES (:id, :type, :prix, :duree)");
query.bindValue(":id",res);
query.bindValue(":type",type);
query.bindValue(":prix",p);
query.bindValue(":duree",res1);

return    query.exec();
}

QSqlQueryModel * Abonnement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonnement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
    return model;
}

bool Abonnement::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from abonnement where Id = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Abonnement::modifier(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString pr=QString::number(prix);
    QString dur=QString::number(duree);
    query.prepare("UPDATE abonnement SET TYPE=:type,  PRIX=:prix,DUREE=:duree WHERE ID=:id");
    query.bindValue(":id", res);
    query.bindValue(":type", type);
    query.bindValue(":prix", pr);
    query.bindValue(":duree", dur);
return    query.exec();
}
QSqlQueryModel * Abonnement::calcul_prix()
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("select sum(prix) from abonnement");
   model->setHeaderData(0, Qt::Horizontal,QObject::tr("prix_totale"));
   return model;
}
