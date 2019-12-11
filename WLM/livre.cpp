#include "livre.h"
#include <QDebug>
Livre::Livre()
{
ISBN=0;
Title="";
Author="";
NumRayon=0;
CINA=0;
}

Livre::Livre(long ISBN, QString Title, QString Author, long NumRayon, long CINA)
{
  this->ISBN=ISBN;
  this->Title=Title;
  this->Author=Author;
  this->NumRayon=NumRayon;
  this->CINA=CINA;
}
QString Livre::get_Title(){return Title;}
QString Livre::get_Author(){return Author;}
long Livre::get_ISBN(){return ISBN;}
long Livre::get_CINA(){return CINA;}
long Livre::get_NumRayon(){return NumRayon;}

bool Livre::ajouter()
{
QSqlQuery query;
QString res= QString::number(ISBN),res1=QString::number(NumRayon),res2=QString::number(CINA);
query.prepare("INSERT INTO Livres (ISBN, Title, Author, NumRayon, CINA) VALUES (:ISBN, :Title, :Author, :NumRayon, :CINA)");
query.bindValue(":ISBN", res);
query.bindValue(":Title", Title);
query.bindValue(":Author", Author);
query.bindValue(":NumRayon", res1);
query.bindValue(":CINA", res2);

return    query.exec();
}

QSqlQueryModel * Livre::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Livres");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Auteur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero Rayon"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN Agent"));
    return model;
}

bool Livre::supprimer(long ISBN)
{
QSqlQuery query;
QString res= QString::number(ISBN);
query.prepare("Delete from livres where ISBN = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Livre::modifier(long ISBN)
{
    QSqlQuery query;
    QString res= QString::number(ISBN),res1=QString::number(NumRayon),res2=QString::number(CINA);
    query.prepare("UPDATE livres SET Title=:Title, Author=:Author, NumRayon=:NumRayon, CINA=:CINA WHERE ISBN=:ISBN");
    query.bindValue(":ISBN", res);
    query.bindValue(":Title", Title);
    query.bindValue(":Author", Author);
    query.bindValue(":NumRayon", res1);
    query.bindValue(":CINA", res2);

    return    query.exec();
}

QSqlQueryModel * Livre::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from livres where (ISBN LIKE '"+id+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Auteur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero Rayon"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN Agent"));

    return model;
}

