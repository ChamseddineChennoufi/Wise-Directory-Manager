#include "Livre.h"
#include <QDebug>
Livre::Livre()
{
id=0;
titre="";
auteur="";
}
Livre::Livre(int id,QString titre,QString auteur)
{
  this->id=id;
  this->titre=titre;
  this->auteur=auteur;
}
QString Livre::get_titre(){return  titre;}
QString Livre::get_auteur(){return auteur;}
int Livre::get_id(){return  id;}

bool Livre::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Livre (ID, TITRE, AUTEUR) "
                    "VALUES (:id, :titre, :auteur)");
query.bindValue(":id", res);
query.bindValue(":titre", titre);
query.bindValue(":auteur", auteur);

return    query.exec();
}

QSqlQueryModel * Livre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Livre");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Auteur"));
    return model;
}

bool Livre::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from livre where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Livre::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE livre SET TITRE=:titre,  AUTEUR=:auteur WHERE ID=:id");
    query.bindValue(":id", res);
    query.bindValue(":titre", titre);
    query.bindValue(":auteur", auteur);

    return    query.exec();
}

QSqlQueryModel * Livre::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from livre where(ID LIKE '"+id+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Auteur"));

        return model;
}

